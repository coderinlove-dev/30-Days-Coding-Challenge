#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter Number of Words : ";
    cin >> n;

    if (n == 0)
    { 
        cout << "Longest Common Prefix = \"\"" << endl;
        return 0;
    }

    string strs[n];
    cout << "Enter " << n << " strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string prefix = strs[0]; 

    for (int i = 1; i < n; i++) 
    {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size()) 
        {
            if (prefix[j] != strs[i][j]) 
            {
                 break;
            }
        j++;
        }

        prefix = prefix.substr(0, j);

        if (prefix == "") break; 
    }

    cout << "Longest Common Prefix = \"" << prefix << "\"" << endl;
    return 0;
}