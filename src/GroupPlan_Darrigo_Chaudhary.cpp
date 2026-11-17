// Programmer: William D'Arrigo | Course: CSC 155 | Group Lab - Coffee Shop Kiosk
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// shortcuts (REMOVE BEFORE SUBMISSION)
// ./GroupPlan_Darrigo_Chaudhary
// g++ -std=c++17 -Wall -Wextra GroupPlan_Darrigo_Chaudhary.cpp -o GroupPlan_Darrigo_Chaudhary

string promptName();

int main () {
    int numCustomers;

    string customerName = promptName();

    cout << "\npromptName result: " << customerName;
}

// ─────────────────────────────────────────────────────────────
// Function : promptName
// Purpose  : Prompts the customer for their name
// Parameter: N/A
// Returns  : string - customer name
// Test     : 
//            User inputs the following names: William Darrigo, Jose Gonzalez, Jen Smith
//            promptName() -> William Darrigo
//            promptName() -> Jose Gonzalez
//            promptName() -> Jen Smith
// ─────────────────────────────────────────────────────────────
string promptName() {
    string name;
    cout << "Welcome to Oakton Hot Coffee!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hi " << name << endl;
    return name;
}