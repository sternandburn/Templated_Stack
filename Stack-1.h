//Group D
//CS 355 - Data Structures and Algorithms
//Assignment 7
//This file contains both class headers and their functions
//Due: September 27, 2020

#ifndef STACK_H
#define STACK_H

#include <stdexcept>

using namespace std;

template <class T>
class Stack {

    struct node {
        T data;
        node* previous;
        int flag = 0;

        node(T data, node *previous) : data(data), previous(previous) {}
        T getData() const { return data; }

        node* getLink() const { return previous; }
    };

    node* copyList(node* l)
        {
            if (l == nullptr) {
                return nullptr;
            }
            return new node{l->getData(), copyList(l->getLink())};
        }

    node* head = nullptr;
    node* cursor;

public:
    Stack();
    Stack(Stack const& rhs);
    Stack& operator=(Stack const& rhs);
    void swap(Stack& other) noexcept;
    ~Stack();
    void push(const T& object);
    T pop();
    void printAtCursor();
    void print();
    bool isEmpty();
    void search(T query);
    void destructor();

};



//***************************************************
// Name: Stack
// Purpose: constructor
// Incoming: N/A
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
Stack<T>::Stack() = default;


//***************************************************
// Name: Stack
// Purpose: copy constructor
// Incoming: Stack<Type> s
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
Stack<T>::Stack(Stack const& rhs)
            : head(copyList(rhs.head))
            {}

template <class T>
void Stack<T>::swap(Stack& other) noexcept
{
    using std::swap;
    swap(head, other.head);
    cursor = head;
}

//***************************************************
// Name: copyList
// Purpose: Copylist for copying purposes
// Incoming: node* head
// Outgoing: node* to new list
// Return: N/A
//***************************************************


/*
//***************************************************
// Name: ~Stack
// Purpose: destructor
// Incoming: N/A
// Outgoing: N/A
// Return: N/A
//***************************************************
*/
template <class T>
Stack<T>::~Stack() {
    while (!isEmpty())
      pop();
}

//***************************************************
// Name: push
// Purpose: insert to list
// Incoming: Type inData
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void Stack<T>::push(const T& object) {
    head = new node(object, head);
    cursor = head;
}

//***************************************************
// Name: pop
// Purpose: remove item from list
// Incoming: N/A
// Outgoing: N/A
// Return: value
//***************************************************
template <class T>
T Stack<T>::pop() {
    T item;
    if (isEmpty())
    {
        cout << "Cannot get item from empty Stack" << endl;
    }
    else
    {
        node* temp = head;
        T item = head->getData();
        head = head->getLink();
        cursor = head;

        delete temp;
        return item;
    }

}

//***************************************************
// Name: isEmpty
// Purpose: check if list is empty
// Incoming: N/A
// Outgoing: N/A
// Return: head == nullptr
//***************************************************
template <class T>
bool Stack<T>::isEmpty() {
    return head == NULL;
}

//***************************************************
// Name: print
// Purpose: print the list to the screen
// Incoming: N/A
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void Stack<T>::print()
{
   node* temp = head;
   Stack<T> tempStack;

  while (temp != NULL)
  {
      tempStack.push(temp->getData());
      temp = temp->getLink();
  }
  temp = head;
    cout << "[ ";
    while (temp != NULL)
    {
      T item = tempStack.pop();
       if ((item == cursor->getData()))
        cout << "[" << item  << "]";	//changed tempStack.pop() to popped
      else
        cout << item << " ";
      temp = temp->getLink();
  }
    cout << " ]" << endl;
}

//***************************************************
// Name: search
// Purpose: search for what the user inputs
// Incoming: Type query
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void Stack<T>::search(T query)
{
  bool found=false;
  node* temp = head;
    while (temp != NULL)
  {
    if (temp->getData()==query)
    {
    found=true;
    }
        temp = temp->getLink();
    }
    if(found)
    {
      cout << query << " is in the Stack" << endl;
      cursor = temp;
    }
    else
    cout << query << " is NOT in the Stack" << endl;
}


