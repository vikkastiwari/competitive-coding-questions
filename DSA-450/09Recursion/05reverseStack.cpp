#include <bits/stdc++.h>
using namespace std;

void print(stack<int> &st)
{
    if (st.empty())
        return;
    int temp = st.top();
    st.pop();
    cout << temp << " ";
    print(st);
    st.push(temp);
}

void insert(stack<int> &st, int temp)
{
    if (st.size() == 0)
    {
        st.push(temp);
        return;
    }
    int t = st.top();
    st.pop();
    insert(st, temp);
    st.push(t);
    return;
}

void reverse(stack<int> &st)
{
    //base condition
    if (st.size() == 1 || st.size() == 0)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverse(st);
    insert(st, temp);
    return;
}

int main()
{
    stack<int> st;
    st.push(0);
    st.push(5);
    st.push(2);
    st.push(4);
    st.push(1);

    print(st);
    cout << endl;
    reverse(st);
    print(st);
    return 0;
}