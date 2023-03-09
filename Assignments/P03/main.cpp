/*****************************************************************************
*                    
*  Author:           Brett Smith
*  Email:            brettsmith578@gmail.com
*  Label:            P03
*  Title:            Program 3 - GraphViz Class
*  Course:           CMPS 2143-201 OOP
*  Semester:         Spring 2023
* 
*  Description:
*        This program creates a class that produces graphviz "dot" syntax.
*        It uses Nodes that hold data and styles and Edges with certain styles
*        to, in turn, print the graphviz syntax. Each Node and Edge can be stylized
*        with different attributes to create multiple looks. This program produces
*        syntax for a Linked List, Doubly Linked List, and a Binary Search Tree.
* 
*  Usage:
*        See methods within each class for explanation and implementation.
* 
*  Files:
*        main.cpp      : driver program
*        test.out      : output file created to print graphviz "dot" syntax
*****************************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;



/**
 * Attribue
 * 
 * Description:
 *      Creates a map of strings to strings to hold
 *      the attribute type and style for each Edge
 *      or Node created
 * 
 * Public Methods:
 *             Attribute()
 *      void   addAttribute(string key, string val)
 *      void   addAttributes(map<string, string> atts)
 *      friend ostream &operator<<(ostream &os, Attribute &e)
 * 
 * Private Methods:
 *      - N/A
 * 
 * Usage: 
 * 
 *      Attribute A;                                  //create instance of Attribute
 *      A.addAttribute("color", "red");               //add a single attribute
 *                                                    
 *                                                    //or
 *
 *      A.addAttributes(map<string, string> stuff)    //add a map of strings with
 *                                                    //multiple attributes
 */
class Attribute
{
  protected:
    map<string, string> att; // attributes

  public:
    //defualt constructor
    Attribute(){}

    
    /**
     * Public : addAttribute
     * 
     * Description:
     *      stores an attribute for a Node or
     *      Edge and att map
     * 
     * Params:
     *      string : location to store value
     *      string : value to be stored
     * 
     * Returns:
     *      N/A
     */
    void addAttribute(string key, string val)
    {
      att[key] = val;
    }
  
    
    /**
     * Public : addAttributes
     * 
     * Description:
     *      Adds attributes to a Node or Edge from
     *      a previously declared map
     * 
     * Params:
     *      map : map of strings
     * 
     * Returns:
     *      N/A
     */
    void addAttributes(map<string, string> atts)
    {
      for (auto const &x : atts)
      {
        cout << x.first << "=" << x.second << endl;
        att[x.first] = x.second;
      }
    }
  
    
    /**
     * Public : ostream &operator<<
     * 
     * Description:
     *      Loops through a map of Attributes and
     *      prints each key and value
     * 
     * Params:
     *      ostream   : ostream object used to print
     *      Attribute : instance of an Attribute
     * 
     * Returns:
     *      ostream : ostream object created to print items
     */
    friend ostream &operator<<(ostream &os, Attribute &e)
    {
      int i = 0;
      
      for (auto const &x : e.att)
      {
        os << x.first << "="
           << "\"" << x.second << "\"";
  
        if (i < e.att.size() - 1) {
          os << ", ";
        }
        
        i++;
      }
  
      return os;
    }
};



/**
 * Edge
 * 
 * Description:
 *      Creates an Edge that can be added between nodes
 *      of a linked list or binary search tree. Inherits
 *      from class Attribute to add attributes.
 * 
 * Public Methods:
 *      - N/A
 * 
 * Private Methods:
 *      - N/A
 * 
 * Usage: 
 * 
 *      Edge();       //creates default Edge with color
 *                    //black and arrowhead vee
 *
 *                    //or
 *
 *      Edge(0, 1);   //creates an edge between Node 0 and
 *                    //1 with defualt color and arrowhead
 *      
 */
class Edge : public Attribute
{
  //id of the which edge has been created
  int eid;

