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
-> calculate subtotal
-> calculate total with taxes
-> calculate total + subtotal + taxes
-> iterate for each customer

customer has an orders collection. Then receipt is printed with recipe_lastname.txt in a folder txt
we iterate on each customer and build a new orders collection

*/

int promptNumCustomers();
string promptName();
int selectCatalog(const int numOptions, string options[], const string label);
int stringToInt(string str);
bool togglePrompt(const string &question);
void removeItem(vector<string> &coffeeItems, vector<string> &milkItems, vector<int> &cupSizeItems, int targetIndex);
void printItem(int cupSize, string coffee, string milk);
void printOrder(vector<string> coffeeItems, vector<string> milkItems, vector<int> cupSizeItems);
double calculateSubtotal(
    double coffeePrices[],
    double milkPrices[],
    double cupSizePrices[],
    vector<int> coffeeItemsIndex,
    vector<int> milkItemsIndex,
    vector<int> cupSizeItemsIndex
);
double calculateTotal(double subtotal, double taxRate);
double priceFinder(double prices[], string catalog[], string searchStr, int count);

int main () {
    const int NUM_COFFEE_OPTIONS = 7;
    const int NUM_MILK_OPTIONS = 7;
    const int NUM_CUP_SIZES = 3;
    string coffeeOptions[NUM_COFFEE_OPTIONS] = {"Drip", "Espresso", "Latte", "Cappuccino", "Cortado", "Flat White", "Mocha"};
    double coffeePrices[NUM_COFFEE_OPTIONS] = {2.99, 2.99, 4.99, 4.50, 3.99, 3.99, 5.50};
    string milkOptions[NUM_MILK_OPTIONS] = {"Regular", "2 percent (Regular)", "Oat", "Soy", "Almond", "Coconut", "No"};
    double milkAddOnPrices[NUM_MILK_OPTIONS] = {0, 0, 1.00, 0.75, 0.50, 1.00, 0};
    string cupSizes[NUM_CUP_SIZES] = {"8 oz", "12 oz", "16 oz"};
    double cupSizesAddOnPrices[NUM_CUP_SIZES] = {0, 2.00, 3.00};
    vector<string> coffeeItems; 
    vector<int> coffeeItemsIndex;
    vector<string> milkItems;
    vector<int> milkItemsIndex;
    vector<int> cupSizeItems;
    vector<int> cupSizeItemsIndex;
    string customerName;
    int milkSelectionIndex;
    int cupSizeSelectionIndex;
    int coffeeSelectionIndex;
    string coffee;
    string milk;
    int cupSize; // in oz
    double subtotal;
    double total;
    double taxRateIl = 6.25;
    int numCustomers;
    int itemCount;
    bool isAddingItem;
    bool isRemovingItem;

    numCustomers = promptNumCustomers();

    for (int i = 0; i < numCustomers; i++) {
        cout << "Customer " << i + 1 << ": \n"; 
        customerName = promptName();
        isAddingItem = true;
        cout << "\n===Select from the catalog===\n";

        while (isAddingItem == true) {
            coffeeSelectionIndex = selectCatalog(NUM_COFFEE_OPTIONS, coffeeOptions, "Coffee");
            coffee = coffeeOptions[coffeeSelectionIndex];

            if (coffeeSelectionIndex == 1) {
                // espresso has fixed 2 oz size and no milk
                milk = milkOptions[6]; // no milk
                cupSize = 2; // 2 oz
            } else if (coffeeSelectionIndex == 4) {
                // cortado has fixed 4 oz size with choice of milk
                cupSize = 4; // 4 oz
                milkSelectionIndex = selectCatalog(NUM_MILK_OPTIONS, milkOptions, "Milk");
                milk = milkOptions[milkSelectionIndex];
            } else {
                milkSelectionIndex = selectCatalog(NUM_MILK_OPTIONS, milkOptions, "Milk");
                cupSizeSelectionIndex = selectCatalog(NUM_CUP_SIZES, cupSizes, "Cup Size");
                cupSize = stringToInt(cupSizes[cupSizeSelectionIndex]);
                milk = milkOptions[milkSelectionIndex];
            }

            coffeeItems.push_back(coffee);
            milkItems.push_back(milk);
            cupSizeItems.push_back(cupSize);

            cout << "Order Added\n";
            printItem(cupSize, coffee, milk);
            string question = "Add another item to your order?";
            isAddingItem = togglePrompt(question);
        }

        do {
            isRemovingItem = togglePrompt("Do you want to remove an item?");

            if (isRemovingItem == true) {
                itemCount = coffeeItems.size();
                int removeItemIndex;
                cout << "Choose an item from the order to remove (1-" << itemCount << "): " << "\n";
                printOrder(coffeeItems, milkItems, cupSizeItems);
                cin >> removeItemIndex;
                removeItemIndex -= 1; // convert to an index
                removeItem(coffeeItems, milkItems, cupSizeItems, removeItemIndex);
            } 
        } while (isRemovingItem == true);

        itemCount = coffeeItems.size();

        if (itemCount > 0) {
            printOrder(coffeeItems, milkItems, cupSizeItems);
            cout << "Finalizing order..." << "\n";
            subtotal = calculateSubtotal(coffeePrices, milkAddOnPrices, cupSizesAddOnPrices, coffeeItemsIndex, milkItemsIndex, cupSizeItemsIndex);
            total = calculateTotal(subtotal, taxRateIl);
        } else {
            cout << "No items in order. Closing order. \n";
        } 

    }
    
}

