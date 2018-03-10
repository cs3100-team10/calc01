#include <QApplication>
#include <list>
using namespace std;

class MemStorage
{
    //memorage storage
    public:
        list<QString> memory;
        list<QString>::iterator it;
        //list<QString>::iterator begin;
        //list<QString>::iterator end;

        //constructor
        MemStorage() {
            it = memory.end();
            //begin = memory.begin();
            //end = memory.end();
        }
        //update iterators
        /*void updateIterators() {
            begin = memory.begin();
            end = memory.end();
        }*/

    private:
};
