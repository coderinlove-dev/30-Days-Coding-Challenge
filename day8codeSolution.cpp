#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    string word = "", result = "";
    
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            if (!word.empty()) {
                if (result == "")
                    result = word;
                else
                    result = word + " " + result;
            }
            word = "";
        } else {
            word += s[i];
        }
    }

    if (result.empty()) 
    {
        cout << "String is empty"; 
    } else {
        cout << "Reversed String : " << result;
    }

    return 0;
}
