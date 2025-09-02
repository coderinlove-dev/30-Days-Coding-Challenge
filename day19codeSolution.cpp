#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    string x;

    cout << "Enter postfix expr : ";
    
    while (cin >> x) 
    {
        bool isNum = false;

        if (isdigit(x[0])) 
        {
            isNum = true;
        }

        else if (x[0] == '-' && x.size() > 1) 
        {
            isNum = true;
        }

        if (isNum) 
        {
            int val = stoi(x);
            s.push(val);
        }
        
        else 
        {
            int n2;
            n2 = s.top();
            s.pop();

            int n1;
            n1 = s.top();
            s.pop();

            int ans = 0;

            if (x == "+") {
                ans = n1 + n2;
            }
            else if (x == "-") {
                ans = n1 - n2;
            }
            else if (x == "*") {
                ans = n1 * n2;
            }
            else if (x == "/") {
                ans = n1 / n2;
            }

            s.push(ans);
        }

        if (cin.peek() == '\n') 
        {
            break;
        }
    }

    cout << "Ans = " << s.top() << endl;
    return 0;
}
