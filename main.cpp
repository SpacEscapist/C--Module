#include <iostream>
#include <iomanip>
// Include data structure from STL
#include <map>

// This allows us to not need "std::" in front of our lines of code.
using namespace std;


//=============================================================== Global Variables ===============================================================

map<string, string> vehicleMap;


//=================================================================== Classes ===================================================================
class Vehicle {
public:
    string vehicle;
    string vehicleStatus;
 
    Vehicle() {
        cout << "\nVehicle Name: ";
        cin >> vehicle;
        cout << "Vehicle Status: ";
        cin >> vehicleStatus;

        vehicleMap.insert(pair<string, string>(vehicle, vehicleStatus));
    }
};


// ==================================================================== Functions ====================================================================
// Initialize Main Menu
void mainMenu();

// User creates a new vehicle
void newVehicle() {
    new Vehicle;

    // Ask user if they want to make another vehicle
    string response;
    cout << "\nWould you like to add another vehicle? (y/n): ";
    // User input
    cin >> response;
    
    if (response == "y") {
        newVehicle();
    }
    else {
        mainMenu();
    }
};

// User views current list of vehicles and their status
void viewVehicles() {
    // Iterate through the Map of vehicles and their status
    cout << "" << endl;
    cout << setw(10) << "VEHICLE" << "  |  " << "STATUS" << endl;
    cout << "-------------------------" << endl;
    for (auto itr = vehicleMap.begin(); itr != vehicleMap.end(); ++itr) {
        cout << setw(10) << itr->first << "  |  " << itr->second << endl;
    };
    cout << "-------------------------" << endl;

    mainMenu();
};

// Count number of vehicles in inventory
void countVehicles() {
    cout << "\n----------------------------------------------------" << endl;
    cout << "There are a total of -- " << vehicleMap.size() << " -- vehicle/s in inventory" << endl;
    cout << "----------------------------------------------------" << endl;

    mainMenu();
};

// User can remove a vehicle
void removeVehicle() {
    string vehicleName;
    // Iterate through map of vehicles and their status
    cout << "" << endl;
    cout << setw(10) << "VEHICLE" << "  |  " << "STATUS" << endl;
    cout << "-------------------------" << endl;
    for (auto itr = vehicleMap.begin(); itr != vehicleMap.end(); ++itr) {
        cout << setw(10) << itr->first << "  |  " << itr->second << endl;
    };
    cout << "-------------------------" << endl;
    cout << "Please enter the name of the vehicle you wish to remove" << endl;
    cout << "Vehicle Name: ";
    // User input
    cin >> vehicleName;
    
    // Remove vehicle from the Map
    vehicleMap.erase(vehicleName);
    cout << "\nThe " << vehicleName << " has been removed" << endl;
    
    mainMenu();
};

// Main Menu options
void mainMenu() {
    int selection;
    cout << "\n----- Main Menu -----\n" << endl;
    cout << "1. Create New Vehicle" << endl;
    cout << "2. View List of Vehicles" << endl;
    cout << "3. Number of Vehicles in Inventory" << endl;
    cout << "4. Remove Vehicle" << endl;
    cout << "5. Quit Program\n" << endl;
    cout << "Please enter selection: ";
    // User input
    cin >> selection;

    if (selection == 1) {
        newVehicle();
    }
    else if (selection == 2) {
        viewVehicles();
    }
    else if (selection == 3) {
        countVehicles();
    }
    else if (selection == 4) {
        removeVehicle();
    }
    else if (selection == 5) {
        cout << "\nExiting Program...\n";
        exit;
    }
    else {
        cout << "\n=============================\nPlease select a valid option\n=============================" << endl;
        mainMenu();
    }
};


// ==================================================================== Main ====================================================================
int main()
{
    mainMenu();
    return 0;
};