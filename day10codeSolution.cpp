#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter The Number of Words: ";
    cin >> n;

    string words[10000];
    string arry2[10000];

    cout << "Enter " <<n<<" Words in the Array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> words[i];
        arry2[i] = words[i];
        sort(arry2[i].begin(), arry2[i].end());
    }

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arry2[j] > arry2[j + 1]) {
                swap(arry2[j], arry2[j + 1]);
                swap(words[j], words[j + 1]);
            }
        }
    }

    cout << "\nGrouped Anagrams:\n[ ";
    cout << "[ " << words[0];
    for (int i = 1; i < n; i++) 
    {
        if (arry2[i] == arry2[i - 1]) {
            cout << " " << words[i];
        } else {
            cout << " ]";
            if (i != n) cout << ", [ " << words[i];
        }
    }
    cout << " ] ]\n";

    return 0;
}
