#ifndef MEMSTORAGE_H
#define MEMSTORAGE_H

#include <QApplication>
#include <vector>
using namespace std;

class MemStorage
{
    private:
    vector<QString> memory;
    int pos;

    QString at(const int index) const;
    int size() const;


    public:
    MemStorage();
    QString up();
    QString down();
    QString push(QString str);
    QString recentMem();
    void returnBegin();

};

#endif
