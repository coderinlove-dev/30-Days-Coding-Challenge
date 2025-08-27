#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s;
    cout << "Enter Any Word : ";
    cin >> s;

    int n = s.length();
    int longest = 1;
    int starting = 0;


    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {

            bool ans = true;
            int left = i, right = j;

            while (left < right) 
            {
                if (s[left] != s[right]) 
                {
                    ans = false;
                    break;
                }
                left++;
                right--;
            }

            if (ans && (j - i + 1) > longest) 
            {
                longest = j - i + 1;
                starting = i;
            }
        }
    }

    cout << "The Longest Palindrome In The String Is :  " << s.substr(starting, longest) << endl;
    return 0;
}
   