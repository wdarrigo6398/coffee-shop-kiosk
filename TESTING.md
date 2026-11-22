TEST RECORD - Group Lab

T1  Normal
    Input: When prompted name, user enters "Billy Joel"
    Expected: Returns Billy Joel
    Actual: 
        Welcome to Oakton Hot Coffee!
        Enter your name: Billy Joel
        Hi Billy Joel

        promptName result: Billy Joel
    Result:   P

T2 Edge
    Input: When prompted name, user enters ""
    Expected: "Guest"
    Actual:
        Welcome to Oakton Hot Coffee!
        Enter your name: 
        Hi Guest
    Result: P

T3 Normal
    Input: User selects "Latte", "8 oz", "Oat Milk"
    Expected: 
        Indeces chosen (coffee, size, and milk respectively) -> 2, 0, 2
    Actual:
        Milk: 2
        Cup Size: 0
        Coffee: 2
    Result: P

T4 Edge
    Input: Selects "Espresso" 
    Expected: Prompt should skip milk and cup size. Coffee index should be 1. 
        Cup size and milk index will be -1.
    Actual:
        Milk: -1
        Cup Size: -1
        Coffee: 1
    Result: P

T5 Normal
    Input: 1 customer. First order: 8oz latte regular milk; Second Order: 12oz cappuccino oat milk.
    Expected: Should prompt order twice for that customer. Every item should be displayed.
    Actual:
    Result: 
        Coffee: 
        1. Drip
        2. Espresso
        3. Latte
        4. Cappuccino
        5. Cortado
        6. Flat White
        7. Mocha

        Selection (1-7): 3

        Milk: 
        1. Regular
        2. 2 percent (Regular)
        3. Oat
        4. Soy
        5. Almond
        6. Coconut
        7. No

        Selection (1-7): 1

        Cup Size: 
        1. 8 oz
        2. 12 oz
        3. 16 oz

        Selection (1-3): 1

        Order Added
        8oz size Latte with Regular milk
        Add another item to your order? (Y/N): y
        Coffee: 
        1. Drip
        2. Espresso
        3. Latte
        4. Cappuccino
        5. Cortado
        6. Flat White
        7. Mocha

        Selection (1-7): 4

        Milk: 
        1. Regular
        2. 2 percent (Regular)
        3. Oat
        4. Soy
        5. Almond
        6. Coconut
        7. No

        Selection (1-7): 3

        Cup Size: 
        1. 8 oz
        2. 12 oz
        3. 16 oz

        Selection (1-3): 2

        Order Added
        12oz size Cappuccino with Oat milk
        Add another item to your order? (Y/N): n

T6 Edge
    Input: 1 customer. Espresso coffee.
    Expected: For espresso, order should have no milk, and be fixed 2oz size. 
    Actual: 
        ===Select from the catalog===
    Coffee: 
    1. Drip
    2. Espresso
    3. Latte
    4. Cappuccino
    5. Cortado
    6. Flat White
    7. Mocha

    Selection (1-7): 2

    Order Added
    2oz size Espresso with No milk
    Add another item to your order? (Y/N): n

    Result: P

T7 Normal
    Input: 1 customer; 3 items on an order; espresso, cortado with oat, latte with regular 8oz. Remove cortado
    Expected: cortado should be removed from the order.
    Actual: 
        Do you want to remove an item? (Y/N): y
        Choose an item from the order to remove (1-3): 
        1. 2oz size Espresso with No milk
        2. 4oz size Cortado with Oat milk
        3. 8oz size Latte with Regular milk
        2
        Removing: 4oz size Cortado with Oat milk
        Do you want to remove an item? (Y/N): n
        1. 2oz size Espresso with No milk
        2. 8oz size Latte with Regular milk
        Finalizing order...

T8 Edge
    Input: 1 customer; 1 item on order; remove the only item
    Expected: Should not print the order as there are no items. 
        Removing: 2oz size Espresso with No milk
    Actual:    
        Do you want to remove an item? (Y/N): n
        Finalizing order...
    Result: P