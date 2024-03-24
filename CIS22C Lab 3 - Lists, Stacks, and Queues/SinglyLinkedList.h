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
		LinkNode* getStart() { return start;  } //Check this logic, or if these are needed at all
		LinkNode* getEnd() { return end; } //Check this logic
};