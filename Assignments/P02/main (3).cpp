/*****************************************************************************
*                    
*  Author:           Brett Smith
*  Email:            brettsmith578@gmail.com
*  Label:            P02
*  Title:            Program 2 - MyVector Class 2
*  Course:           CMPS 2143-201 OOP
*  Semester:         Spring 2023
* 
*  Description:
*        This program uses a linked list based MyVector class to create instances of
*        MyVectors. These Vectors hold integers and are able to grow and shrink without
*        having to copy values into newly allocated memory. An instance of a Vector can
*        be initialized using multiple push methods described below. There are also methods
*        that can remove items from Vector using different techniques. Each Vector can also
*        be printed using the print() method which dispalys data to the console and to an
*        output file. This program extends upon Program 1 by including overloaded operator
*        methods (<<, [], +, -, *, /, =, ==). Examples: print Vectors wihtout a print method,
*        add values to MyVectors, subtract values, multiply values, divide values, and check
*        for equality.
* 
*  Usage:
*        See methods in class Vector to see how to create Vectors and add, remove,
*        and print data in Vectors.
* 
*  Files:
*        main.cpp      : driver program
*        output.txt    : output file created to print Vector data to
*****************************************************************************/

#include <iostream>
#include <fstream>

//declaration of Infinity
#define INF 1000000000

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
 * MyVector
 * 
 * Description:
 *      This class creates instances of linked list based Vectors that hold ints then
 *      uses multiple methods to add, remove, and print data contained in the Vectors
 * 
 * Public Methods:
 *      void             init()
 *                       MyVector()
 *                       MyVector(int * A, int size)
 *                       MyVector(string FileName)
 *                       MyVector(const MyVector &other)
 *      void             pushFront(int val)
 *      void             pushFront(MyVector &other)
 *      void             pushRear(int val)
 *      void             pushRear(MyVector &other)
 *      void             pushAt(int loc,int val)
 *      void             inOrderPush(int val)
 *      int              popFront()
 *      int              popRear()
 *      int              popAt(int loc)
 *      int              find(int val)
 *      void             print(ofstream &outfile)
 *      int              sizeOf()
 *      void             sortList()
 *      void             destroy()
 *      friend ostream   &operator<<(ostream &os, const MyVector &v)
 *      friend ofstream  &operator<<(ofstream &of, const MyVector &v)
 *      MyVector         operator+(const MyVector &rhs)
 *      MyVector         operator-(const MyVector &other)
 *      MyVector         operator*(const MyVector &rhs)
 *      MyVector         operator/(const MyVector &other)
 *      int              &operator[](int loc)
 *      MyVector         &operator=(const MyVector &rhs)
 *      bool             operator==(const MyVector &other)
 * 
 * Private Methods:
 *      Node             *_find(int location)
 * 
 * Usage: 
 * 
 *      int arr[] = {1, 2, 3};    //Create an array with values
 *      MyVector v(arr, 3);       //Create an instance of a Vector and
 *                                //pass in the array and its size
 *
 *      v.pushFront(0);           //Add 0 to the front of the Vector
 *      v.pushRear(4);            //Add 4 to the rear of the Vector
 *      v.popAt(2);               //Remove the value at index 2
 *      v.print(outfile);         //Print the values in the Vector to 
 *                                //stdout and an outfile created in main
 *      
 */
class MyVector
{
  private:
    Node * head;      //head and tail to keep track
    Node * tail;      //of front and back of list

    bool sorted;      //tells if list is sorted or not
    int size;         //int to keep track of list sizes
    string fileName;  //string used to create Vectors from input files


    /**
     * Private : *_find
     * 
     * Description:
     *      Creates a temporary Node to traverse the Vector and
     *      find a value at a given index. (Borrowed from Dr.
     *      Griffin's 2143_vector_discussion_Spring_23 code)
     * 
     * Params:
     *      int    :  index of the value to be found
     * 
     * Returns:
     *      Node*  :  the temporary Node with the value at the given location
     */
    Node *_find(int location)
    {
      Node *traverse = head;
  
      while (traverse && location--)
      {
        traverse = traverse->next;
      }
      
      return traverse;
    }

