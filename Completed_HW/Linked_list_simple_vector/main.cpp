/* Project- Simple Vector and Link List
 * Author- Ismael Perez
 * Date- 10/17/23
 * 
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv) {
    LinkedList list; // list object

    cout << "Original List" << endl;
    // items in the linked list
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    // print the list 
    list.prntLst();
    cout << endl;
    
    // push front and back
    list.push_front(12);
    list.push_back(54);
    
    cout << "After Adding one front and one back:" << endl;
    list.prntLst();
    cout << endl;
    
    // pop front and back 
    list.pop_front();
    list.pop_front();
    list.pop_back();

    cout << "After Removing two front and one back:" << endl;
    list.prntLst();

    return 0;
}
