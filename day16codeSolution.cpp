#include <iostream>
using namespace std;

int main() {
    long long num1, num2;
    cout << "Enter 1st number : ";
    cin >> num1;
    cout << "Enter 2nd number : ";
    cin >> num2;

    long long a = num1, b = num2;

    while (b != 0) 
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    long long high = a;

    long long lcm = (num1 / high) * num2;
    cout << "LCM = " << lcm << endl;

    return 0;
}