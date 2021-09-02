#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st, k - 1);
    st.push(temp);
    return;
}

stack<int> del(stack<int> &st, int size)
{
    if (st.size() == 0)
        return st;
    int k = (size / 2) + 1;
    solve(st, k);
    return st;
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
    int size = 5;

    del(st, size);
    print(st);
    return 0;
}