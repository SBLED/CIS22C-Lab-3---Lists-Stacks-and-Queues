/* CIS-22C
*  Lab 3
*  Spencer Bledsoe
*/
#pragma once
#include "SinglyLinkedList.h"
#include <string>
#include <sstream>
class Queue : SinglyLinkedList {
public:
    //enqueue which takes a Currency object as parameter and adds it to the end of the queue.
    void enqueue(Currency& currObj) {
        LinkNode* newNode = new LinkNode();
        newNode->data = &currObj;

        if (count == 0) {
            start = newNode;
            end = newNode;
        }

        else {
            end->next = newNode;
            end = newNode;
        }
        count++;
        return;
    }

    //dequeue which takes no parameter and removes and returns the Currency object from the front of the queue.
    Currency& dequeue() {
        Currency* temp;
        try {
            if (count == 0) {
                throw ("No_Such_Element");
            }

            else if (count == 1) {
                temp = start->data;
                start = NULL;
                end = NULL;
                count = 0;
            }

            else {
                temp = start->data;
                start = start->next;
                count--;
            }
        }
        catch (std::string r) {
            std::cout << "Error: " << r << std::endl;
        }
        return *temp;
    }
    //peekFront which takes no parameter and returns a copy of the Currency object at the front of the queue.
    const Currency* peekFront() {
        try {
            if (count == 0) {
                throw ("No_Such_Element");
            }
        }
        catch (std::string s) {
            std::cout << "Error: " << s << std::endl;
        }
        return start->data;
    }
    //peekRear which takes no parameter and returns a copy of the Currency object at the end of the queue.
    const Currency* peekRear() {
        try {
            if (count == 0) {
                throw ("No_Such_Element");
            }
        }
        catch (std::string t) {
            std::cout << "Error: " << t << std::endl;
        }
        return end->data;
    }

    //printQueue method which returns a string signifying the contents of the queue from front to end, tab spaced.
     /*
     * Returns the values stored in the Queue as a String, separated by a tab space
     * @return a String of Queue values
     */
    std::string printQueue() {
        std::stringstream ss;
        std::string str;
        LinkNode* temp = start;
        while (temp != NULL) {
            ss << temp->data << "\t";
            temp = temp->next;
        }
        return str;
    }
};