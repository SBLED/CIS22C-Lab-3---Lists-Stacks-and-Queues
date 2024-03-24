/* CIS-22C
*  Lab 3
*  Spencer Bledsoe
*/
#pragma once
#include "LinkNode.h"

class SinglyLinkedList {
	private:
		int count;
		LinkNode* start;
		LinkNode* end;

	public:
		SinglyLinkedList() {
			count = 0;
			start = NULL;
			end = NULL;
		}

		~SinglyLinkedList() {

		}
		
		//Getters
		/*Pre: 
		Post: returns corresponding member variable value.
		*/
		int getCount() { return count; }
		LinkNode* getStart() { return start;  } //Check this logic, or if these are needed at all
		LinkNode* getEnd() { return end; } //Check this logic

		//Setters
		/*Pre:
		Post: Sets corresponding member variable to new(Val)
		*/
		void setCount(int newCount) { count = newCount; }
		void setStart(LinkNode* newStart) { start = newStart; }
		void setEnd(LinkNode* newEnd) { end = newEnd; }

		void addCurrency(Currency& currObj, int index) {
			if (count == 0) {
				start = new LinkNode();
				start->data = &currObj;
				count++;
			}
			else if (count == 1 && index == 1) {
				start->next = new LinkNode();
				start->next->data = &currObj;
				end = start->next;
				count++;
			}
			else {
				for (int i = 0; i < index; i++) {
					LinkNode* temp;
					count++;
				}
			}
		}

};