  public:
    //ints and strings to show direction edge is pointing
    int from, to;
    string nl, direction;

    //default constructor
    Edge()
    {
      att["color"] = "black";    // default color
      att["arrowhead"] = "vee"; // default arrow shape
    }

    //overloaded constructor allowing to overwrite
    //default attributes or add new ones
    Edge(string color, string arrow)
    {
      att["color"] = color;      // default color
      att["arrowhead"] = arrow; // default arrow shape
    }

    //overloaded constructor allowing to add
    //attributes to certain edges of a node
    Edge(int f, int t)
    {
      from = f;
      to = t;

      att["color"] = "black";
      att["arrowhead"] = "vee";
    }

    //overloaded constructor used for adding attributes
    //to edges that point from data to null
    Edge(int f, string n)
    {
      from = f;
      nl = n;

      att["color"] = "red";
      att["arrowhead"] = "vee";
    }

    //overloaded constructor used for adding attributes
    //to left and right edges of a binary search tree
    Edge(int f, int t, string dir)
    {
      from = f;
      to = t;
      direction = dir;

      att["color"] = "blue";
      att["arrowhead"] = "vee";
    }
};



/**
 * Node
 * 
 * Description:
 *      Creates a Node that holds data and default attributes.
 *      Attributes can be changed or added for each Node.
 * 
 * Public Methods:
 *      - N/A
 * 
 * Private Methods:
 *      - N/A
 * 
 * Usage: 
 * 
 *      Node();                           //creates instance of Node with default parameters
 *
 *                                        //or
 *
 *      Node(map<string, string> stuff);  //creates a Node from a map that already
 *                                        //contains multiple attributes
 *
 *                                        //or
 *
 *      Node(7);                          //creates Node with number 7 and default attributes
 *      
 */
class Node : public Attribute
{
  protected:
    //id to keep track of which Node goes with which edge
    int nid;

  public:
    //integer data to stor in Node
    int data;

    //defualt constructor
    Node()
    {
      att["color"] = "black"; // default color
      att["shape"] = "record";   // default arrow shape
      data = 0;
    }

    //overloaded constructor to create Node from
    //attributes from a created map
    Node(map<string,string> atts)
    {
      for (auto const &x : atts)
      {
        att[x.first] = x.second;
      }
    }

    //overloaded constructor to create a Node with
    //specified data and default attributes
    Node(int d)
    {
      att["color"] = "black";
      att["shape"] = "record";
      data = d;
    }
};



/**
 * GraphViz
 * 
 * Description:
 *      Creates an instance of a graphviz that then prints the
 *      graphviz "dot" syntax using specified data and attributes
 *      of each Node and Edge.
 * 
 * Public Methods:
 *      int    addNode()
 *      int    addNode(map<string,string> atts)
 *      int    addNode(int d)
 *      void   updateNode(int id, string key ,string value)
 *      void   addEdge(int f, int t)
 *      void   addEdge(int f, string n)
 *      void   addEdge(int f, int t, string dir)
 *      void   updateEdge(int id, string key, string value)
 *      void   printGraph(ostream &fout, string graphName="")
 *      friend ostream& operator<<(ostream& os, GraphViz& g)
 * 
 * Private Methods:
 *      - N/A
 * 
 * Usage: 
 * 
 *      GraphViz G("LL");                      //Create instance of GraphViz named "LL"
 *
 *      G.addNode(7);                          //add Node with value 7
 *                                             //and default attributes
 *
 *      G.addNode(11);                         //add Node with value 11
 *                                             //and default attributes
 *
 *      G.updateNode(0, "shape" , "star");     //change first Node's shape to star
 *
 *      G.addEdge(0, 1);                       //create an Edge between Node 0 and 1
 *
 *      G.updateEdge(0, "arrowhead", "crow");  //change Edge's arrow shape to crow
 *
 *      G.pringGraph;                          //print graphviz syntax to console and output
 *      
 */
