#include <bits/stdc++.h>
using namespace std;

// Initialization is bit different from 01 with oops concept
// Hashtable to implement 505, Vikas

class HashTable
{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups]; // list 1, index 0, list 2, index 1 ...

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum{}; // sum = 0
    for (int i{}; i < hashGroups; i++)
    {
        sum += table[i].size();
    }
    if (!sum)
        return true;
    else
        return false;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups; // key:505 - function will return 5
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto Itr = begin(cell);
    bool keyExists = false;
    while (Itr != end(cell))
    {
        if (Itr->first == key)
        {
            keyExists = true;
            Itr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
        Itr++;
    }

    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto Itr = begin(cell);
    bool keyExists = false;
    while (Itr != end(cell))
    {
        if (Itr->first == key)
        {
            keyExists = true;
            Itr = cell.erase(Itr);
            cout << "[INFO] Item removed." << endl;
            break;
        }
        Itr++;
    }

    if (!keyExists)
    {
        cout << "[WARNING] Key not found. Pair not removed." << endl;
    }
    return;
}

void HashTable::printTable()
{
    for (int i{}; i < hashGroups; i++)
    {
        if (table[i].size() == 0)
            continue;

        auto Itr = table[i].begin();
        while (Itr != table[i].end())
        {
            cout << "[INFO] Key: " << Itr->first << "Value: " << Itr->second << endl;
            Itr++;
        }
    }
    return;
}

int main()
{
    HashTable ht;
    (ht.isEmpty()) ? cout << "Correct Answer! - check at starting is successful" << endl : cout << "oh oh. We need to check our code" << endl;

    ht.insertItem(101, "vik");
    ht.insertItem(201, "qik");
    ht.insertItem(103, "eik");
    ht.insertItem(131, "tik");
    ht.insertItem(401, "eis");
    ht.insertItem(402, "yus");
    ht.insertItem(125, "pik");

    ht.printTable();

    ht.removeItem(402);
    ht.removeItem(131);
    ht.removeItem(1321);

    ht.printTable();

    (ht.isEmpty()) ? cout << "oh oh. We need to check our code" << endl : cout << "Correct Answer! - check at ending is successful" << endl;

    return 0;
}