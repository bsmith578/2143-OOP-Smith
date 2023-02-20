## P02 - MyVector Class 2
### Brett Smith
### Description:

This program takes the class created in P01 and adds more functionality. This is achieved by
adding methods to overload C++ operators (<<, [], +, -, \*, /, =, ==). Some of these
methods will allow the program to print a Vector using '<<' without having to call the print
method, add a value onto the vector using '+' instead of having to call a push method, or check
if two vectors are equal using '=='.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [banner.txt](https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/P02/banner.txt)  | Banner for P02 |
|   2   | [main.cpp](https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/P02/main.cpp)    | Main driver of my program that includes the class and methods |
|   3   | [output.txt](https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/P02/output.txt)  | Output file that is written to in main |

### Instructions

- Must have #include<iostream> and #include<fstream>
- Read the methods within the MyVector Class to see how to create an
    instance of a vector and ways to manipulate it

- Example Command:
    - int a1[] = { 1, 2, 3, 4, 5 };     //create an array of integers
    - MyVector v1(a1,5);                //create an instance of a MyVector and fill it with values from a1
    
    - cout << v1[2] << endl;            //print the value at index 2 from MyVector v1
    - outfile << v1[2] << endl;         //to the console and an output file
    
    - cout << v1 << endl;               //print MyVector v1 to the console
