#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maximum = 362880;
string results[Maximum];
int index = 0;

void permantation(string &str, int start, int n) 
{
    if (start == n) 
    {
        results[index++] = str;
        return;
    }
    for (int i = start; i < n; i++) 
    {
        bool repeat = false;
        for (int j = start; j < i; j++) 
        {
            if (str[j] == str[i]) 
            {
                repeat = true;
                break;
            }
        }
        if (repeat) continue;

        swap(str[start], str[i]);
        permantation(str, start + 1, n);
        swap(str[start], str[i]);
    }
}

int main() {
    string word;
    cout << "Enter Any Word Of Characters: ";
    cin >> word;

    sort(word.begin(), word.end());
    permantation(word, 0, word.size());

    cout << "Unique Permantation:\n[";
    for (int i = 0; i < index; i++) 
    {
        if (i > 0) cout << ", ";
        cout << "\"" << results[i] << "\"";
    }
    cout << "]\n";

    return 0;
}
