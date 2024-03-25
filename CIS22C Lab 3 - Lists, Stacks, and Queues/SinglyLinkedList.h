/* CIS-22C
*  Lab 3
*  Spencer Bledsoe
*/
#pragma once
#include "LinkNode.h"
#include <string>
#include <sstream>

class SinglyLinkedList {
	protected:
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
			if (count > 0) {
				LinkNode* iterator = start;
				for (int i = 0; i < count - 1; i++) {
					//removeCurrency(1);
				}
			}
		}
		
		//Getters
		/*Pre: 
		Post: returns corresponding member variable value.
		*/
		const int getCount() { return count; }
		const LinkNode* getStart() { return start;  } //Check this logic, or if these are needed at all
		const LinkNode* getEnd() { return end; } //Check this logic
		const int countCurrency() {
			int counter = 0;
			if (start != NULL) {
				LinkNode* iterator = start;
				while (iterator->next != NULL) {
					iterator = iterator->next;
					counter++;
				}
			}
			return counter; 
		}

		//Setters
		/*Pre:
		Post: Sets corresponding member variable to new(Val)
		*/
		void setCount(int newCount) { count = newCount; }
		void setStart(LinkNode* newStart) { start = newStart; }
		void setEnd(LinkNode* newEnd) { end = newEnd; }

		//addCurrency method which takes a Currency object and a node index value as parameters to add the Currency to the list at that index.
		void addCurrency(Currency& currObj, int index) { //This has issues
			try {
				if (index >= 0 || index < count) {
					//Case 1: First Node Insert (Empty List)
					if (start == NULL) {
						start = new LinkNode();
						start->data = &currObj;
						end = start;
						count++;
					}
					//Case 2: Insert End Node
					else if (index == count - 1) {
						end->next = new LinkNode();
						end = end->next;
						end->next = NULL;
						end->data = &currObj;
						count++;
					}
					//Case 3:L Insert in Middle
					else {
						LinkNode* iterator;
						iterator->next = start;
						for (int i = 0; i < index - 1; i++) {
							iterator = iterator->next;
							iterator->data = &currObj;
						}
						if (iterator == start) {
							iterator->next = start;
							start = iterator;
							start->data = &currObj;
						}
						else if (iterator == end) {
							end->next = iterator;
							end = iterator;
							iterator->next = NULL;
							end->data = &currObj;
						}
						else {

						}
					}
				}
				else {
					throw ("Invalid Index");
				}

			}
			catch (std::string s) {
				std::cout << "Error: " << s << std::endl;
			}
			return;
		}

		Currency* removeCurrency(Currency& currObj) {

			//Case 1: Remove list head node
			int index = findCurrency(currObj);
			if (index == 0) {
				start = start->next;
				if (start == NULL) {
					end = NULL;
				}
			}
			//Case 2: Remove after iterator
			else if (index != NULL) {
				LinkNode* iterator;
				iterator->next = start;
				for (int i = 0; i < index - 1; i++) {
					iterator = iterator->next;
				}
				if (iterator->next == end) {
					iterator = end;
					iterator->next = NULL;
				}
				else {
					iterator->next = iterator->next->next;
					if (iterator->next == NULL) {
						end = iterator;
					}
				}
			}
			else {
				return NULL;
			}
		}

		Currency* removeCurrency(int index) {

			//Case 1: Remove list head node
			if (index == 0) {
				start = start->next;
				if (start == NULL) {
					end = NULL;
				}
			}
			//Case 2: Remove after iterator
			else if (index != NULL) {
				LinkNode* iterator;
				iterator->next = start;
				for (int i = 0; i < index - 1; i++) {
					iterator = iterator->next;
				}
				if (iterator->next == end) {
					iterator = end;
					iterator->next = NULL;
				}
				else {
					iterator->next = iterator->next->next;
					if (iterator->next == NULL) {
						end = iterator;
					}
				}
			}
			else {
				return NULL;
			}
		}

		const int findCurrency(Currency& currObj) { // returns index
			int index = 0;
			if (count > 0) {
				LinkNode* iterator = start;
				while (iterator != NULL) {
					if (iterator->data == &currObj) {
						return index;
					}
					index++;
					iterator = iterator->next;
				}
			}
			return NULL;
		}

		Currency* getCurrency(int index) { //assume index starts at 0
			if (count > index) {
				LinkNode* iterator = start;
				while (iterator != NULL) {
					for (int i = 0; i < index; i++) { //Check that this loops enough times.
						iterator = iterator->next;
					}
					return iterator->data;
				}
			}
			return NULL;
		}

		std::string printList() {
			std::stringstream ss;
			std::string str;
			LinkNode* iterator = start;
			while (iterator != NULL) {
				ss << iterator->data << "\t";
				iterator = iterator->next;
			}
			return str;
		}

		const bool isListEmpty() {
			if (count == 0) {
				return true;
			}
			else {
				return false;
			}
		}

};