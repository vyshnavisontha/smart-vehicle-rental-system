#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


// =====================================================
// BASE CLASS - VEHICLE
// =====================================================

class Vehicle
{
protected:
    int vehicleNo;
    char vehicleName[30];
    char vehicleType[20];
    float rentPerDay;

public:

    // Constructor
    Vehicle()
    {
        vehicleNo = 0;
        strcpy(vehicleName, "Unknown");
        strcpy(vehicleType, "Unknown");
        rentPerDay = 0;
    }

    // Set vehicle details
    void setVehicle(int no, const char name[], const char type[], float rent)
    {
        vehicleNo = no;
        strcpy(vehicleName, name);
        strcpy(vehicleType, type);
        rentPerDay = rent;
    }

    // Virtual function
    virtual void displayVehicle()
    {
        cout << "\n--------------------------------";
        cout << "\nVehicle Number : " << vehicleNo;
        cout << "\nVehicle Name   : " << vehicleName;
        cout << "\nVehicle Type   : " << vehicleType;
        cout << "\nRent Per Day   : Rs." << rentPerDay;
        cout << "\n--------------------------------";
    }

    // Calculate rent
    virtual float calculateRent(int days)
    {
        return rentPerDay * days;
    }

    int getVehicleNo()
    {
        return vehicleNo;
    }

    char* getVehicleName()
    {
        return vehicleName;
    }

    char* getVehicleType()
    {
        return vehicleType;
    }

    float getRent()
    {
        return rentPerDay;
    }

    // Save vehicle details to file
    void saveToFile(ofstream &fout)
    {
        fout << "Vehicle Number  : " << vehicleNo << "\n";
        fout << "Vehicle Name    : " << vehicleName << "\n";
        fout << "Vehicle Type    : " << vehicleType << "\n";
        fout << "Rent Per Day    : Rs." << rentPerDay << "\n";
    }

    virtual ~Vehicle()
    {
    }
};


// =====================================================
// DERIVED CLASS - CAR
// =====================================================

class Car : public Vehicle
{
public:

    Car()
    {
        setVehicle(101, "HondaCity", "Car", 1500);
    }

    void displayVehicle()
    {
        cout << "\n--------------------------------";
        cout << "\nVehicle Number : " << vehicleNo;
        cout << "\nVehicle Name   : " << vehicleName;
        cout << "\nVehicle Type   : " << vehicleType;
        cout << "\nRent Per Day   : Rs." << rentPerDay;
        cout << "\n--------------------------------";
    }
};


// =====================================================
// DERIVED CLASS - BIKE
// =====================================================

class Bike : public Vehicle
{
public:

    Bike()
    {
        setVehicle(102, "Activa", "Bike", 600);
    }

    void displayVehicle()
    {
        cout << "\n--------------------------------";
        cout << "\nVehicle Number : " << vehicleNo;
        cout << "\nVehicle Name   : " << vehicleName;
        cout << "\nVehicle Type   : " << vehicleType;
        cout << "\nRent Per Day   : Rs." << rentPerDay;
        cout << "\n--------------------------------";
    }
};


// =====================================================
// DERIVED CLASS - BUS
// =====================================================

class Bus : public Vehicle
{
public:

    Bus()
    {
        setVehicle(103, "Volvo", "Bus", 3000);
    }

    void displayVehicle()
    {
        cout << "\n--------------------------------";
        cout << "\nVehicle Number : " << vehicleNo;
        cout << "\nVehicle Name   : " << vehicleName;
        cout << "\nVehicle Type   : " << vehicleType;
        cout << "\nRent Per Day   : Rs." << rentPerDay;
        cout << "\n--------------------------------";
    }
};


// =====================================================
// CUSTOMER CLASS
// =====================================================

class Customer
{
private:
    int customerID;
    char customerName[30];
    char phone[15];
    char address[50];
    char licenseNo[20];

public:

    // Constructor
    Customer()
    {
        customerID = 0;
        strcpy(customerName, "");
        strcpy(phone, "");
        strcpy(address, "");
        strcpy(licenseNo, "");
    }

    // Get customer details
    void getCustomerDetails()
    {
        cout << "\n\n===== CUSTOMER DETAILS =====";

        cout << "\nEnter Customer ID: ";
        cin >> customerID;

        cout << "Enter Customer Name: ";
        cin >> customerName;

        cout << "Enter Phone Number: ";
        cin >> phone;

        cout << "Enter Address: ";
        cin >> address;

        cout << "Enter Driving License Number: ";
        cin >> licenseNo;
    }

    // Display customer
    void displayCustomer()
    {
        cout << "\n\n===== CUSTOMER INFORMATION =====";
        cout << "\nCustomer ID       : " << customerID;
        cout << "\nCustomer Name     : " << customerName;
        cout << "\nPhone Number      : " << phone;
        cout << "\nAddress           : " << address;
        cout << "\nDriving License   : " << licenseNo;
    }

