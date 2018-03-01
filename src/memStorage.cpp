//This file is the basics of how the memory system should work
#include <iostream>
#include <list>
#include <iostream>
using namespace std;

//This is how I tested moving through the memory
int main(){    
    //how are we going to store info best?  as stirngs, then converting 
    //needs to move up and down, 
    //be able to pull a value back to the line 
    //delete from a certain space 
    char input; 
    list<int> memory; //empty
    memory.push_back(1); 
    memory.push_back(2); 
    memory.push_back(3);
    memory.push_back(4); 
    memory.push_back(5); 
    list<int>::iterator it; 
    it = memory.end(); 
    for (int i = 0; i < 5; i++) { 
        cin>>input; 
        if (input == 'u') {	
            it++; 
            cout<<*it<<endl; 
        } else if (input == 'd') { 
            it--; 
            cout<<*it<<endl; 
        } 
    }
//create a linked list    //checks if size of linked list exceeds X amount
// //if yes, it starts cutting off top when adding (swtich a boolean)
// // //allow storage, deletion, access of value    
    return 0;
}
