#include <QApplication>
#include <list>
using namespace std;

class MemStorage
{
    //memorage storage
    public:
        list<QString> memory;
        list<QString>::iterator it;
        int loc;
        int size;

        //constructor
        MemStorage() {
            it = memory.end();
            loc = 0;
            size = 0;
        }
        //clear empty nodes
        void clearEmpties() {
            memory.remove("");
            list<QString>::iterator begin = memory.begin();
            list<QString>::iterator end = memory.end();
            size = distance(begin, end);
        }

    private:
};
