
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

/**
 * accesses the parser friendly string from memory at the specified index
 **/
string MemStorage::atParse(const int index) const
{
    if (index >= 0 && index < this->size())
    {
        return stringmem[index];
    }

    if (index == this->size())
    {
        // empty string represents current entry
        return string("");
    }

    else
    {
        return string("");
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
 * Scroll up in memory for parser string.
 * This gets the item before the current item in the list.
 **/
string MemStorage::upParse()
{
    if (pos > 0)
    {
        // we're not already at the lowest index
        // which means that there are older items
        // we need to move up by 1
        pos--;
    }
    return this->atParse(pos);
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
 * Scroll down in memory for parser string.
 * This gets the item after the current item in the list.
 **/
string MemStorage::downParse()
{
    if (pos < this->size())
    {
        // we're not already at the lowest index
        // we need to move down by 1
        pos++;
    }

    return this->atParse(pos);
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
 * Add a new item to the list for parser strings.
 * This appends an item to the list and resets the position to the empty string.
 **/
string MemStorage::pushParse(string str)
{
    stringmem.push_back(str);
    pos = this->size();
    return this->atParse(pos); // will always return empty string
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
 * Returns the value of the most recent string in the memory.
 **/
string MemStorage::recentMemParse()
{
    if (this->size() != 0)
    {
        return this->atParse(this->size() - 1);
    } else {
        return string(""); //return error of no memory
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
