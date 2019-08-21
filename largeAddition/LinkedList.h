// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
// PRECONDITIONS:                             *
//   Choice for ItemType implements 'cout'    *
//   as well as "==" operator                 *
//*********************************************

template <class ItemType>
class ListNode
{
  public:
    ItemType info;               // Node value
    ListNode<ItemType> *next;    // Pointer to the next node

    // Constructor
    ListNode (ItemType nodeValue)
    {     
        info = nodeValue;
        next = NULL;
    }
};

//*********************************************
// LinkedList class                           *
//*********************************************

template <class ItemType>
class LinkedList
{
private:
    ListNode<ItemType> *head;        // List head pointer
    ListNode<ItemType> *currentPos;  // Pointer to "current" list item
    int length;                      // Length

public:
    LinkedList();                                           // Constructor
    ~LinkedList();                                          // Destructor
    LinkedList( const LinkedList<ItemType>& anotherList );  // Copy constructor
    void operator= ( const LinkedList<ItemType>& );         // Assignment operator

    void appendNode(ItemType);
    void insertNode(ItemType);
    void deleteNode(ItemType);
    bool searchList(ItemType& item);
    
    int getLength();    
    void displayList();
	ItemType displayNode(int place);										//custom added for largeAddition program
    
    void resetList();             // Iterator operations
    ItemType getNextItem();        
    bool atEnd();
};

//**************************************************
// Constructor                                     *
// Initial list head pointer and length            *
//**************************************************
template <class ItemType>
LinkedList<ItemType>::LinkedList()    
{
   head = NULL;
   length = 0;
}

//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************

template <class ItemType>
void LinkedList<ItemType>::appendNode(ItemType newValue)
{
    ListNode<ItemType> *newNode, *nodePtr;

    // Allocate a new node & store newValue
    newNode = new ListNode<ItemType>(newValue);

    // If there are no nodes in the list
    // make newNode the first node
    if (head == NULL)
        head = newNode;
    else    // Otherwise, insert newNode
    {
        // Initialize nodePtr to head of list
        nodePtr = head;

        // Find the last node in the list
        while (nodePtr->next != NULL)
            nodePtr = nodePtr->next;

        // Insert newNode as the last node
        nodePtr->next = newNode;
    }
    length++;
}

//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head.          *
// Precondition: "cout" operator enabled for       *
// ItemType data type.                             *
//**************************************************

template <class ItemType>
void LinkedList<ItemType>::displayList()
{
    ListNode<ItemType> *nodePtr;

    nodePtr = head;
    while (nodePtr != NULL)
    {
        cout << nodePtr->info << ' ';
        nodePtr = nodePtr->next;
    }
    cout << endl;
}




//**************************************************
// displayNode shows the value stored in a node    *
// of the linked list pointed to by head.          *
// Precondition: "cout" operator enabled for       *
// ItemType data type.                             *
//**************************************************

template <class ItemType>
ItemType LinkedList<ItemType>::displayNode(int place)
{
    ListNode<ItemType> *nodePtr;
	ItemType output;
	int i = 0;

    nodePtr = head;
    while (i <= place)
		nodePtr = nodePtr->next;
	return nodePtr->info;
}




//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.  The node  *
// is inserted at the beginning of the list        *
//**************************************************

template <class ItemType>
void LinkedList<ItemType>::insertNode(ItemType newValue)
{
    ListNode<ItemType> *nodePtr;

    nodePtr = new ListNode<ItemType>(newValue);
    nodePtr->next = head;
    head = nodePtr;
    length++;
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class ItemType>
void LinkedList<ItemType>::deleteNode(ItemType searchValue)
{
    ListNode<ItemType> *nodePtr, *previousNode;

    // If the list is empty, do nothing.
    if (head == NULL)
        return;
    
    // Determine if the first node is the one.
    if (head->info == searchValue)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list
        nodePtr = head;

        // Skip all nodes whose value member is 
        // not equal to searchValue.
        while (nodePtr != NULL && nodePtr->info != searchValue)
        {    
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, 
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr != NULL)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }    
    }
    length--;
}

//**************************************************
// Linear search                                   *
// Post: If found, item's key matches an element's *
// key in the list and a copy of that element has  *
// been stored in item; otherwise, item is         *
// unchanged.  Return value is boolean to indicate *
// status of search.                               *
//**************************************************

template <class ItemType>
bool LinkedList<ItemType>::searchList(ItemType& item)
{
  bool moreToSearch;
  ListNode<ItemType>* nodePtr;
  
  nodePtr = head;                // Start search from head of list
  bool found = false;            // Assume value not found
  moreToSearch = (nodePtr != NULL);
  
  while (moreToSearch && !found)
  {
      if (item == nodePtr->info)
      {
         found = true;
         item = nodePtr->info;
      }
      else
      {
         nodePtr = nodePtr->next;
         moreToSearch = (nodePtr != NULL);
      }
   }
   return found;
}

//**************************************************
// Iterator reset function                         *
// Resets pointer of current item in list to the   *
// head of the list.                               *
//**************************************************

template <class ItemType>
void LinkedList<ItemType>::resetList()
// Post: Current position has been initialized.
{
    currentPos = head; 
}
 
//**************************************************
// Function: Gets the next element in list as 
//           referenced by currPtr
// Pre:  Current position is defined.
// Post: Current position is updated to next position.
//       item is a copy of element at current position.
//**************************************************
template <class ItemType>
ItemType LinkedList<ItemType>::getNextItem() 
{
  ItemType item;
  
  if (currentPos == NULL)   
    currentPos = head;            // Wrap if position is at end

  item = currentPos->info;        // Get item at current position
  currentPos = currentPos->next;  // Advance to next position
  
  return item;                    // Return item
} 

//**************************************************
// Observer function to return current list length *
//**************************************************
template <class ItemType>
int LinkedList<ItemType>::getLength()
{
   return length;
}

//**************************************************
// Observer function to determine if current       *
// is the end of the list                          *
//**************************************************
template <class ItemType>
bool LinkedList<ItemType>::atEnd()
{
    if (currentPos == NULL)
       return true;
    else
       return false;  
}

//**************************************************
// Copy Constructor                                *
//**************************************************
template<class ItemType>        
LinkedList<ItemType>::LinkedList( const LinkedList<ItemType>& anotherList )
{    
  ListNode<ItemType>* ptr1;
  ListNode<ItemType>* ptr2;

  if (anotherList.head == NULL)
    head = NULL;
  else
  {
    head = new ListNode<ItemType>(anotherList.head->info);
    ptr1 = anotherList.head->next;
    ptr2 = head;
    while (ptr1 != NULL)
    {
      ptr2->next = new ListNode<ItemType>(ptr1->info);
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
  }    
  length = anotherList.length;
}

//**************************************************
// Overloaded Assignment Operator                  *
//**************************************************
template<class ItemType>        
void LinkedList<ItemType>::operator=( const LinkedList<ItemType>& anotherList )
{       
  ListNode<ItemType>* ptr1;
  ListNode<ItemType>* ptr2;

  if (anotherList.head == NULL)
    head = NULL;
  else
  {
    head = new ListNode<ItemType>(anotherList.head->info);
    ptr1 = anotherList.head->next;
    ptr2 = head;
    while (ptr1 != NULL)
    {
      ptr2->next = new ListNode<ItemType>(ptr1->info);
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
  }    
  length = anotherList.length;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    ListNode<ItemType> *nodePtr, *nextNode;

    nodePtr = head;
    while (nodePtr != NULL)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

#endif
