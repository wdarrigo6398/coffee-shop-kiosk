// Programmer: William D'Arrigo | Course: CSC 155 | Group Lab - Coffee Shop Kiosk
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


/*
shortcuts (REMOVE BEFORE SUBMISSION)
./GroupPlan_Darrigo_Chaudhary
g++ -std=c++17 -Wall -Wextra GroupPlan_Darrigo_Chaudhary.cpp -o GroupPlan_Darrigo_Chaudhary

What's next:
-> remove item

customer has an orders collection. Then receipt is printed with recipe_lastname.txt in a folder txt
we iterate on each customer and build a new orders collection

*/

int promptNumCustomers();
string promptName();
int selectCatalog(const int numOptions, string options[], const string label);
int stringToInt(string str);
bool togglePrompt(const string &question);

int main () {
    const int NUM_COFFEE_OPTIONS = 7;
    const int NUM_MILK_OPTIONS = 7;
    const int NUM_CUP_SIZES = 3;
    string coffeeOptions[NUM_COFFEE_OPTIONS] = {"Drip", "Espresso", "Latte", "Cappuccino", "Cortado", "Flat White", "Mocha"};
    string milkOptions[] = {"Regular", "2 percent (Regular)", "Oat", "Soy", "Almond", "Coconut", "No"};
    string cupSizes[NUM_CUP_SIZES] = {"8 oz", "12 oz", "16 oz"};
    vector<string> coffeeOrders; 
    vector<string> milkOrders;
    vector<int> cupOrders;
    bool isToGo = true; // may add function bool toggleSwitch(string label)
    string customerName;
    int milkSelectionIndex;
    int cupSizeSelectionIndex;
    int coffeeSelectionIndex;
    int numCustomersIndex;
    string coffee;
    string milk;
    int cupSize; // in oz
    string numCustomers;
    bool isAddingItem = true;

    numCustomers = promptNumCustomers();
    customerName = promptName();

    cout << "\n===Select from the catalog===\n";

    while (isAddingItem == true) {
        coffeeSelectionIndex = selectCatalog(NUM_COFFEE_OPTIONS, coffeeOptions, "Coffee");
        coffee = coffeeOptions[coffeeSelectionIndex];

        if (coffeeSelectionIndex == 1) {
            // espresso has fixed 2 oz size and no milk
            milk = milkOptions[6]; // no milk
            cupSize = 2; // 2 oz
        } else {
            milkSelectionIndex = selectCatalog(NUM_MILK_OPTIONS, milkOptions, "Milk");
            cupSizeSelectionIndex = selectCatalog(NUM_CUP_SIZES, cupSizes, "Cup Size");
            cupSize = stringToInt(cupSizes[cupSizeSelectionIndex]);
            milk = milkOptions[milkSelectionIndex];
        }

        coffeeOrders.push_back(coffee);
        milkOrders.push_back(milk);
        cupOrders.push_back(cupSize);

        cout << "Order Added\n";
        cout << cupSize << "oz size " << coffee << " with " << milk << " milk\n";
        string question = "Add another item to your order?";
        isAddingItem = togglePrompt(question);
    }

}

// ─────────────────────────────────────────────────────────────
// Function : togglePrompt
// Purpose  : Prompts customer a yes or no question and returns a boolean 
// Parameter: string question
// Returns  : bool
// Test     : togglePrompt("Do we need to buy food?") -> user inputs 'n' and returns false
//            togglePrompt("Will it be cold today?") -> user inputs 'Y' and returns true
//            togglePrompt("Is C++ fun?") -> true -> user inputs 'y' and returns true
// ─────────────────────────────────────────────────────────────
bool togglePrompt(const string &question) {
    char answer;
    cout << question << " (Y/N): ";
    cin >> answer;
    return (answer == 'Y' || answer == 'y');
}

// ─────────────────────────────────────────────────────────────
// Function : stringToInt
// Purpose  : Converts string to integer 
// Parameter: string str
// Returns  : int
// Test     : stringToInt("20 oz") -> 20
//            stringToInt("no numbers here") -> -1
//            stringToInt("hello world 4") -> 4
// ─────────────────────────────────────────────────────────────
int stringToInt(string str) {
    string digitsOnly = "";
    char zero = '0';
    char nine = '9';

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        // comparing ASCII values for 0-9
        if (c >= zero && c <= nine) {
            digitsOnly = digitsOnly += c;
        }
    }

    if (digitsOnly == "") {
        return -1;
    }

    return stoi(digitsOnly);
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
        cout << "\n";
        if (selection < 1 || selection > numOptions) {
            cout << "Option Invalid. Try again.\n";
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
    getline(cin, name); // TODO: careful here may need cin.ignore()

    if (name == "") {
        name = "Guest";
    }

    cout << "Hi " << name << endl;

    return name;
}


// ─────────────────────────────────────────────────────────────
// Function : promptNumCustomers
// Purpose  : Prompts the number of customers waiting in line.
// Parameter: N/A
// Returns  : int - number of customers in line.
// Test     : promptNumCustomers() -> User inputs 0, displays "Waiting for customers to get in line..."
//            promptNumCustomers() -> User inputs 1, returns 1
//            promptNumCustomers() -> User input 10, displays "Too many customers to fit into line. Try again."
// ─────────────────────────────────────────────────────────────
int promptNumCustomers() {
    int numCustomers;
    do {
        cout << "Number of customers in line: ";
        cin >> numCustomers;
        cin.ignore();
        if (numCustomers == 0) {
            cout << "Waiting for customers to get in line...\n";
        }
        else if (numCustomers > 5) {
            cout << "Too many customers to fit into line. Try again. \n";
        } else if (numCustomers < 0) {
            cout << "Invalid number of customers. Try again. \n";
        }
    } while(numCustomers > 5 || numCustomers <= 0);

    return numCustomers;
}

void addItem(string item) {

}