    // Save customer details
    void saveToFile(ofstream &fout)
    {
        fout << "\n===== CUSTOMER INFORMATION =====\n";
        fout << "Customer ID       : " << customerID << "\n";
        fout << "Customer Name     : " << customerName << "\n";
        fout << "Phone Number      : " << phone << "\n";
        fout << "Address           : " << address << "\n";
        fout << "Driving License   : " << licenseNo << "\n";
    }
};


// =====================================================
// BOOKING CLASS
// =====================================================

class Booking
{
private:
    int bookingID;
    int days;

    // Used for automatic Booking ID generation
    static int nextBookingID;

public:

    // Constructor
    Booking()
    {
        bookingID = nextBookingID++;
        days = 0;
    }

    // Create booking
    void createBooking()
    {
        cout << "\n\n===== BOOKING DETAILS =====";

        // Booking ID is automatically generated
        cout << "\nBooking ID: " << bookingID;

        cout << "\nEnter Number of Days: ";
        cin >> days;
    }

    int getDays()
    {
        return days;
    }

    // Display booking
    void displayBooking()
    {
        cout << "\nBooking ID       : " << bookingID;
        cout << "\nRental Days      : " << days;
    }

    // Save booking to file
    void saveToFile(ofstream &fout)
    {
        fout << "\n===== BOOKING INFORMATION =====\n";
        fout << "Booking ID       : " << bookingID << "\n";
        fout << "Rental Days      : " << days << "\n";
    }
};


// Starting Booking ID
int Booking::nextBookingID = 1001;


// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    Customer customer;
    Booking booking;

    // Derived class objects
    Car car;
    Bike bike;
    Bus bus;

    // Base class pointer
    Vehicle *vehiclePtr;

    float totalRent;
    int choice;

    cout << "========================================";
    cout << "\n     SMART VEHICLE RENTAL SYSTEM";
    cout << "\n========================================";

    // Customer details
    customer.getCustomerDetails();


    // =================================================
    // DISPLAY AVAILABLE VEHICLES
    // =================================================

    cout << "\n\n===== AVAILABLE VEHICLES =====";

    cout << "\n\n1. CAR";
    vehiclePtr = &car;
    vehiclePtr->displayVehicle();

    cout << "\n\n2. BIKE";
    vehiclePtr = &bike;
    vehiclePtr->displayVehicle();

    cout << "\n\n3. BUS";
    vehiclePtr = &bus;
    vehiclePtr->displayVehicle();


    // =================================================
    // SELECT VEHICLE
    // =================================================

    cout << "\n\nEnter Vehicle Number to Book: ";
    cin >> choice;


    // =================================================
    // BOOKING DETAILS
    // =================================================

    booking.createBooking();


    // =================================================
    // POINTER + POLYMORPHISM
    // =================================================

    if(choice == 101)
    {
        vehiclePtr = &car;
    }
    else if(choice == 102)
    {
        vehiclePtr = &bike;
    }
    else if(choice == 103)
    {
        vehiclePtr = &bus;
    }
    else
    {
        cout << "\nInvalid Vehicle Number!";
        return 0;
    }

    // Calculate rent using base class pointer
    totalRent = vehiclePtr->calculateRent(booking.getDays());


    // =================================================
    // FINAL BOOKING INFORMATION
    // =================================================

    cout << "\n\n========================================";
    cout << "\n           BOOKING CONFIRMED";
    cout << "\n========================================";

    customer.displayCustomer();

    booking.displayBooking();

    cout << "\n\nVehicle Number   : "
         << vehiclePtr->getVehicleNo();

    cout << "\nVehicle          : "
         << vehiclePtr->getVehicleName();

    cout << "\nVehicle Type     : "
         << vehiclePtr->getVehicleType();

    cout << "\nRent Per Day     : Rs."
         << vehiclePtr->getRent();

    cout << "\nTotal Rent       : Rs."
         << totalRent;


    // =================================================
    // FILE HANDLING
    // =================================================

    ofstream fout("booking.txt", ios::app);

    if(fout)
    {
        fout << "\n\n========================================";
        fout << "\n       SMART VEHICLE RENTAL SYSTEM";
        fout << "\n========================================\n";

        customer.saveToFile(fout);

        booking.saveToFile(fout);

        vehiclePtr->saveToFile(fout);

        fout << "Total Rent       : Rs."
             << totalRent << "\n";

        fout << "========================================\n";

        fout.close();

        cout << "\n\nBooking saved successfully in booking.txt";
    }
    else
    {
        cout << "\n\nError opening booking.txt!";
    }


    // =================================================
    // END
    // =================================================

    cout << "\n\n========================================";
    cout << "\n       THANK YOU FOR BOOKING!";
    cout << "\n========================================";

    return 0;
}