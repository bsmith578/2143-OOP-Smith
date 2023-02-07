/*****************************************************************************
*                    
*  Author:           Brett Smith
*  Email:            brettsmith578@gmail.com
*  Label:            P01
*  Title:            Program 1 - Vector Class
*  Course:           CMPS 2143-201 OOP
*  Semester:         Spring 2023
* 
*  Description:
*        This program uses a linked list based Vector class to create instances of
*        Vectors. These Vectors hold integers and are able to grow and shring without
*        having to copy values into newly allocated memory. An instance of a Vector can
*        be initialized using multiple push methods described below. There are also methods
*        that can remove items from Vector using different techniques. Each Vector can also
*        be printed using the print() method which dispalys data to the console and to an
*        output file.
* 
*  Usage:
*        See methods in class Vector to see how to create Vectors and add, remove,
*        and print data in Vectors.
* 
*  Files:
*        main.cpp     : driver program
*        input.dat    : input file with data implemented inside main
*        test.out     : output file created to print Vector data to
*****************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;


/**
 * struct Node
 * 
 * Description:
 *      Creates Nodes that store data and pointers used in creating linked lists
 * 
 * Public Methods:
 *                  Node()
 * 
 * Usage: 
 * 
 *      Node temp = new Node(3)    //creates a new Node with the value 3
 *                                 //that can be used to create a new list
 *                                 //or linked into an existing list
 *      
 */
struct Node
{
  int data;
  Node * next;

  Node(int d = 0, Node * n = nullptr)
  {
    data = d;
    next = n;
  }
};


/**
 * Vector
 * 
 * Description:
 *      This class creates instances of linked list based Vectors that hold ints then
 *      uses multiple methods to add, remove, and print data contained in the Vectors
 * 
 * Public Methods:
 *             Vector()
 *             Vector(int * A, int size)
 *             Vector(string FileName)
 *             Vector(const Vector &other)
 *      void   pushFront(int val)
 *      void   pushFront(Vector &other)
 *      void   pushRear(int val)
 *      void   pushRear(Vector &other)
 *      void   pushAt(int loc,int val)
 *      void   inOrderPush(int val)
 *      int    popFront()
 *      int    popRear()
 *      int    popAt(int loc)
 *      int    find(int val)
 *      void   print(ofstream &outfile)
 *      int    size()
 * 
 * Private Methods:
 *      N/A
 * 
 * Usage: 
 * 
 *      int arr[] = {1, 2, 3};    //Create an array with values
 *      Vector v(arr, 3);         //Create an instance of a Vector and
 *                                //pass in the array and its size
 *
 *      v.pushFront(0);           //Add 0 to the front of the Vector
 *      v.pushRear(4);            //Add 4 to the rear of the Vector
 *      v.popAt(2);               //Remove the value at index 2
 *      v.print(outfile);         //Print the values in the Vector to 
 *                                //stdout and an outfile created in main
 *      
 */
class Vector
{
  private:
    Node * head;  //head and tail to keep track
    Node * tail;  //of front and back of list

  public:

