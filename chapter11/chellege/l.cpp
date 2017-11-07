#include <iostream>
#include <cstdlib>
using namespace std;

class IntNode {
public:
   IntNode(int dataInit = 0, IntNode* nextLoc = 0);
   void InsertAfter(IntNode* nodePtr);
   IntNode* GetNext();
   int GetDataVal();
private:
   int dataVal;
   IntNode* nextNodePtr;
};

// Constructor
IntNode::IntNode(int dataInit, IntNode* nextLoc) {
   this->dataVal = dataInit;
   this->nextNodePtr = nextLoc;
   return;
}

/* Insert node after this node.
 * Before: this -- next
 * After:  this -- node -- next
 */
void IntNode::InsertAfter(IntNode* nodeLoc) {
   IntNode* tmpNext = 0;

   tmpNext = this->nextNodePtr;    // Remember next
   this->nextNodePtr = nodeLoc;    // this -- node -- ?
   nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
   return;
}

// Grab location pointed by nextNodePtr
IntNode* IntNode::GetNext() {
   return this->nextNodePtr;
}

int IntNode::GetDataVal() {
   return this->dataVal;
}

int main() {
   IntNode* headObj = 0; // Create intNode objects
   IntNode* currObj = 0;
   IntNode* lastObj = 0;
   int i = 0;            // Loop index
   int negativeCntr = 0;

   headObj = new IntNode(-1);        // Front of nodes list
   lastObj = headObj;

   for (i = 0; i < 10; ++i) {        // Append 10 rand nums
      currObj = new IntNode((rand() % 21) - 10);
      lastObj->InsertAfter(currObj); // Append curr
      lastObj = currObj;             // Curr is the new last item
   }

   currObj = headObj;                // Print the list
   while (currObj != 0) {
      cout << currObj->GetDataVal() << ", ";
      currObj = currObj->GetNext();
   }
   cout << endl;

   currObj = headObj;                // Count number of negative numbers
   while (currObj != 0) {
	cout << currObj<< ' ';
	if (currObj->GetDataVal() < 0){
		negativeCntr++;
}
      /* Your solution goes here  */

      currObj = currObj->GetNext();
   }
   cout << "Number of negatives: " << negativeCntr << endl;

   return 0;
}