class GraphViz
{
  //ID's for number of edges and nodes
  int edgeId;
  int nodeId;

  //vectors to hold the attributes of each edge and node
  vector<Edge> Edges;
  vector<Node> Nodes;

  //name of the graph to determine how it is printed
  string graphName;

  public:

    //default constructor
    GraphViz()
    {
      edgeId = 0;
      nodeId = 0;
      graphName = "foo";
    }

    //overloaded constructor allowing to pass in a graphName
    GraphViz(string name)
    {
      edgeId = 0;
      nodeId = 0;
      graphName = name;
    }


    
    /**
     * Public : addNode
     * 
     * Description:
     *      adds a node with default values to Nodes vector
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int : ID of created node
     */
    int addNode()
    {
      Nodes.push_back(Node());
      
      return Nodes.size() - 1;
    }


    
    /**
     * Public : addNode
     * 
     * Description:
     *      overloaded method that allows the ability to
     *      pass in a previously declared map of attributes
     * 
     * Params:
     *      map : map of strings holding attributes
     * 
     * Returns:
     *      int : ID of created node
     */
    int addNode(map<string,string> atts)
    {
      Nodes.push_back(Node(atts));
  
      return Nodes.size() - 1;
    }


  
    /**
     * Public : addNode
     * 
     * Description:
     *      overloaded method allowing to pass in the data
     *      to be stored in the node
     * 
     * Params:
     *      int : integer to store in the node
     * 
     * Returns:
     *      int : ID of created node
     */
    int addNode(int d)
    {
      Nodes.push_back(Node(d));

      return Nodes.size() - 1;
    }


    
    /**
     * Public : update Node
     * 
     * Description:
     *      gives the ability to add a new attribute to
     *      a node or change and existing attribute
     * 
     * Params:
     *      int    : ID of previously created node
     *      string : key of value to store or change
     *      string : value to be stored or changed
     * 
     * Returns:
     *      N/A
     */
    void updateNode(int id, string key ,string value)
    {
      Nodes[id].addAttribute(key, value);
    }


    
    /**
     * Public : addEdge
     * 
     * Description:
     *      gives ability to add a default edge from one node to another
     * 
     * Params:
     *      int : ID of first node
     *      int : ID of second node
     * 
     * Returns:
     *      N/A
     */
    void addEdge(int f, int t)
    {
      Edges.push_back(Edge(f, t));
    }


    
    /**
     * Public : addEdge
     * 
     * Description:
     *      add an edge from a node to null
     * 
     * Params:
     *      int    : ID of node
     *      string : tells if a node points to null
     * 
     * Returns:
     *      N/A
     */
    void addEdge(int f, string n)
    {
      Edges.push_back(Edge(f, n));
    }


    
    /**
     * Public : addEdge
     * 
     * Description:
     *      ability to add an edge going left or right for a binary search tree
     * 
     * Params:
     *      int    : ID of first node
     *      int    : ID of second node
     *      string : direction to point the edge
     * 
     * Returns:
     *      N/A
     */
    void addEdge(int f, int t, string dir)
    {
      Edges.push_back(Edge(f, t, dir));
    }


    
    /**
     * Public : updateEdge
     * 
     * Description:
     *      ability to add attributes to an edge or
     *      change attributes of an existing edge
     * 
     * Params:
     *      int    : ID of edge
     *      string : key of where to store value
     *      string : value to be stored
     * 
     * Returns:
     *      N/A
     */
    void updateEdge(int id, string key, string value)
    {
      Edges[id].addAttribute(key, value);
    }
    

    
    /**
     * Public : printGraph
     * 
     * Description:
     *      prints graphviz "dot" syntax based on the name of the graph
     *      can print for Linked List, Doubly Linked List, or Binary Search Tree
     * 
     * Params:
     *      ofstream : ofstream object to print to output file
     *      string   : name of the graph
     * 
     * Returns:
     *      N/A
     */
    void printGraph(ostream &fout, string graphName="")
    {
      if(graphName.size() == 0)
        graphName = this->graphName;

      
      if(graphName == "LL")
      {
        cout << "digraph " << graphName << "\n{\n";
        cout << "\trankdir=LR;" << endl;
        cout << "\tlabel=\"Linked List\"" << endl;
        cout << "\tNode [shape=record,color=black];" << endl << endl;

        fout << "digraph " << graphName << "\n{\n";
        fout << "\trankdir=LR;" << endl;
        fout << "\tlabel=\"Linked List\"" << endl;
        fout << "\tNode [shape=record,color=black];" << endl << endl;
        
        // loop over nodes and print them
        for(int i=0; i < Nodes.size(); i++)
        {
          cout << "\t" << i << " [label=\"{ <data> " << Nodes[i].data
               << " | <next> }\", " << Nodes[i] << "];"<< endl;

          fout << "\t" << i << " [label=\"{ <data> " << Nodes[i].data
               << " | <next> }\", " << Nodes[i] << "];"<< endl;
        }

        cout << endl << "\tnull [shape=circle, color=white];" << endl << endl;

        fout << endl << "\tnull [shape=circle, color=white];" << endl << endl;
  
        //loop over edges and print them
        for(int i=0; i < Edges.size(); i++)
        {
          if(Edges[i].nl != "null")
          {
            cout << "\t" << Edges[i].from << ":next:3 -> " << Edges[i].to 
                 << ":data [" << Edges[i] << "];" << endl;

            fout << "\t" << Edges[i].from << ":next:3 -> " << Edges[i].to 
                 << ":data [" << Edges[i] << "];" << endl;
          }
        }

        cout << "\t" << Edges.size() - 1 << ":next:3 -> null [" 
             << Edges[Edges.size()-1] <<"];" << endl;

        fout << "\t" << Edges.size() - 1 << ":next:3 -> null [" 
             << Edges[Edges.size()-1] <<"];" << endl;
        
        cout << "}\n" << endl;
        fout << "}\n" << endl;
      }

        
      else if(graphName == "DLL")
      {
        cout << "digraph " << graphName << "\n{\n";
        cout << "\trankdir=LR;" << endl;
        cout << "\tlabel=\"Doubly Linked List\"" << endl;
        cout << "\tNode [shape=record,color=black];" << endl << endl;

        fout << "digraph " << graphName << "\n{\n";
        fout << "\trankdir=LR;" << endl;
        fout << "\tlabel=\"Doubly Linked List\"" << endl;
        fout << "\tNode [shape=record,color=black];" << endl << endl;
        
        // loop over nodes and print them
        for(int i=0; i < Nodes.size(); i++)
        {
          cout << "\t" << i << " [label=\"{ <pre> | <data> " << Nodes[i].data
               << " | <next> }\", " << Nodes[i] << "];"<< endl;

          fout << "\t" << i << " [label=\"{ <pre> | <data> " << Nodes[i].data
               << " | <next> }\", " << Nodes[i] << "];"<< endl;
        }

        cout << endl << "\tnull [shape=circle, color=white];" << endl << endl;

        fout << endl << "\tnull [shape=circle, color=white];" << endl << endl;
  
        //loop over edges and print them
        for(int i=0; i < Edges.size(); i++)
        {
          if(i == 0)
          {
            cout << "\t" << i << ":pre:n -> null [" << Edges[i] << "];" << endl;

            cout << "\t" << Edges[i].from << ":next:3 -> " << Edges[i].to 
                 << ":data [" << Edges[i] << "];" << endl;

            fout << "\t" << i << ":pre:n -> null [" << Edges[i] << "];" << endl;

            fout << "\t" << Edges[i].from << ":next:3 -> " << Edges[i].to 
                 << ":data [" << Edges[i] << "];" << endl;
          }

          else if(Edges[i].nl != "null")
          {
            cout << "\t" << Edges[i].from << ":pre:3 -> " << Edges[i - 1].from 
                 << ":data [" << Edges[i] << "];" << endl;
            
            cout << "\t" << Edges[i].from << ":next:3 -> " << Edges[i].to 
                   << ":data [" << Edges[i] << "];" << endl;

            fout << "\t" << Edges[i].from << ":pre:3 -> " << Edges[i - 1].from 
                 << ":data [" << Edges[i] << "];" << endl;
            
            fout << "\t" << Edges[i].from << ":next:3 -> " << Edges[i].to 
                   << ":data [" << Edges[i] << "];" << endl;
          }
        }

        cout << "\t" << Edges.size() - 1 << ":pre:3 -> " << Edges[Edges.size() - 2].from 
                 << ":data [" << Edges[Edges.size() - 1] << "];" << endl;

        fout << "\t" << Edges.size() - 1 << ":pre:3 -> " << Edges[Edges.size() - 2].from 
                 << ":data [" << Edges[Edges.size() - 1] << "];" << endl;
        
        cout << "\t" << Edges.size() - 1 << ":next:3 -> null [" 
             << Edges[Edges.size()-1] <<"];" << endl;

        fout << "\t" << Edges.size() - 1 << ":next:3 -> null [" 
             << Edges[Edges.size()-1] <<"];" << endl;
        
        cout << "}\n" << endl;
        fout << "}\n" << endl;
      }

        
      else if(graphName == "BST")
      {
        cout << "digraph " << graphName << "\n{\n";
        cout << "\tbgcolor=cyan;" << endl;
        cout << "\tlabel=\"Binary Search Tree\"" << endl;
        cout << "\tNode [shape=record, color=black];" << endl << endl;

        fout << "digraph " << graphName << "\n{\n";
        fout << "\tbgcolor=cyan;" << endl;
        fout << "\tlabel=\"Binary Search Tree\"" << endl;
        fout << "\tNode [shape=record, color=black];" << endl << endl;
        
        // loop over nodes and print them
        for(int i=0; i < Nodes.size(); i++)
        {
          cout << "\t" << i << " [label=\"{ <data> " << Nodes[i].data
               << " | { <left> | <right> }}\", " << Nodes[i] << "];"<< endl;

          fout << "\t" << i << " [label=\"{ <data> " << Nodes[i].data
               << " | { <left> | <right> }}\", " << Nodes[i] << "];"<< endl;
        }

        cout << endl;
  
        //loop over edges and print them
        for(int i=0; i < Edges.size(); i++)
        {
          if(Edges[i].direction == "left")
          {
            cout << "\t" << Edges[i].from << " :left -> " << Edges[i].to
                 << " [" << Edges[i] << "];" << endl;

            fout << "\t" << Edges[i].from << " :left -> " << Edges[i].to
                 << " [" << Edges[i] << "];" << endl;
          }

          else if(Edges[i].direction == "right")
          {
            cout << "\t" << Edges[i].from << " :right -> " << Edges[i].to
                 << " [" << Edges[i] << "];" << endl;

            fout << "\t" << Edges[i].from << " :right -> " << Edges[i].to
                 << " [" << Edges[i] << "];" << endl;
          }
        }
        
        cout << "}\n" << endl;
        fout << "}\n" << endl;
      }
    }


    
    /**
     * Public : ostream &operator<<
     * 
     * Description:
     *      Overloads "<<" to print items of the graphviz class
     *      without needing a print method
     * 
     * Params:
     *      ostream  : ostream object used to print to stdout
     *      GraphViz : GraphViz object to be printed
     * 
     * Returns:
     *      ostream : ostream object used for printing
     */
    friend ostream& operator<<(ostream& os, GraphViz& g)
    {
      for(int i=0; i < g.Nodes.size(); i++)
      {
        os << i << " " << g.Nodes[i] << endl;
      }
      
      for(int i=0; i < g.Edges.size(); i++)
      {
        os << i << " " << g.Edges[i] << endl;
      }
      
     return os; 
    }
};



