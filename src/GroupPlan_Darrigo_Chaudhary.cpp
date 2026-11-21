// Programmer: William D'Arrigo | Course: CSC 155 | Group Lab - Coffee Shop Kiosk
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


/*
shortcuts (REMOVE BEFORE SUBMISSION)
./GroupPlan_Darrigo_Chaudhary
g++ -std=c++17 -Wall -Wextra GroupPlan_Darrigo_Chaudhary.cpp -o GroupPlan_Darrigo_Chaudhary

What's next:
-> Testing select catalog
-> Documentation
*/


string promptName();
int selectCatalog(const int numOptions, string options[], const string label);

int main () {
    const int NUM_COFFEE_OPTIONS = 7;
    const int NUM_MILK_OPTIONS = 7;
    const int NUM_CUP_SIZES = 3;
    string coffeeOptions[NUM_COFFEE_OPTIONS] = {"Drip", "Espresso", "Latte", "Cappuccino", "Cortado", "Flat White", "Mocha"};
    string milkOptions[] = {"Regular", "2 percent (Regular)", "Oat", "Soy", "Almond", "Coconut", "No Milk"};
    string cupSizes[NUM_CUP_SIZES] = {"8 oz", "12 oz", "16 oz"};
    bool isToGo = true; // may add function bool toggleSwitch(string label)
    string customerName;
    int milkSelection;
    int cupSizeSelection;
    int numCustomers;

    // if espresso then don't ask for cup size

    customerName = promptName();

    cout << "\n===Select from the catalog===\n";

    int coffeeSelection = selectCatalog(NUM_COFFEE_OPTIONS, coffeeOptions, "Coffee");

    if (coffeeSelection == 1) {
        // espresso has fixed size and no milk
        milkSelection = -1;
        cupSizeSelection = -1;    
    } else {
        milkSelection = selectCatalog(NUM_MILK_OPTIONS, milkOptions, "Milk");
        cupSizeSelection = selectCatalog(NUM_CUP_SIZES, cupSizes, "Cup Size");
    }

    cout << "Milk: " << milkSelection << endl;
    cout << "Cup Size: " << cupSizeSelection << endl;
    cout << "Coffee: " << coffeeSelection << endl;

    // cout << "\npromptName result: " << customerName;
}

// ─────────────────────────────────────────────────────────────
// Function : selectCatalog
// Purpose  : Gives the user the catalog options and prompts selection.
// Parameter: const int numOptions, string options[], const string label
// Returns  : int option index
// Test     : 
//            selectCatalog(4, {"S", "M", "L", "XL"}, "T Shirt Size") -> selecting "M" outputs 1
//            selectCatalog(1, {"Diet Cola"}, "Available Soda") ->  selecting "Diet Cola" outputs 0
//            selectCatalog(0, {}, "No Options Here") -> -1
// ─────────────────────────────────────────────────────────────
int selectCatalog(const int numOptions, string options[], const string label) {
    int selection;
    cout << label << ": " << "\n";

    if (numOptions == 0) {
        return -1; // no options available
    }
    
    for (int i = 0; i < numOptions; i++ ) {
        cout << i + 1 << ". " << options[i] << "\n";
    }

    do {
        cout << "\n" << "Selection (" << "1-" << numOptions << "): ";
        cin >> selection;
        if (selection < 1 || selection > numOptions) {
            cout << "\n Option Invalid. Try again.\n";
        }
    } while (selection < 1 || selection > numOptions);

    return selection - 1;
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

    if (name == "") {
        name = "Guest";
    }

    cout << "Hi " << name << endl;

    return name;
}