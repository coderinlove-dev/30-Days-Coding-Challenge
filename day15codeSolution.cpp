#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "Enter Any String: ";
    cin >> str;

    int pos[256];
    for (int i = 0; i < 256; i++)
    {
        pos[i] = -1;
    }

    int start = 0, ans = 0;

    for (int j = 0; j < str.length(); j++) 
    {
        char ch = str[j];

        if (pos[(int)ch] >= start) 
        {
            start = pos[(int)ch] + 1;
        }

        pos[(int)ch] = j;
        ans = max(ans, j - start + 1);
    }

    cout << "Length of longest substring without repeating characters is : " << ans << endl;
    return 0;
}