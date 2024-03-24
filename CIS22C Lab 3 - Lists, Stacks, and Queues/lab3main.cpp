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
    SinglyLinkedList sLinkList();
    //Create Stack
    //Stack labStack();
    //Create Queue
    //Queue labQueue();

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