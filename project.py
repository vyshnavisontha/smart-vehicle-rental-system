questions = [
    {
        "question": "What is the result of multiplying a 2x3 matrix with a 3x2 matrix?",
        "options": ["2x2", "3x3", "2x3", "3x2"],
        "answer": 0
    },
    {
        "question": "Which operation is not defined for matrices?",
        "options": ["Addition", "Subtraction", "Division", "Multiplication"],
        "answer": 2
    },
    {
        "question": "What is the identity matrix of size 2?",
        "options": ["[[1,0],[0,1]]", "[[0,1],[1,0]]", "[[1,1],[1,1]]", "[[0,0],[0,0]]"],
        "answer": 0
    },
    {
        "question": "Transpose of [[1,2],[3,4]] is?",
        "options": ["[[1,3],[2,4]]", "[[1,2],[3,4]]", "[[4,3],[2,1]]", "[[2,1],[4,3]]"],
        "answer": 0
    },
    {
        "question": "Determinant of [[1,2],[3,4]] is?",
        "options": ["-2", "2", "10", "0"],
        "answer": 0
    },
    {
        "question": "Which matrix is singular?",
        "options": ["[[1,2],[3,4]]", "[[2,4],[1,2]]", "[[0,1],[1,0]]", "[[5,6],[7,8]]"],
        "answer": 1
    },
    {
        "question": "Can you add a 2x2 matrix to a 2x3 matrix?",
        "options": ["Yes", "No", "Only if elements are same", "Only if determinant is zero"],
        "answer": 1
    },
    {
        "question": "Inverse of identity matrix is?",
        "options": ["Zero matrix", "Same identity matrix", "Negative identity", "Not defined"],
        "answer": 1
    },
    {
        "question": "Trace of [[1,2],[3,4]] is?",
        "options": ["5", "4", "3", "10"],
        "answer": 0
    },
    {
        "question": "Which of these is a diagonal matrix?",
        "options": ["[[1,0],[0,1]]", "[[1,2],[3,4]]", "[[0,0],[0,0]]", "[[1,1],[1,1]]"],
        "answer": 0
    }
]

score = 0
attempts = 0

def ask_question(index, q):
    global score, attempts
    print(f"\nQuestion {index + 1}: {q['question']}")
    for i, option in enumerate(q['options']):
        print(f"  {i + 1}. {option}")
    try:
        choice = int(input("Your answer (1-4): ")) - 1
        if choice == q['answer']:
            print("✅ Correct!")
            score += 1
        else:
            print(f"❌ Wrong! Correct answer: {q['options'][q['answer']]}")
            score -= 1
        attempts += 1
    except ValueError:
        print("⚠ Invalid input. Skipping question.")
        attempts += 1

def show_result():
    print("\n🎉 Quiz Completed!")
    print(f"Total Attempts: {attempts}")
    print(f"Final Score: {score}")

def main():
    print("🧠 Welcome to the Matrix Operations Quiz!")
    for i, q in enumerate(questions):
        ask_question(i, q)