    /**
     * Public : Vector
     * 
     * Description:
     *      Defualt constructor that creates an empty Vector
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    Vector()
    {
      head = tail = nullptr;
    }

    
    /**
     * Public : Vector
     * 
     * Description:
     *      Overloaded Vector constructor that creates a Vector
     *      using data inside an array
     * 
     * Params:
     *      int*  :  Array of integers
     *      int   :  Size of the array 
     * 
     * Returns:
     *      N/A
     */
    Vector(int * A, int size)
    {
      head = tail = nullptr;

      for(int i = 0; i < size; i++)
        pushRear(A[i]);
    }

    
    /**
     * Public : Vector
     * 
     * Description:
     *      Overloaded Vector constructor that creates a Vector
     *      by reading in data from an input file
     * 
     * Params:
     *      string  :  Name of input file
     * 
     * Returns:
     *      N/A
     */
    Vector(string FileName)
    {
      head = tail = nullptr;
      int n;

      ifstream infile;
      infile.open(FileName);
      
      while(!infile.eof())
      {
        infile >> n;
        pushRear(n);
      }

      infile.close();
    }

    
    /**
     * Public : Vector
     * 
     * Description:
     *      Overloaded Vector constructor that creates a Vector
     *      with the data contained in another Vector
     * 
     * Params:
     *      const Vector  :  Address of another vector previously declared
     * 
     * Returns:
     *      N/A
     */
    Vector(const Vector &other)
    {
      head = tail = nullptr;
      Node * traverse = other.head;

      while(traverse != nullptr)
      {
        this->pushRear(traverse->data);
        traverse = traverse->next;
      }
    }

    
    /**
     * Public : pushFront
     * 
     * Description:
     *      Adds a value to the front of a Vector
     * 
     * Params:
     *      int  :  Integer to be added
     * 
     * Returns:
     *      N/A
     */
    void pushFront(int val)
    {
      Node * temp = new Node(val, head);

      if(head == nullptr)
      {
        head = tail = temp;
      }

      else
      {
        temp->next = head;
        head = temp;
      }
    }

    
    /**
     * Public : pushFront
     * 
     * Description:
     *      Adds entire other.list to the front of this.list
     * 
     * Params:
     *      Vector  :  Address of another Vector previously Declared
     * 
     * Returns:
     *      N/A
     */
    void pushFront(Vector &other)
    {
      int s = other.size();
      Node * traverse = other.head;
      Node * temp = other.tail;

      for(int i = 0; i < (s - 1); i++)
      {
        while(traverse->next != temp)
        {
          traverse = traverse->next;
        }
  
        this->pushFront(temp->data);
        temp = traverse;
        traverse = other.head;
      }

      this->pushFront(other.head->data);
    }

    
    /**
     * Public : pushRear
     * 
     * Description:
     *      Adds a value to the rear of a Vector
     * 
     * Params:
     *      int  :  Integer to be added
     * 
     * Returns:
     *      N/A
     */
    void pushRear(int val)
    {
      Node * temp = new Node(val);

      if(head == nullptr)
      {
        head = tail = temp;
      }

      else
      {
        tail->next = temp;
        tail = temp;
      }
      
    }

    
    /**
     * Public : pushRear
     * 
     * Description:
     *      Adds entire other.list to the rear of this.list
     * 
     * Params:
     *      Vector  :  Address of another vector previously declared
     * 
     * Returns:
     *      N/A
     */
    void pushRear(Vector &other)
    {
      Node * traverse = other.head;

      while(traverse != nullptr)
      {
        this->pushRear(traverse->data);
        traverse = traverse->next;
      }
    }

    
    /**
     * Public : pushAt
     * 
     * Description:
     *      Insert a value to the Vector at a specified index
     * 
     * Params:
     *      int  :  Index of where to place the value
     *      int  :  Integer to be placed at the index
     * 
     * Returns:
     *      N/A
     */
    void pushAt(int loc,int val)
    {
      int s = this->size();
      Node * temp = new Node(val);

      if(head == nullptr && loc > 0)
        cout << "Vector is empty. Cannot place value at this location.";

      else if(loc > (s - 1))
        cout << "Vector is smaller than entered location. Location does not exist.";

      else if(loc == 0)
        pushFront(val);

      else if(loc == (s - 1))
        pushRear(val);

      else
      {
        Node * traverse = head;

        for(int i = 0; i < (loc - 1); i++)
        {
          traverse = traverse->next;
        }

        temp->next = traverse->next;
        traverse->next = temp;
      }
    }

    
    /**
     * Public : inOrderPush
     * 
     * Description:
     *      Adds a value to the Vector in numerical order
     * 
     * Params:
     *      int  :  Integer to be added
     * 
     * Returns:
     *      N/A
     */
    void inOrderPush(int val)
    {
      Node * temp = new Node(val);

      if(head == nullptr)
        head = tail = temp;

      else if(temp->data < head->data)
        pushFront(val);

      else
      {
        Node * traverse = head;

        while(traverse->next && traverse->next->data < temp->data)
          traverse = traverse->next;

        if(traverse->next == nullptr)
          pushRear(val);

        else
        {
          temp->next = traverse->next;
          traverse->next = temp;
        }
      }
    }

    
    /**
     * Public : popFront
     * 
     * Description:
     *      Deletes the value that is in front of the Vector and returns the value
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int  :  Integer removed from the Vector
     */
    int popFront()
    {
      int temp = head->data;
      Node * deleteme = head;
      head = head->next;
      delete deleteme;

      return temp;
    }

    
    /**
     * Public : popRear
     * 
     * Description:
     *      Deletes the value that is at the rear of the Vector and returns the value
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int  :  Integer removed from the Vector
     */
    int popRear()
    {
      Node * traverse = head;
      while(traverse->next != tail)
      {
        traverse = traverse->next;
      }
      
      int temp = tail->data;
      Node * deleteme = tail;
      tail = traverse;
      delete deleteme;
      tail->next = nullptr;

      return temp;
    }

    
    /**
     * Public : popAt
     * 
     * Description:
     *      Deletes a value at a specified index of the Vector and returns the value
     * 
     * Params:
     *      int  :  Index of value to be removed
     * 
     * Returns:
     *      int  :  Integer removed from vector
     */
    int popAt(int loc)
    {
      int s = this->size();
      int temp;

      if(head == nullptr)
        cout << "Vector is empty. No values to remove.";

      else if(loc > (s - 1))
        cout << "Location does not exist.";

      else if(loc == (s - 1))
        temp = popRear();

      else if(loc == 0)
        temp = popFront();

      else
      {
        Node * traverse = head;
        
        for(int i = 0; i < (loc - 1); i++)
        {
          traverse = traverse->next;
        }
        
        temp = traverse->next->data;
        Node * deleteme = traverse->next;
        traverse->next = traverse->next->next;
        delete deleteme;
      }

      return temp;
    }

    
    /**
     * Public : find
     * 
     * Description:
     *      Finds a specified value in the Vector (if it exists) and returns the index
     *      or return -1 if the value is not in the Vector
     * 
     * Params:
     *      int  :  Integer to be found within the Vector
     * 
     * Returns:
     *      int  :  Index of specified value
     */
    int find(int val)
    {                  //if the value is not in list it returns -1
      int index = 0;

      if(head == nullptr)
        index = -1;

      else
      {
        Node * traverse = head;

        while(traverse && traverse->data != val && traverse->next != nullptr)
        {
          traverse = traverse->next;
          index++;
        }

        if(traverse->next == NULL)
          index = -1;
      }

      return index;
    }

    
    /**
     * Public : print
     * 
     * Description:
     *      Prints the contents of a Vector to sdtout and an output file
     *      specified by the user
     * 
     * Params:
     *      ofstream  :  Object used to create and write to an output file
     * 
     * Returns:
     *      N/A
     */
    void print(ofstream &outfile)
    {
      Node * traverse = head;

      cout << '[';
      outfile << '[';
      
      while(traverse)
      {
        cout << traverse->data;
        outfile << traverse->data;

        if(traverse->next != nullptr)
        {
          cout << ", ";
          outfile << ", ";
        }
        
        traverse = traverse->next;
      }

      cout << ']' << endl << endl;
      outfile << ']' << endl << endl;
    }

    
    /**
     * Public : size
     * 
     * Description:
     *      Traverses the contens of a Vector to find how many values it contains
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int  :  Number of values in a Vector
     */
    int size()
    {
      int count = 0;

      Node * traverse = head;

      while(traverse)
      {
        count++;
        traverse = traverse->next;
      }

      return count;
    }
};

