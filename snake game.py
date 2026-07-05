import pygame
import random
import sys

pygame.init()

# Window
WIDTH = 800
HEIGHT = 600
CELL = 20

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Red Snake")

clock = pygame.time.Clock()

font = pygame.font.SysFont("Arial", 28)
bigFont = pygame.font.SysFont("Arial", 60)

# Colors
BLACK = (15,15,15)
GRID1 = (22,22,22)
GRID2 = (30,30,30)

HEAD = (255,40,40)
BODY = (180,0,0)

APPLE = (255,70,70)
LEAF = (0,220,0)

WHITE = (255,255,255)
BLACK2 = (0,0,0)

FPS = 6


def reset():

    global snake,direction,food,score,gameOver

    snake=[(200,200),(180,200),(160,200)]

    direction=(CELL,0)

    score=0

    gameOver=False

    spawnFood()


def spawnFood():

    global food

    while True:

        x=random.randrange(0,WIDTH,CELL)
        y=random.randrange(0,HEIGHT,CELL)

        if (x,y) not in snake:

            food=(x,y)

            break


reset()

while True:

    # Events
    for event in pygame.event.get():

        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type==pygame.KEYDOWN:

            if event.key==pygame.K_ESCAPE:
                pygame.quit()
                sys.exit()

            if gameOver:

                if event.key==pygame.K_r:
                    reset()

            else:

                if event.key==pygame.K_UP and direction!=(0,CELL):
                    direction=(0,-CELL)

                elif event.key==pygame.K_DOWN and direction!=(0,-CELL):
                    direction=(0,CELL)

                elif event.key==pygame.K_LEFT and direction!=(CELL,0):
                    direction=(-CELL,0)

                elif event.key==pygame.K_RIGHT and direction!=(-CELL,0):
                    direction=(CELL,0)

    if not gameOver:

        head=(snake[0][0]+direction[0],
              snake[0][1]+direction[1])

        # Wall collision
        if head[0]<0 or head[0]>=WIDTH or head[1]<0 or head[1]>=HEIGHT:
            gameOver=True

        # Self collision
        elif head in snake:
            gameOver=True

        else:

            snake.insert(0,head)

            if head==food:

                score+=1

                spawnFood()

            else:

                snake.pop()

    # Background
    for y in range(0,HEIGHT,CELL):

        for x in range(0,WIDTH,CELL):

            color=GRID1 if ((x//CELL+y//CELL)%2==0) else GRID2

            pygame.draw.rect(screen,color,(x,y,CELL,CELL))

    # Apple
    pygame.draw.circle(screen,APPLE,
                      (food[0]+CELL//2,food[1]+CELL//2),
                      CELL//2-2)

    pygame.draw.line(screen,LEAF,
                     (food[0]+10,food[1]+2),
                     (food[0]+14,food[1]-3),3)

    # Snake Body
    for part in snake[1:]:

        pygame.draw.circle(screen,
                           BODY,
                           (part[0]+CELL//2,
                            part[1]+CELL//2),
                           CELL//2)

    # Snake Head
    hx,hy=snake[0]

    pygame.draw.circle(screen,
                       HEAD,
                       (hx+CELL//2,
                        hy+CELL//2),
                       CELL//2)

    # Eyes
    if direction==(CELL,0):

        pygame.draw.circle(screen,WHITE,(hx+14,hy+6),3)
        pygame.draw.circle(screen,WHITE,(hx+14,hy+14),3)

        pygame.draw.circle(screen,BLACK2,(hx+15,hy+6),1)
        pygame.draw.circle(screen,BLACK2,(hx+15,hy+14),1)

    elif direction==(-CELL,0):

        pygame.draw.circle(screen,WHITE,(hx+6,hy+6),3)
        pygame.draw.circle(screen,WHITE,(hx+6,hy+14),3)

        pygame.draw.circle(screen,BLACK2,(hx+5,hy+6),1)
        pygame.draw.circle(screen,BLACK2,(hx+5,hy+14),1)

    elif direction==(0,-CELL):

        pygame.draw.circle(screen,WHITE,(hx+6,hy+6),3)
        pygame.draw.circle(screen,WHITE,(hx+14,hy+6),3)

        pygame.draw.circle(screen,BLACK2,(hx+6,hy+5),1)
        pygame.draw.circle(screen,BLACK2,(hx+14,hy+5),1)

    elif direction==(0,CELL):

        pygame.draw.circle(screen,WHITE,(hx+6,hy+14),3)
        pygame.draw.circle(screen,WHITE,(hx+14,hy+14),3)

        pygame.draw.circle(screen,BLACK2,(hx+6,hy+15),1)
        pygame.draw.circle(screen,BLACK2,(hx+14,hy+15),1)

    # Score
    text=font.render("Score : "+str(score),True,WHITE)
    screen.blit(text,(10,10))

    # Game Over
    if gameOver:

        over=bigFont.render("GAME OVER",True,(255,50,50))
        restart=font.render("Press R to Restart",True,WHITE)

        screen.blit(over,(WIDTH//2-over.get_width()//2,
                          HEIGHT//2-40))

        screen.blit(restart,(WIDTH//2-restart.get_width()//2,
                             HEIGHT//2+30))

    pygame.display.flip()

    clock.tick(FPS)