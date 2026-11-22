# Coffee Shop Kiosk

## Purpose
A program that takes in customer orders at a coffee shop and outputs a receipt.

## Features
- prints receipts to receipt.txt file
- customer can select from catalog for coffee, milk, and cup sizes
- user may remove items from an order
- user may add on to an order
- can handle multiple customers
- calculates total cost of an order including taxes

## C++17 build/run instructions
In src directory run:
>> g++ -std=c++17 -Wall -Wextra *.cpp
>> ./a

## Input/data requirements
Up to 5 customers can use the kiosk at a time. Input the customer name, 
then follow the prompts to build the order. You will be asked for the coffee,
type of milk, and cup size. Once order is done, the receipt is printed, and
the next customer in line will use the kiosk.

## Known limitations
- Kiosk can only handle up to 5 customers
- Customer cannot select an item that does not exist
- only a single receipts.txt file is outputted for all the customers