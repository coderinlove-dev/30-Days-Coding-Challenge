#include <iostream>
#include <stack>
using namespace std;

void pushBottom(stack<int> &st, int val) 
{
    if (st.empty()) 
    {
        st.push(val);
        return;
    }
    int topVal = st.top();
    st.pop();

    pushBottom(st, val);

    st.push(topVal);
}

void reverse(stack<int> &st) 
{
    if (st.empty()) 
    {
        return;
    }

    int topVal = st.top();
    st.pop();

    reverse(st);

    pushBottom(st, topVal);
}

void printStack(stack<int> &st) 
{
    if (st.empty()) 
    {
        return;
    }

    int topVal = st.top();
    st.pop();

    printStack(st);

    cout << topVal << " ";

    st.push(topVal);
}

int main() 
{
    stack<int> st;
    int n, num;

    cout << "Enter The Size of Stack : ";
    cin >> n;

    if(n == 0) 
    {
        cout << "The stack is empty." << endl;
        return 0;
    }

    if(n < 0) 
    {
        cout << "The Stack Size Cant be Negative ." << endl;
        return 0;
    }

    cout << "Enter Stack Elements : ";
    for (int i = 0; i < n; i++) 
    {
        cin >> num;
        st.push(num);
    }

    reverse(st);

    cout << "Stack after reversing : ";
    printStack(st);
    cout << endl;

    return 0;
}