//***************************************************
// Name: assignmentOperator
// Purpose:  overload the = operator
// Incoming: Node<Type> &right
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
Stack<T>& Stack<T>::operator=(Stack const& rhs)
{
    Stack tmp(rhs);            // make a copy using copy constructor.
    swap(tmp);                 // swap the tmp and this object
    cursor = head;
    return *this;
}

//***************************************************
// Name: destructor
// Purpose: test if the destructor works
// Incoming: N/A
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void Stack<T>::destructor(){
    this->~Stack();
}
//***************************************************
// Name: printAtCursor
// Purpose: print data at cursor
// Incoming: N/A
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void Stack<T>::printAtCursor()
{
  cout << cursor->getData() << endl;
}

//***************************************************
// Name: Menu
// Purpose: menu to show the options for the user to pick from
// Incoming: N/A
// Outgoing: N/A
// Return: N/A
//***************************************************

void Menu(){
     cout << "Enter + to push an item onto the Stack"  << endl
          << "Enter - to pop an item off the Stack"    << endl
          << "Enter ? to search for an item"           << endl
          << "Enter P to Print the list"               << endl
          << "Enter @ to Print the item at the cursor" << endl
          << "Enter 1 to test the copy constructor"    << endl
          << "Enter 2 to test the assignment operator" << endl
          << "Enter 3 to test the destructor"          << endl
          << "Enter M to Print the Menu"			   << endl
          << "Enter Q to Quit"                         << endl;
}

//***************************************************
// Name: assignmentOperator
// Purpose:  test the overloaded operator
// Incoming: Stack<Type> stack1
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void assignmentOperator(Stack<T> s1){
    Stack<T> s2;
    s2 = s1;
    cout << "Stack to assign: " ;
    s1.print();
    s1.pop();
    cout << "Stack after popping: " ;
    s1.print();
    cout << "New stack: " ;
    s2.print();
    cout << "New stack after assignment: " ;
    s2.print();
}

//***************************************************
// Name: copyConstructor
// Purpose: copy constructor to test it works
// Incoming: Stack<Type> stack1
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void copyConstructor(Stack<T> s1){
    Stack<T> s2 = Stack<T>(s1);
    cout << "Stack to copy: " ;
    s1.print();
    s1.pop();
    cout << "Stack after popping: " ;
    s1.print();
    cout << "New stack: " ;
    s2.print();
}

//***************************************************
// Name: loop
// Purpose: loop the class
// Incoming: Stack<Type> s
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
void loop(Stack<T> &s)
{
        string line;
        printf(">");
        readLine(s);
        loop(s);
}

//***************************************************
// Name: readLine
// Purpose: to work on the stack class
// Incoming: Stack<Type> s
// Outgoing: N/A
// Return: N/A
//***************************************************
template <class T>
  void readLine(Stack<T> &s)
  {
  char choice;
  T insert;
  T query;
  do
  {
    cin >> choice;
    switch (choice)
    {
      case '+': //INSERT ITEM
      cin >> insert;
      s.push(insert);
      break;
      case '-': //REMOVE ITEM
      s.pop();
      break;
      case '?': //SEARCH ITEM
      cin >> query;
      s.search(query);
      break;
      case 'P':
      case 'p': //PRINT LIST
      s.print();
      break;
      case '@': //PRINT AT CURSOR
      s.printAtCursor();
      break;
      case '1': //TEST COPY CONSTRUCTOR
      copyConstructor(s);
      break;
      case '2': //TEST ASSIGNMENT OPERATOR
      assignmentOperator(s);
      break;
      case '3': //TEST DESTRUCTOR
      s.destructor();
      break;
      case 'M':
      case 'm': //PRINT MENU
      Menu();
      break;
      case 'Q':
      case 'q': //QUIT THE PROGRAM
      exit(0);
      break;

      default: //INVALID CHOICE
      cout << "You have entered an invalid choice" << endl;
    }
  } while(cin.get() != '\n');

}


#endif
