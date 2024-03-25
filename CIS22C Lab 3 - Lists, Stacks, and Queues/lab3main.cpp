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
    SinglyLinkedList sLinkList;
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
    for (int i = 0; i < 6; i++) {
        sLinkList.addCurrency(*currArray[j], i);
        j--;
    }
    //Search for $87.43, print result
    // Search for $44.56, print result
    //Search for and remove node containing $111.22
    //Remove node at index 2
    //Print list contents
    //Add next 4 obj (9-12) such that their index in the linkedlist is calculated as (index in array % 5)
    //Remove object at index (countCurrency % 6)
    //Remove object at index (countCurrency / 7)
    //Print contents of list.
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