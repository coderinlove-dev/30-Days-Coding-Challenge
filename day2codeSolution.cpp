#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cout << "Enter Size Of Array with missing number included: ";
    cin >> n;

    if (n <= 0) {
        cout << "The Size Of The Array Should Be Positive" << endl;
        return 0;
    }

    if (n == 1) {  
        cout << "The Array Contains 0 Elements" << endl;
        cout << "The Missing Number in The Array is: 1" << endl;
        return 0;
    }

    cout << "Enter " << n - 1 << " elements in the array: ";

    int num;
    long long isPresent = 0;  
    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        isPresent = isPresent + num;
    }

    long long isExpected =  n * (n + 1) / 2; 
    long long isMissing = isExpected - isPresent;

    cout << "The Missing Number in The Array is: " << isMissing << endl;

    return 0;
}
