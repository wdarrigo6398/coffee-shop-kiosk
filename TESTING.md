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

T9 Error
    Input: 2 customers
    Expected: Should prompt both customers for their orders, then print the order.
    Actual:
        Enter your name: John
        Hi John

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
        Do you want to remove an item? (Y/N): n
        1. 2oz size Espresso with No milk
        Finalizing order...
    Result: F

T10 Normal
    Input: 2 customers
    Expected: Should prompt both customers for their orders, then print the order.
    Actual: 
        Number of customers in line: 2
        Customer 1: 
        Welcome to Oakton Hot Coffee!
        Enter your name: John
        Hi John

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
        Do you want to remove an item? (Y/N): n
        1. 2oz size Espresso with No milk
        Finalizing order...
        Customer 2: 
        Welcome to Oakton Hot Coffee!
        Enter your name: Jane
        Hi Jane

        ===Select from the catalog===
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
        Add another item to your order? (Y/N): n
        Do you want to remove an item? (Y/N): n
        1. 2oz size Espresso with No milk
        2. 8oz size Latte with Regular milk
        Finalizing order...
    Result: P

T11 Edge
    Input: 0 customers
    Expected: Should give warning message that there are no customes waiting in line, then ask again for
        customers in line.
    Actual:
        Number of customers in line: 0
        Waiting for customers to get in line...
        Number of customers in line: 
    Result: P

T12 Normal
    Input: 1 customer; 2 items on an order: espresso, latte with oatmilk. 
    Expected: Total should be 9.54
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
    Add another item to your order? (Y/N): y
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

    Selection (1-7): 3

    Cup Size: 
    1. 8 oz
    2. 12 oz
    3. 16 oz

    Selection (1-3): 1

    Order Added
    8oz size Latte with Oat milk
    Add another item to your order? (Y/N): n
    Do you want to remove an item? (Y/N): n
    1. 2oz size Espresso with No milk
    2. 8oz size Latte with Oat milk
    Finalizing order...
    Subtotal: 8.98
    Total: 9.54
    Result: 

T13 Edge
    Input: 1 customer; 2 items on an order, then remove the 2 items
    Expected: Kiosk should not calculate total and gracefully exit order
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
    Add another item to your order? (Y/N): y
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

    Selection (1-7): 3

    Cup Size: 
    1. 8 oz
    2. 12 oz
    3. 16 oz

    Selection (1-3): 1

    Order Added
    8oz size Latte with Oat milk
    Add another item to your order? (Y/N): n
    Do you want to remove an item? (Y/N): y

    Choose an item from the order to remove (1-2): 
    1. 2oz size Espresso with No milk
    2. 8oz size Latte with Oat milk
    Item Number: 3
    Item not found.
    Do you want to remove an item? (Y/N): y

    Choose an item from the order to remove (1-2): 
    1. 2oz size Espresso with No milk
    2. 8oz size Latte with Oat milk
    Item Number: 2
    Removing: 8oz size Latte with Oat milk
    Do you want to remove an item? (Y/N): y

    Choose an item from the order to remove (1-1): 
    1. 2oz size Espresso with No milk
    Item Number: 1
    Removing: 2oz size Espresso with No milk
    No items in order. Closing order. 
    Result: P

T14 Error
    Input: 2 customers 
    Expected: reciepts.txt containing correct order information
    Actual:
    ============================================
                OAKTON HOT COFFEE
            123 Main St, Des Plaines
                (555)555-5555
    ============================================

    Name:               John Smith
    Order:
    2oz size Espresso with No milk
        2.99
    4oz size Cortado with Oat milk
        4.99
    12oz size Latte with Oat milk
        7.99
    Subtotal:                15.97
    Tax:                      6.25
    Total:                 16.9681

    ============================================
                OAKTON HOT COFFEE
            123 Main St, Des Plaines
                (555)555-5555
    ============================================

    Name:           Jennifer Smith
    Order:
    16oz size Mocha with Oat milk
        9.5
    8oz size Flat White with Soy milk
        4.99
    Subtotal:                19.23
    Tax:                      6.25
    Total:                 20.4319


    Result: F

T15 Normal
    Input:  2 customers
    Expected: Correct order information in receipts.txt
    Actual:
        ============================================
            OAKTON HOT COFFEE
        123 Main St, Des Plaines
               (555)555-5555
        ============================================

        Name:               John Smith
        Order:
        8oz size Drip with Regular milk
            2.99
        12oz size Latte with Oat milk
            7.99
        Subtotal:                10.98
        Tax:                      0.69
        Total:                   11.67

        ============================================
                    OAKTON HOT COFFEE
                123 Main St, Des Plaines
                    (555)555-5555
        ============================================

        Name:                Jen Smith
        Order:
        4oz size Cortado with Oat milk
            4.99
        2oz size Espresso with No milk
            2.99
        Subtotal:                 7.98
        Tax:                      0.50
        Total:                    8.48

    Result: P

T16 Error
    Input: 1 customer, remove an item from the order
    Expected: Verify that the info matches in the receipt
    Actual: 
        
    Name:                     john
    Order:
    2oz size Espresso with No milk
        5.99
    8oz size Cappuccino with Soy milk
        2.99
    Subtotal:                14.23
    Tax:                      0.89
    Total:                   15.12

    Result: F - prices do not match with item

T17 Normal
    Input: 1 customer. Remove item before printing receipt
    Expected: Prices should match
    Actual:   
        Name:                     John
        Order:
        16oz size Latte with Oat milk
            8.99
        Subtotal:                 8.99
        Tax:                      0.56
        Total:                    9.55
    Result: P
