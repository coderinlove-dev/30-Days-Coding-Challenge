#include <iostream>
#include <stack>
using namespace std;

void stackelement(stack<int> &st, int ele) {
    if(st.empty() || st.top() <= ele) 
    {
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    stackelement(st, ele);
    st.push(temp);
}

void sortstack(stack<int> &st) 
{
    if(st.empty()) return;
    int temp = st.top();
    st.pop();
    sortstack(st);
    stackelement(st, temp);
}

void show(stack<int> &st) {
    if(st.empty()) return;
    int temp = st.top();
    st.pop();
    show(st);
    cout << temp << " ";
    st.push(temp);
}

int main() {
    stack<int> s;
    int n, x;

    cout << "Enter The Size Of Stack  : ";
    cin >> n;

    if(n == 0) {
        cout << "The stack is empty." << endl;
        return 0;
    }

     if(n < 0) {
        cout << "The Stack Size Cant be Negative ." << endl;
        return 0;
    }

    cout << "Enter stack elements : ";
    for(int i=0; i<n; i++) {
        cin >> x;
        s.push(x);
    }

    sortstack(s);

    cout << "Stack After Sorting : ";
    show(s);

    return 0;
}