/*─────────────────────────────────────────────────────────────
Function : calculateSubtotal
Purpose  : Calculates the subtotal dollar USD amount for the order.
Parameter: vector<string> &coffeeItems, vector<string> &milkItems, vector<int> &cupSizeItems
Returns  : double subtotal amount
Test     : 
            calculateSubtotal() -> 
       
            calculateSubtotal() -> 
            
            calculateSubtotal() -> 
           
─────────────────────────────────────────────────────────────*/
double calculateSubtotal(
    double coffeePrices[],
    double milkPrices[],
    double cupSizePrices[],
    vector<int> coffeeItemsIndex,
    vector<int> milkItemsIndex,
    vector<int> cupSizeItemsIndex
) {
    double subtotal = 0;
    double costCup;
    double costMilk;
    double costCoffee;
    int itemSize;

    itemSize = coffeeItemsIndex.size(); // number of items in an order

    for (int i = 0; i < itemSize; i++) {
        costCoffee = coffeePrices[coffeeItemsIndex[i]];
        costMilk = milkPrices[milkItemsIndex[i]];
        costCup = cupSizePrices[cupSizeItemsIndex[i]];
        subtotal = subtotal + costCoffee + costMilk + costCup;
    }

    return subtotal;
}

/*─────────────────────────────────────────────────────────────
Function : calculateTotal
Purpose  : Calculates the total dollar USD amount for the order.
Parameter: double subtotal, double taxRate
Returns  : double total amount
Test     :  calculateTotal() ->
            calculateTotal() ->
            calculateTotal() ->
─────────────────────────────────────────────────────────────*/
double calculateTotal(double subtotal, double taxRate) {
    return subtotal + subtotal * (taxRate / 100);
}

/*─────────────────────────────────────────────────────────────
Function : removeItem
Purpose  : Removes Item from an order
Parameter: vector<string> &coffeeItems, vector<string> &milkItems, vector<int> &cupSizeItems, int targetIndex
Returns  : void
Test     : 
        1 order with 3 items: espresso, latte with oat 8oz, Mocha with regular 2 percent 12oz
            removeItem(coffeeItems, milkItems, cupSizeItems, 1) -> prints
                Removing: 2oz size Espresso with No milk
            removeItem(coffeeItems, milkItems, cupSizeItems, 3) -> prints
                Removing: 12oz size Mocha with 2 percent (Regular) milk
            removeItem(coffeeItems, milkItems, cupSizeItems, 2) -> after printOrder
                Removing: 8oz size Latte with Oat milk
─────────────────────────────────────────────────────────────*/
void removeItem(vector<string> &coffeeItems, vector<string> &milkItems, vector<int> &cupSizeItems, int targetIndex) {
    vector<string> updatedCoffeeItems;
    vector<string> updatedMilkItems;
    vector<int> updatedCupSizeItems;
    int count = coffeeItems.size();

    for (int i = 0; i < count; i++) {
        if (targetIndex != i) {
            updatedCoffeeItems.push_back(coffeeItems[i]);
            updatedMilkItems.push_back(milkItems[i]);
            updatedCupSizeItems.push_back(cupSizeItems[i]);
        } else {
            cout << "Removing: ";
            printItem(cupSizeItems[i], coffeeItems[i], milkItems[i]);
        }
    }

    coffeeItems = updatedCoffeeItems;
    milkItems = updatedMilkItems;
    cupSizeItems = updatedCupSizeItems;
}

// ─────────────────────────────────────────────────────────────
// Function : printItem
// Purpose  : Prints formatted item
// Parameter: int cupSize, string coffee, string milk
// Returns  : void
// Test     : printItem(2, "Espresso", "No") -> 2oz size Espresso with No milk
//            printItem(12, "Latte", "Regular") -> 12oz size Latte with Regular milk
//            printItem(8, "Cappuccino", "Oat") -> 8oz size Cappuccino with Oat milk
// ─────────────────────────────────────────────────────────────
void printItem(int cupSize, string coffee, string milk) {
    cout << cupSize << "oz size " << coffee << " with " << milk << " milk\n";
}

/*─────────────────────────────────────────────────────────────
Function : printOrder
Purpose  : Prints formatted order
Parameter: vector<string> coffeeItems, vector<string> milkItems, vector<int> cupSizeItems
Returns  : void
Test     : 
            Input single item, espresso.
            printOrder(coffeeItems, milkItems, cupSizeItems) -> prints
                1. 2oz size Espresso with No milk
            Input 2 items, espresso, and latte with oat 8oz
            printOrder(coffeeItems, milkItems, cupSizeItems) -> prints
                1. 2oz size Espresso with No milk
                2. 8oz size Latte with Oat milk
            Input 3 items, espresso, latte with oat 8oz, cortado regular
            printOrder(coffeeItems, milkItems, cupSizeItems) -> prints
                1. 2oz size Espresso with No milk
                2. 8oz size Latte with Oat milk
                3. 4oz size Cortado with Regular milk
─────────────────────────────────────────────────────────────/*/
void printOrder(vector<string> coffeeItems, vector<string> milkItems, vector<int> cupSizeItems) {
    int count = coffeeItems.size();

    for (int i = 0; i < count; i++) {
        string coffee = coffeeItems[i];
        string milk = milkItems[i];
        int size = cupSizeItems[i];
        cout << i + 1 << ". ";
        printItem(size, coffee, milk);
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
    int count = str.length();

    for (int i = 0; i < count; i++) {
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
    cin.ignore();
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