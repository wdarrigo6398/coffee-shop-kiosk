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
