/*****************************************************************************
*
*  Author:           Brett Smith
*  Email:            brettsmith578@gmail.com
*  Label:            A03
*  Title:            Basic Project Organization
*  Course:           CMPS 2143
*  Semester:         Spring 2023 
*
*  Description:
*        This program implements a class that creates and manipulates a queue.
*        Overloaded functions are used to create the queue. Depending on if a certain
*        size is passed in or not will determine which function will be called. It overloads
*        the "<<" operator allowing the ability to print the queue using the "cout" object
*        instead of having to create and call a print function.
*
*  Usage:
*        N/A
*
*  Files:
*        main.cpp    : driver program
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 *
 * Description:
 *      This class is used to create and manipulate a queue.
 *
 * Public Methods:
 *                  CircularArrayQue()
 *                  CircularArrayQue(int size)
 *      void        Push(int item)
 *      int         Pop()
 *
 * Private Methods:
 *      void        init(int size = 0)
 *      bool        Full()
 *
 * Usage:
 *
 *      CircularArrayQue C1;             //Create a queue of default size 10
 *      Push(5);                         //Call Push to add int to front of queue
 *      Push(23);                        //Continue to call Push until queue is
 *                                       //full or user has entered desired number
 * 
 *                                       //or
 * 
 *      CircularArrayQue C2(2);          //Create a queue of custom size
 *      Push(77);                        //Call Push to fill queue with
 *      Push(37);                        //specified number of ints
 *      Pop();                           //Call Pop to return first number in queue
 *
 */

class CircularArrayQue {
private:
    int* Container;     // int pointer holds address of queue
    int Front;          // int at front of queue
    int Rear;           // int at rear of queue
    int QueSize;        // items in the queue
    int CurrentSize;    // size of queue

    /**
     * Private: init
     *
     * Description:
     *      Initializes the Front, Rear, and CurrentSize to 0.
     *      Also sets QueSize to either 0 as default or user specified size.
     *
     * Params:
     *      int  :  queue size
     *
     * Returns:
     *      N/A
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private: Full
     *
     * Description:
     *      Checks if queue is full.
     *
     * Params:
     *      None
     *
     * Returns:
     *      bool  :  True if full otherwise False
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:

    /**
     * Public: CircularArrayQue
     *
     * Description:
     *      Default constructor that creates a queue with default size of 10 ints.
     *
     * Params:
     *      None
     *
     * Returns:
     *      N/A
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

    /**
     * Public: CircularArrayQue
     *
     * Description:
     *      Overloaded function that allows user to pass in an int to create
     *      a queue of custom size
     *
     * Params:
     *      int  :  queue size
     *
     * Returns:
     *      N/A
     */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public: Push
     *
     * Description:
     *      Allows user to enter an int that is then added to the end of the queue.
     *      If the queue is full, "FULL!!!!" is printed to the console
     *
     * Params:
     *      int  :  item in queue
     *
     * Returns:
     *      N/A
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public: Pop
     *
     * Description:
     *      The int that is in the front of the queue is removed and stored in a temp variable.
     *      Front is then moved to the next item in the queue, the queue size is reduced, and
     *      the int stored in temp is returned.
     *
     * Params:
     *      None
     *
     * Returns:
     *      int  :  number that was first in queue
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const CircularArrayQue& other);     //overloaded "<<" operator defined below
};


/**
 * Function to overload "<<" operator
 *
 * Description:
 *      Used to overload the "<<" operator which, in turn, gives the ability
 *      to print any created queue without having to create and define a
 *      seperate print function in the class.
 *
 * Params:
 *      ostream&           :  iostream class
 *      CircularArrayQue&  :  address of a queue
 *
 * Returns:
 *      ostream&           :  reference to "<<" operator that allows a queue to be printed
 */
ostream& operator<<(ostream& os, const CircularArrayQue& other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
    CircularArrayQue C1(5);     //Creates a queue of size 5

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);                 //
    C1.Push(2);                 //Pushes the numbers 1, 2, 3 to the queuq
    C1.Push(3);                 //
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;         //Prints queue

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;         //Prints queue
}
