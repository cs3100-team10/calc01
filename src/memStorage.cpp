
#include "memStorage.h"

MemStorage::MemStorage()
{
    pos = -1;
}

/**
 * New history items are added at the end of the data structure.
 * The structure is organized in chronological order; the oldest items are first in the list, and the newest items are last.
 **/

QString MemStorage::at(const int index) const
{
    if (index >= 0 && index < this->size())
    {
        return memory[index];
    }

    if (index == this->size())
    {
        // empty string represents current entry
        return QString("");
    }

    else
    {
        return QString("");
    }
}

int MemStorage::size() const
{
    return memory.size();
}

/**
 * Scroll up in memory.
 * This gets the item before the current item in the list.
 **/
QString MemStorage::up()
{
    if (pos > 0)
    {
        // we're not already at the lowest index
        // which means that there are older items
        // we need to move up by 1
        pos--;
    }

    return this->at(pos);
}

/**
 * Scroll down in memory.
 * This gets the item after the current item in the list.
 **/
QString MemStorage::down()
{
    if (pos < this->size())
    {
        // we're not already at the lowest index
        // we need to move down by 1
        pos++;
    }

    return this->at(pos);
}

/**
 * Add a new item to the list.
 * This appends an item to the list and resets the position to the empty string.
 **/
QString MemStorage::push(QString str)
{
    memory.push_back(str);
    pos = this->size();
    return this->at(pos); // will always return empty QString
}

/**
 * Returns the value of the most recent QString in the memory.
 **/
QString MemStorage::recentMem()
{
    if (this->size() != 0)
    {
        return this->at(this->size() - 1);
    } else {
        return QString(""); //return error of no memory
    }
}

/**
 * Reset the position in memory to beginning.
 **/
void MemStorage::returnBegin()
{
    if (pos != this->size())
    {
        pos = this->size();
    }
}
