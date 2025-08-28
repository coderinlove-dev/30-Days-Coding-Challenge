#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    int k;
    cout << "Enter Any String: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    int len = s.size();

    int i1 = 0, cnt1 = 0;
    unordered_map<char,int> mp1;
    for (int j = 0; j < len; j++) 
    {
        mp1[s[j]]++;
        while ((int)mp1.size() > k) 
        {
            mp1[s[i1]]--;
            if (mp1[s[i1]] == 0) 
            {
                mp1.erase(s[i1]);
            }
            i1++;
        }
        cnt1 += (j - i1 + 1);
    }

    int i2 = 0, cnt2 = 0;
    unordered_map<char,int> mp2;
    for (int j = 0; j < len; j++) 
    {
        mp2[s[j]]++;
        while ((int)mp2.size() > (k-1)) 
        {
            mp2[s[i2]]--;
            if (mp2[s[i2]] == 0) 
            {
                mp2.erase(s[i2]);
            }
            i2++;
        }
        cnt2 += (j - i2 + 1);
    }

    int ans = cnt1 - cnt2;
    cout << "Substrings possible : " << ans << endl;

    return 0;
}