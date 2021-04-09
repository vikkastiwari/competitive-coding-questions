/* Implementing dynamic array in c++ which is basically a vector STL library.
   but the below implementation of arrays in c++ is done by using class which will have the
   following functions.

    1. void push(int data): This function takes one element and inserts it at the last.
    2. void push(int data, int index): It inserts data at the specified index.
    3. int get(int index): It is used to get the element at the specified index.
    4. void pop(): It deletes the last element. Time complexity is O(1).
    5. int size(): It returns the size of the vector i.e, number of elements in the vector. Time complexity is O(1).
    6. int getcapacity(): It returns the capacity of the vector. Time complexity is O(1).
    7. void print(): It is used to print array elements. Time complexity is O(N), where N is the size of the vector.

 */

#include <bits/stdc++.h>
using namespace std;

class DynamicArray
{
    int *arr;         // creating array pointer
    int capacity;     // holds the actual size of the array
    int totalNumbers; // hold the total number of elements present in the array

public:
    DynamicArray()
    {
        arr = new int[2];
        capacity = 2;
        totalNumbers = 0;
    }
    void push(int data)
    {
        // check whether the array is filled with assigned capacity or not
        if (totalNumbers == capacity)
        {
            int *temp = new int[2 * capacity]; // initialise the array at new position dynamically by doubling the size
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i]; // copy the existing elements from the older array
            }
            delete[] arr;            // delete memory allocated for older array
            capacity = capacity * 2; // update the capacity
            arr = temp;              // pointing our array to newly created memory
        }
        arr[totalNumbers] = data; // inserting data
        totalNumbers++;
    }

    void push(int data, int index)
    {
        // this function updates the existing elements wrt to index and data passed
        if (index == capacity)
        {
            push(data); // we are adding the data directly at the end position if index==capacity
        }
        else
        {
            arr[index] = data;
        }
    }

    void insertElement(int data, int index)
    {
        // this function updates the array with the data at specified index
        // without replacing the element  on the existing index
        // it just push the existing element on the same index with one position ahead
        if (index == capacity)
        {
            push(data); // we are adding the data directly at the end position if index==capacity
        }
        for (int i = totalNumbers; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = data;
        totalNumbers++;
    }

    int pop()
    {
        // it returns the last element of the array and reduces the size respectively
        int element = arr[totalNumbers - 1];
        totalNumbers--;
        return element;
    }

    void pop(int index)
    {
        // function deletes the element from specified index
        if (index > -1 && index < totalNumbers)
        {
            totalNumbers--;
            for (int i = index; i < totalNumbers; i++)
            {
                arr[i] = arr[i + 1];
            }
        }
    }

    int get(int index)
    {
        // reterive element from specified index
        if (index > -1 && index < totalNumbers)
        {
            return arr[index];
        }
    }

    int length()
    {
        return totalNumbers;
    }

    void print()
    {
        for (int i = 0; i < totalNumbers; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray array; // creating instance of the class
    array.push(10);
    array.push(15);
    array.push(20);
    array.push(25);
    array.push(30);
    cout << "The array before inserting element is ";
    array.print();

    array.insertElement(5, 0);
    cout << "The array after inserting element is ";
    array.print();

    int element = array.pop();
    cout << "Element Deleted: " << element << endl;

    cout << "The array after deletion: ";
    array.print();

    array.pop(0);
    cout << "The array after deleting element from specified index: ";
    array.print();

    cout << "The size of the array is " << array.length() << endl;

    return 0;
}