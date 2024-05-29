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

    double initValArr[20] = { 
        57.12,    //Index 0
        23.44,    //Index 1
        87.43,    //Index 2
        68.99,    //Index 3
        111.22,   //Index 4
        44.55,    //Index 5
        77.77,    //Index 6
        18.36,    //Index 7
        543.21,   //Index 8
        20.21,    //Index 9
        345.67,   //Index 10
        36.18,    //Index 11
        48.48,    //Index 12
        101.00,   //Index 13
        11.00,    //Index 14
        21.00,    //Index 15
        51.00,    //Index 16
        1.00,     //Index 17
        251.00,   //Index 18
        151.00 }; //Index 19

    Currency* currArray[20];
    for (int i = 0; i < 20; i++) {
        currArray[i] = new Dollar(initValArr[i]);
    }

    //Create SinglyLinkedList
    SinglyLinkedList* sLinkList = new SinglyLinkedList();
    //Create Stack
    Stack* labStack = new Stack();
    //Create Queue
    Queue* labQueue = new Queue();

    //////////////////////  FOR LINKED LIST     ////////////////////////////////
    //add first 7 array obj into linkedlist (reverse order: 7th element = head, 1st = end)
    int j = 6;
    for (int i = 0; i < 7; i++) { // Check if i must be 6 or 7
        sLinkList->addCurrency(*currArray[j], i);
        j--;
    }

    //Search for $87.43, print result
    Dollar srchCurr1(87.43);
    cout << "Search SinglyLinkedList for $";
    srchCurr1.print();
    cout << " Result index : " << sLinkList->findCurrency(srchCurr1) << endl;

    // Search for $44.56, print result
    Dollar srchCurr2(44.56);
    cout << "Search SinglyLinkedList for $";
    srchCurr2.print();
    cout << " Result index : " << sLinkList->findCurrency(srchCurr2) << endl;

    //Search for and remove node containing $111.22
    Dollar srchCurr3(111.22);
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
    cout << "Contents of List: " << sLinkList->printList() << "\n\n" << endl;
    
    delete sLinkList;
    //////////////////////////////////////////////////////////////////////////

    //////////////////////  FOR STACK   //////////////////////////////////////////////
    //Push 7 objects starting from array index 13, onwards to the stack
    for (int i = 13; i < 20; i++) {
        labStack->push(*currArray[i]);
    }

    // Peek top of stack and print result
    cout << "Top of Stack: ";
    labStack->peek()->print();
    cout << endl;

    // Perform 3 pops in succession
    for (int i = 0; i < 3; i++) {
        labStack->pop();
    }

    // Print contents of stack
    cout << "Contents of Stack: " << labStack->printStack() << endl;

    // Push 5 more objects from the start of the objects array to the stack
    for (int i = 0; i < 5; i++) {
        labStack->push(*currArray[i]);
    }

    // Pop twice in succession
    labStack->pop();
    labStack->pop();

    // Print contents of stack
    cout << "Contents of Stack: " << labStack->printStack() << endl;
    cout << "\n\n" << endl;

    delete labStack;
    //////////////////////////////////////////////////////////////////////////////////

    //////////////////////  FOR QUEUE   //////////////////////////////////////////////
    //Enqueue the seven (7) objects at odd indexes starting from index 5 in the array.
    for (int i = 7; i < 20; i++) { // There are 8 objects at odd indexes starting from and including index 5 in the array {5, 7, 9, 11, 13, 15, 17, 19}. To meet the target number of elements, I will assume this does not include index 5.
        labQueue->enqueue(*currArray[i]);
        i++;
    }

    //Peek the front and end of the queue - print the results.
    cout << "Front of Queue: ";
    labQueue->peekFront()->print();
    cout << endl;

    cout << "End of Queue: ";
    labQueue->peekRear()->print();
    cout << endl;

    //Perform two(2) dequeues in succession.
    labQueue->dequeue();
    labQueue->dequeue();

    //Print the contents of the queue.
    cout << "Contents of Queue: " << labQueue->printQueue() << endl;

    //Enqueue five(5) more objects from the index 10 in the array.
    for (int i = 10; i < 15; i++) {
        labQueue->enqueue(*currArray[i]);
    }
    
    //Dequeue three times in succession.
    for (int i = 0; i < 3; i++) {
        labQueue->dequeue();
    }
    
    //Print the contents of the queue.
    cout << "Contents of Queue: " << labQueue->printQueue() << endl;

    delete labQueue;
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