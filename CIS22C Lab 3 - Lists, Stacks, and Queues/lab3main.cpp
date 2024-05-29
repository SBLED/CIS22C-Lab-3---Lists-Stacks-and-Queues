/* CIS-22C
*  Lab 3 - Lists, Stacks, and Queues
*  Spencer Bledsoe
*/
#include "Currency.h"
#include "Dollar.h"
#include "LinkNode.h"
#include "SinglyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;

void Welcome();
void Goodbye();

int main()
{
    Welcome();

    double initValArr[20] = { 57.12,23.44,87.43,68.99,111.22,44.55,77.77,
                              18.36,543.21,20.21,345.67,36.18,48.48,101.00,
                              11.00,21.00, 51.00,1.00,251.00,151.00 };
    Currency* currArray[20];
    for (int i = 0; i < 20; i++) {
        currArray[i] = new Dollar(initValArr[i]);
    }

    //Create SinglyLinkedList
    SinglyLinkedList* sLinkList = new SinglyLinkedList();
    //Create Stack
    Stack labStack;
    //Create Queue
    Queue labQueue;

    for (int i = 0; i < 20; i++) {
        delete currArray[i];
    }
    //////////////////////  FOR LINKED LIST     ////////////////////////////////
    //add first 7 array obj into linkedlist (reverse order: 7th element = head, 1st = end)
    int j = 6;
    for (int i = 0; i < 7; i++) { // Check if i must be 6 or 7
        sLinkList->addCurrency(*currArray[j], i);
        j--;
    }

    //Search for $87.43, print result
    Dollar srchCurr1 = 87.43;
    cout << "Search SinglyLinkedList for $";
    srchCurr1.print();
    cout << " Result index : " << sLinkList->findCurrency(srchCurr1) << endl;

    // Search for $44.56, print result
    Dollar srchCurr2 = 44.56;
    cout << "Search SinglyLinkedList for $";
    srchCurr2.print();
    cout << " Result index : " << sLinkList->findCurrency(srchCurr2) << endl;

    //Search for and remove node containing $111.22
    Dollar srchCurr3 = 111.22;
    sLinkList->removeCurrency(srchCurr3);
    
    //Remove node at index 2
    sLinkList->removeCurrency(2);
    
    //Print list contents
    cout << "List contents: " << sLinkList->printList() << endl;
    
    //Add next 4 obj (9-12) such that their index in the linkedlist is calculated as (index in array % 5)
    for (int i = 8; i < 12; i++) {
        sLinkList->addCurrency(*currArray[i], i % 5);
    }
    
    //Remove object at index (countCurrency % 6)
    sLinkList->removeCurrency(sLinkList->getCount() % 6);
    
    //Remove object at index (countCurrency / 7)
    sLinkList->removeCurrency(sLinkList->getCount() / 7);

    //Print contents of list.
    cout << "List contents: " << sLinkList->printList() << endl;
    
    delete sLinkList;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////  FOR STACK   //////////////////////////////////////////////
    //Push 7 objects starting from array index 13, onwards to the stack
    // Peek top of stack and print result
    // Perform 3 pops in succession
    // Print contents of stack
    // Push 5 more objects from the start of the objects array to the stack
    // Pop twice in succession
    // Print contents of stack
    //////////////////////////////////////////////////////////////////////////////////

    //////////////////////  FOR QUEUE   //////////////////////////////////////////////
    //Enqueue the seven (7) objects at odd indexes starting from index 5 in the array.
    //Peek the front and end of the queue - print the results.
    //Perform two(2) dequeues in succession.
    //Print the contents of the queue.
    //Enqueue five(5) more objects from the index 10 in the array.
    //Dequeue three times in succession.
    //Print the contents of the queue.
    //////////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < 20; i++) {
        delete currArray[i];
    }

    Goodbye();
    system("pause");
    return 0;
}

void Welcome() {
    cout << "Lab 3 - Lists, Stacks, and Queues\n" << "Solution by Spencer Bledsoe\n" << endl;
    return;
}

void Goodbye() {
    cout << "Exiting program..." << endl;
    return;
}