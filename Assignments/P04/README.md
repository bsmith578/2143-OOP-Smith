## P04 - Dice Class
### Brett Smith
### Description:

This program contains 2 classes: Die and Dice. The Die class will create
an instace of a sigular die. The user can pass in the number of sides
for the die or it will default to 6. The Die class also contains a 
method to roll a die and return a number from 1 to the number of sides
and a method to print the number of sides for a die. The Dice class is
used to create multiple instances of a Die of n sides. The user can pass
in the number of dice and the number of sides for all dice or a string
such as "5.d.20" and 5 20-sided dice will be created and stored in a
list. The Dice class contains methods to roll all the dice and to find
the sum, min, max, and average of all the rolls.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [banner.txt](https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/P04/banner.txt)  | Banner for P04 |
|   2   | [dice.py](https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/P04/dice.py)    | Python file that contains the classes and methods |
|   3   | [main.py](https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/P04/main.py)  | Main driver of the program |

### Instructions

- In main.py you must have: 
    - from dice import Die
    - from dice import Dice

- Example Input:
    - d1 = Die()        //creates a single Die with 6 sides
    - d2 = Die(10)      //creates a single die with 10 sides
    - d3 = Dice("5.d.20")   //creates 5 - 20 sided dice

    - print(d1)         //prints: Dice:[
                                    [sides: 6]
                                       ]

    - d3.rollAll()      //rolls a random value for all 5 dice
    - print(d3.rollVals)    //prints all values of the 5 dice
    - print(d3.roll('max')) //prints the max number of the 5
    - print(d3.roll('min')) //prints the min number of the 5
    - print(d3.roll('avg')) //prints the average of all 5
    - print(d3.roll())      //prints the sum of all 5