  public:

    /**
     * Public : init
     * 
     * Description:
     *      Initializes the values of a newly created and empty Vector
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    void init()
    {
      head = tail = nullptr;
      sorted = 0;
      size = 0;
      fileName = "";
    }


    /**
     * Public : MyVector
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
    MyVector()
    {
      init();
    }

    
    /**
     * Public : MyVector
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
    MyVector(int * A, int size)
    {
      init();

      for(int i = 0; i < size; i++)
        pushRear(A[i]);
    }

    
    /**
     * Public : MyVector
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
    MyVector(string FileName)
    {
      init();
      
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
     * Public : MyVector
     * 
     * Description:
     *      Overloaded Vector constructor that creates a Vector
     *      with the data contained in another Vector
     * 
     * Params:
     *      const MyVector  :  Address of another Vector previously declared
     * 
     * Returns:
     *      N/A
     */
    MyVector(const MyVector &other)
    {
      init();
      
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
     *      Adds a value to the front of a Vector and increments its size
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

      size++;
    }

    
    /**
     * Public : pushFront
     * 
     * Description:
     *      Adds entire other.MyVector to the front of this.MyVector
     *      and increments this.MyVector's size
     * 
     * Params:
     *      MyVector  :  Address of another Vector previously Declared
     * 
     * Returns:
     *      N/A
     */
    void pushFront(const MyVector &other)
    {
      int s = other.sizeOf();
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
     *      Adds a value to the rear of a Vector and increments its size
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

      size++;
    }

    
    /**
     * Public : pushRear
     * 
     * Description:
     *      Adds entire other.MyVector to the rear of this.MyVector
     *      and increments this.MyVector's size
     * 
     * Params:
     *      MyVector  :  Address of another Vector previously declared
     * 
     * Returns:
     *      N/A
     */
    void pushRear(MyVector &other)
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
     *      and increments its size
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
      int s = this->sizeOf();
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

