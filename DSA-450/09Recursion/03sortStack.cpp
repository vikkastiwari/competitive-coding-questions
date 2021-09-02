#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &v, int temp)
{
    if (v.size() == 0 || v.top() <= temp)
    {
        v.push(temp);
        return;
    }
    int val = v.top();
    v.pop();
    insert(v, temp);
    v.push(val);
}

void sort(stack<int> &v)
{
    if (v.size() == 1)
        return;

    int temp = v.top();
    v.pop();
    sort(v);
    insert(v, temp);
}

void print(stack<int> &st)
{
    cout << st.top() << " ";
    st.pop();
    print(st);
}

int main()
{
    stack<int> st;
    st.push(0);
    st.push(5);
    st.push(2);
    st.push(4);
    st.push(1);

    sort(st);
    print(st);
    return 0;
}