int main() 
{
  int x = 0;                 //Int to hold values popped from lists
  
  ofstream outfile;          //ofstream object for writing to output file
  outfile.open("test.out");  //Create and open output file for writing

  outfile << "Brett Smith" << endl << "Program 1" << endl << "2143 - OOP" << endl << "Spring 2023" << endl << endl;

  Vector v1;                 //Instance of a Vector created with the default constructor
  v1.pushFront(18);
  v1.pushFront(20);
  v1.pushFront(25);
  v1.pushRear(18);
  v1.pushRear(20);
  v1.pushRear(25);
  v1.print(outfile);

  int A[] = {11,25,33,47,51};  //Array used to fill a Vector
  Vector v2(A,5);              //Instance of a Vector created using an array
  v2.print(outfile);
  
  v2.pushFront(9);
  v2.inOrderPush(27);
  v2.pushRear(63);
  v2.print(outfile);

  v1.pushRear(v2);
  v1.print(outfile);

  x = v1.popFront();
  x = v1.popFront();
  x = v1.popFront();
  v1.print(outfile);
  cout << x << endl << endl;
  outfile << x << endl << endl;

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v1.print(outfile);
  cout << x << endl << endl;
  outfile << x << endl << endl;

  x = v2.popAt(3);
  v2.print(outfile);
  cout << x << endl << endl;
  outfile << x << endl << endl;

  x = v2.find(51);
  cout << x << endl << endl;
  outfile << x << endl << endl;

  x = v2.find(99);
  cout << x << endl << endl;
  outfile << x << endl << endl;

  Vector v3(v1);      //Instance of a Vector created from another Vector
  v3.print(outfile);

  v3.pushFront(v2);
  v3.print(outfile);

  Vector v4("input.dat");  //Instance of a Vector created by reading in data from a file
  v4.pushRear(v3);
  v4.print(outfile);

  outfile.close();  //Close output file once done writing
}
