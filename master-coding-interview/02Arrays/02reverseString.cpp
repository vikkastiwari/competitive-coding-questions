#include <bits/stdc++.h>
using namespace std;

// Method 1
// Function to reverse a string
void revString(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

// Method 2
void revCharArray(char *arr, int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printCharArray(char *arr, int size)
{
    cout << "Method 2: ";
    for (int i = 0; i < size; i++)
        cout << arr[i];
    cout << endl;
}

int charLen(char str[])
{
    // function to calculate length of a chracter array
    int len = 0, i = 0;
    while (str[i] != '\0')
    {
        len = len + 1;
        i++;
    }
    return len;
}

int main()
{
    string s;
    cin >> s;
    string str = s;
    int n = s.length();
    char cArray[n + 1];

    // strcpy - copying the contents
    /* c_str() - It returns a pointer to an array that contains a null-terminated sequence 
    of characters (i.e., a C-string) representing the current value of the string object. */
    strcpy(cArray, s.c_str());

    // reverse string directly
    revString(s);
    cout << "Method 1: " << s << endl;

    // reverse char array
    int len = charLen(cArray);
    revCharArray(cArray, len);
    printCharArray(cArray, len);

    // Inbuilt function
    reverse(str.begin(), str.end());
    cout << "Method 3: " << str << endl;

    return 0;
}