int main()
{
  //fstream object for writing to output file
  fstream fout;
  fout.open("test.out");

  //write heading to output file
  fout << "Brett Smith \n3/08/2023 \nSpring 2023" << endl << endl;

  //instance of GraphViz
  GraphViz G("LL");

  //add Nodes to G
  G.addNode(74);
  G.addNode(11);
  G.addNode(27);
  G.addNode(123);

  //add Edges to G
  G.addEdge(0, 1);
  G.addEdge(1, 2);
  G.addEdge(2, 3);
  G.addEdge(3, "null");

  //change attributes of G's Edges
  G.updateEdge(0, "arrowtail", "dot");
  G.updateEdge(0, "color", "purple");
  G.updateEdge(0, "dir", "both");
  G.updateEdge(0, "tailclip", "false");
  G.updateEdge(1, "arrowhead", "crow");
  G.updateEdge(2, "arrowhead", "icurve");
  G.updateEdge(2, "dir", "one");
  G.updateEdge(3, "dir", "none");
  G.updateEdge(3, "arrowtail", "dot");

  //change attributes of G's Nodes
  G.updateNode(0, "color", "orange");
  G.updateNode(2, "color", "blue");
  G.updateNode(1, "shape", "signature");
  G.updateNode(3, "shape", "star");
  G.updateNode(3, "color", "purple");

  //print G to console and output
  G.printGraph(fout);


  //instance of GraphViz
  GraphViz G2("DLL");

  //add Nodes to G2
  G2.addNode(7);
  G2.addNode(8);
  G2.addNode(9);

  //add Edges to G2
  G2.addEdge(0, 1);
  G2.addEdge(1, 2);
  G2.addEdge(2, "null");
  
  //change attributes of G2's Edges
  G2.updateEdge(0, "arrowtail", "dot");
  G2.updateEdge(0, "color", "purple");
  G2.updateEdge(0, "dir", "both");
  G2.updateEdge(0, "tailclip", "false");
  G2.updateEdge(1, "dir", "both");
  G2.updateEdge(2, "dir", "both");
  G2.updateEdge(2, "arrowtail", "dot");

  //change attributes of G2's Nodes
  G2.updateNode(0, "color", "orange");
  G2.updateNode(0, "shape", "invhouse");
  G2.updateNode(1, "shape", "doublecircle");
  G2.updateNode(2, "color", "blue");

  //print G2 to console and output file
  G2.printGraph(fout);


  //instance of GraphViz
  GraphViz G3("BST");

  //add Nodes to G3
  G3.addNode(115);
  G3.addNode(57);
  G3.addNode(28);
  G3.addNode(5);
  G3.addNode(7);
  G3.addNode(2);
  G3.addNode(8);

  //add Edges to G3
  G3.addEdge(0, 1, "left");
  G3.addEdge(0, 2, "right");
  G3.addEdge(1, 3, "left");
  G3.addEdge(1, 4, "right");
  G3.addEdge(2, 5, "left");
  G3.addEdge(2, 6, "right");

  //change attributes of G3's Edges
  G3.updateEdge(0, "color", "magenta");
  G3.updateEdge(1, "color", "purple");
  G3.updateEdge(0, "arrowhead", "diamond");
  G3.updateEdge(1, "arrowhead", "inv");
  G3.updateEdge(2, "arrowhead", "lcrow");
  G3.updateEdge(3, "arrowhead", "rcrow");
  G3.updateEdge(4, "arrowhead", "linv");
  G3.updateEdge(5, "arrowhead", "oinv");

  //print G3 to console and output file
  G3.printGraph(fout);

  //close output file
  fout.close();
}