#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter Any String of Parenthesis: ";
    getline(cin, s);

    if (s.length() == 0) 
    {
        cout << "true";
        return 0;
    }

    if (s.length() % 2 != 0) 
    {
        cout << "false";
        return 0;
    }

    char array1[10000];
    int lastelement = -1; 
    bool Ans = true;

    for (int i = 0; i < s.length(); i++) 
    {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') 
        {
            array1[++lastelement] = c;
        }
        else 
        {
            if (lastelement == -1) 
            {
                Ans = false;
                break;
            }

            char last = array1[lastelement--];

            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) 
            {
                Ans = false;
                break;
            }
        }
    }

    if (lastelement != -1) Ans = false;

    cout << (Ans ? "true" : "false");
    return 0;
}