      size++;
    }

    
    /**
     * Public : inOrderPush
     * 
     * Description:
     *      If a list is not sorted it sorts the list, then adds the value
     *      to the Vector in numerical order and increments its size
     * 
     * Params:
     *      int  :  Integer to be added
     * 
     * Returns:
     *      N/A
     */
    void inOrderPush(int val)
    {
      if(head && !sorted)
        sortList();

      else if(head == nullptr || val < head->data)
        pushFront(val);

      // else if(val < head->data)
      //   pushFront(val);

      else if(val > tail->data)
        pushRear(val);

      else
      {
        Node * temp = new Node(val);
        Node * traverse = head;

        while(traverse->next && traverse->next->data < temp->data)
        {
          traverse = traverse->next;
        }

        // if(traverse->next == nullptr)
        //   pushRear(val);

        //else
        //{
          temp->next = traverse->next;
          traverse->next = temp;
        //}
        size++;
      }
    }

    
    /**
     * Public : popFront
     * 
     * Description:
     *      Deletes the value that is in front of the Vector,
     *      decrements the Vector's size, and returns the value
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

      size--;

      return temp;
    }

    
    /**
     * Public : popRear
     * 
     * Description:
     *      Deletes the value that is at the rear of the Vector,
     *      decrements the Vector's size, and returns the value
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

      size--;

      return temp;
    }

    
    /**
     * Public : popAt
     * 
     * Description:
     *      Deletes a value at a specified index of the Vector,
     *      decrements the Vector's size, and returns the value
     * 
     * Params:
     *      int  :  Index of value to be removed
     * 
     * Returns:
     *      int  :  Integer removed from Vector
     */
    int popAt(int loc)
    {
      int s = this->sizeOf();
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

        size--;
      }

      return temp;
    }

    
    /**
     * Public : find
     * 
     * Description:
     *      Finds a specified value in the Vector (if it exists) and returns the index.
     *      Otherwise, it returns -1 if the value is not in the Vector
     * 
     * Params:
     *      int  :  Integer to be found within the Vector
     * 
     * Returns:
     *      int  :  Index of specified value
     */
    int find(int val)
    {
      int index = 0;

      if(head == nullptr)
        index = -1;

      else
      {
        Node * traverse = head;

        while(traverse && traverse->data != val)
        {
          traverse = traverse->next;
          index++;
        }

        if(traverse == nullptr)
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
     * Public : sizeOf() const
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
    int sizeOf() const
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


    /**
     * Public : sortList
     * 
     * Description:
     *      Takes a list that has not been sorted and arranges
     *      the list in ascending order (Borrowed from Dr. Griffin's
     *      Vector starter code)
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    void sortList() 
    {
      Node* newFront = head;
      
      while (newFront->next)
      {
        Node* smallest = newFront;
        Node* current = newFront;
        int   minimum = INF;
        
        while (current)
        {
          if (current->data < minimum)
          {
            smallest = current;
            minimum = current->data;
          }
          
          current = current->next;
        }
        
        smallest->data = newFront->data;
        newFront->data = minimum;
        newFront = newFront->next;
      }

      sorted = true;
    }


    /**
     * Public : destroy
     * 
     * Description:
     *      Deletes values stroed in a Vector. (Borrowed
     *      from Dr. Griffin's 02-List_Based_Queue code)
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    void destroy()
    {
        Node *prev = head;
        Node *curr = head;

        while (curr)
        {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        head = tail = nullptr;
    }


    /**
     * Public : operator<<
     * 
     * Description:
     *      Overloaded operator function that allows the user to print a Vector to
     *      the console using "cout << V;" instead of using a seperate print method
     * 
     * Params:
     *      ostream       :  address of an ostream object
     *      const Vector  :  address of the Vector to be printed
     * 
     * Returns:
     *      ostream  :  ostream object being overloaded
     */
    friend ostream &operator<<(ostream &os, const MyVector &v)
    {
      Node * traverse = v.head;

      os << "[";
      
      while(traverse)
      {
        os << traverse->data;
        if(traverse->next)
          os << ", ";

        traverse = traverse->next;
      }

      os << "]";
      
      return os;
    }


    /**
     * Public : operator<<
     * 
     * Description:
     *      Overloaded operator function that allows the user to print a Vector to an
     *      output file using "outfile << V;" instead of using a seperate print method
     * 
     * Params:
     *      ofstream      :  address of an ofstream object
     *      const Vector  :  address of the Vector to be printed
     * 
     * Returns:
     *      ofstream  :  ofstream object being overloaded
     */
    friend ofstream &operator<<(ofstream &of, const MyVector &v)
    {
      Node * traverse = v.head;

      of << "[";
      
      while(traverse)
      {
        of << traverse->data;
        if(traverse->next)
          of << ", ";

        traverse = traverse->next;
      }

      of << "]";
      
      return of;
    }


    /**
     * Public : operator+
     * 
     * Description:
     *      Overloaded '+' operator function that finds the shorter and longer
     *      of the two Vectors then adds the values together until the end
     *      of the shorter list is reached and leaves the rest of the values
     *      of the longer list the same. (Borrowed from Dr. Griffin's 
     *      2143_vector_discussion_Spring_23)
     * 
     * Params:
     *      const MyVector  :  Address of rhs.MyVector to add values with this.MyVector
     *      
     * 
     * Returns:
     *      MyVector  :  Address of this.MyVector in which the added values were stored
     */
    MyVector operator+(const MyVector &rhs)
    {
      MyVector V;
      Node *shorter;
      Node *longer;
      
      if (rhs.size < this->size)
      {
        shorter = rhs.head;
        longer = this->head;
      } 
      
      else
      {
        longer = rhs.head;
        shorter = this->head;
      }
      
      while (shorter)
      {
        V.pushRear(shorter->data + longer->data);
        shorter = shorter->next;
        longer = longer->next;
      }

      while (longer)
      {
      V.pushRear(longer->data);
      longer = longer->next;
      }

      return V;
    }


    /**
     * Public : operator-
     * 
     * Description:
     *      Overloaded '-' operator function that finds the shorter and longer
     *      of the two Vectors then subtracts the values until the end
     *      of the shorter list is reached and leaves the rest of the
     *      values of the longer list the same. (Borrowed from Dr. Griffin's 
     *      2143_vector_discussion_Spring_23)
     * 
     * Params:
     *      const MyVector  :  Address of other.MyVector to subtract values with this.MyVector
     *      
     * 
     * Returns:
     *      MyVector  :  Address of the this.MyVector in which the subtracted values were stored
     */
    MyVector operator-(const MyVector &other)
    {
      MyVector V;
      Node *lhs = this->head;
      Node *rhs = other.head;
      Node *rest;
     
  
      while (lhs && rhs)
      {
        V.pushRear(lhs->data - rhs->data);
        lhs = lhs->next;
        rhs = rhs->next;
      }
      
      if(rhs)
      {
        rest = rhs;
      }
      
      else
      {
        rest = lhs;
      }
      
      while (rest)
      {
        V.pushRear(rest->data);
        rest = rest->next;
      }
      
      return V;
    }


     /**
     * Public : operator*
     * 
     * Description:
     *      Overloaded '*' operator function that finds the shorter and longer
     *      of the two Vectors then multiplies the values together until the end
     *      of the shorter list is reached and leaves the rest of the values
     *      of the longer list the same. (Based on Dr. Griffin's 
     *      2143_vector_discussion_Spring_23 overloaded '+' method)
     * 
     * Params:
     *      const MyVector  :  Address of rhs.MyVector to multiply values with this.MyVector
     *      
     * 
     * Returns:
     *      MyVector  :  Address of the this.MyVector in which the multiplied values were stored
     */
    MyVector operator*(const MyVector &rhs)
    {
      MyVector V;
      Node *shorter;
      Node *longer;
      
      if (rhs.size < this->size)
      {
        shorter = rhs.head;
        longer = this->head;
      } 
      
      else
      {
        longer = rhs.head;
        shorter = this->head;
      }
      
      while (shorter)
      {
        V.pushRear(shorter->data * longer->data);
        shorter = shorter->next;
        longer = longer->next;
      }

      while (longer)
      {
      V.pushRear(longer->data);
      longer = longer->next;
      }

      return V;
    }


    /**
     * Public : operator/
     * 
     * Description:
     *      Overloaded '/' operator function that finds the shorter and longer
     *      of the two Vectors then divides the values until the end
     *      of the shorter list is reached and leaves the rest of the
     *      values of the longer list the same. (Based on Dr. Griffin's 
     *      2143_vector_discussion_Spring_23 overloaded '-' method)
     * 
     * Params:
     *      const MyVector  :  address of other.MyVector to divide values with this.MyVector
     *      
     * 
     * Returns:
     *      MyVector  :  Address of the this.MyVector in which the divided values were stored
     */
    MyVector operator/(const MyVector &other)
    {
      MyVector V;
      Node *lhs = this->head;
      Node *rhs = other.head;
      Node *rest;
     
  
      while (lhs && rhs)
      {
        V.pushRear(lhs->data / rhs->data);
        lhs = lhs->next;
        rhs = rhs->next;
      }
      
      if(rhs)
      {
        rest = rhs;
      }
      
      else
      {
        rest = lhs;
      }
      
      while (rest)
      {
        V.pushRear(rest->data);
        rest = rest->next;
      }
      
      return V;
    }


    /**
     * Public : operator[]
     * 
     * Description:
     *      Overloaded '[]' operator function that finds the value
     *      at a specified index in a Vector and returns the value.
     * 
     * Params:
     *      int  :  Integer index of the value to be found
     *      
     * 
     * Returns:
     *      int  :  Integer value at the specified index
     */
     int &operator[](int loc)
     {
       Node * temp = _find(loc);
       return temp->data;
     }


    /**
     * Public : operator=
     * 
     * Description:
     *      Overloaded '=' operator function that adds values from
     *      rhs.MyVector to this.MyVector
     * 
     * Params:
     *      const MyVector  :  address of rhs.MyVector to be added to this.MyVector
     *      
     * 
     * Returns:
     *      MyVector  :  address of this.MyVector where values were added
     */
     MyVector &operator=(const MyVector &rhs)
     {
       if(this == &rhs)
       {
         return *this;
       }

       if(head)
       {
         this->destroy();
       }

       Node * traverse = rhs.head;

       while(traverse)
        {
          this->pushRear(traverse->data);
          traverse = traverse->next;
        }

       return *this;
     }


    /**
     * Public : operator==
     * 
     * Description:
     *      Overloaded '==' operator function that checks if
     *      two seperate Vectors are equal to each other.
     * 
     * Params:
     *      const MyVector  :  Address of other.MyVector to compare with this.MyVector
     *      
     * 
     * Returns:
     *      bool  :  0 (false) if Vectors not equal or 1 (true) if Vectors are equal
     */
    bool operator==(const MyVector &other)
    {
      if(this == &other)
      {
        return true;
      }

      else if(this->size != other.size)
      {
        return false;
      }

      else
      {
        Node * lhs = this->head;
        Node * rhs = other.head;

        while(lhs && rhs)
        {
          if(lhs->data != rhs->data)
          {
            return false;
          }

          lhs = lhs->next;
          rhs = rhs->next;
        }
      }

      return true;
    }
};


int main() 
{
  int a1[] = { 1, 2, 3, 4, 5 };  //integer arrays used
  int a2[] = { 10, 20, 30 };     //to declare MyVectors
  
  MyVector v1(a1,5);
  MyVector v2(a2,3);
  
  ofstream outfile;            //ofstream object created to print to output.txt
  outfile.open("output.txt");  //output file created for writing to

  outfile << "Brett Smith" << endl << "Program 2" << endl << "2143 - OOP" << endl << "Spring 2023" << endl << endl;
  
  cout << v1[2] << endl;
  outfile << v1[2] << endl;
  // writes out 3 to console and output file
  
  v1[4] = 9;
  // v1 now = [1,2,3,4,9]
  
  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.
  
  outfile << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.
  
  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  outfile << v3 << endl;
  // writes out [11,22,33,4,9] to console and output file.
  
  v3 = v1 - v2;
  cout << v3 << endl;
  outfile << v3 << endl;
  // writes out [-9,-18,-27,4,9] to console and output file.
  
  v3 = v2 - v1;
  cout << v3 << endl;
  outfile << v3 << endl;
  // writes out [9,18,27,4,9] to console and output file.
  
  v3 = v2 * v1;
  cout << v3 << endl;
  outfile << v3 << endl;
  // writes out [10,40,90,4,9] to console and output file.
  
  v3 = v1 * v2;
  cout << v3 << endl;
  outfile << v3 << endl;
  // writes out [10,40,90,4,9] to console and output file.
  
  v3 = v1 / v2;
  cout << v3 << endl;
  outfile << v3 << endl;
  // writes out [0,0,0,4,9] to console and output file.
  
  v3 = v2 / v1;
  cout << v3 << endl;
  outfile << v3 << endl;
  // writes out [10,10,10,4,9] to console and output file.
  
  cout << (v2 == v1) << endl;
  outfile << (v2 == v1) << endl;
  // writes 0 to console (false) and output file.
  
  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  outfile << (v4 == v1) << endl;
  // writes 1 to console (true) and output file.
}