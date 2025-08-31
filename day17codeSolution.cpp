#include <iostream>
using namespace std;

int main() {
    long long n;
    cout << "Enter Any Number : ";
    cin >> n;

    cout << "[ ";

    bool firstnum = true;

    while (n % 2 == 0) 
    {
        if (!firstnum) cout << " , ";
        cout << 2;
        n = n/2;
        firstnum = false;
    }

    for (long long i = 3; i * i <= n; i = i + 2) 
    {
        while (n % i == 0) 
        {
            if (!firstnum) cout << " , ";
            cout << i;
            n = n/i;
            firstnum = false;
        }
    }

    if (n > 2) 
    {
        if (!firstnum) cout << " , ";
        cout << n;
    }

    cout << "]" << endl;
    return 0;
}