#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Size Of Array with duplicate not included : ";
    cin >> n;

    if (n <= 0) {
        cout << "The Size Of The Array Should Be Positive" << endl;
        return 0;
    }

    int array[n+1];
    cout << "Enter " << n+1 << " elements in the array: ";
    for (int i = 0; i <= n; i++) {
        cin >> array[i];
    }

    int num1 = array[0], num2 = array[0];

    do {
        num1 = array[num1];
        num2 = array[array[num2]];
    } while (num1 != num2);

    num1 = array[0];
    while (num1 != num2) {
        num1 = array[num1];
        num2 = array[num2];
    }

    cout << "The Duplicate Number in The Array is: " << num1 << endl;

    return 0;
}
