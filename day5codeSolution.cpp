#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " Elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    int leaders[n];  
    int count = 0;

    int LastElement = arr[n-1]; 
    leaders[count++] = LastElement;  


    for (int i = n-2; i >= 0; i--)
    {
        if (arr[i] > LastElement)
        {
            leaders[count++] = arr[i];
            LastElement = arr[i];
        }
    }

    cout << "Leaders: ";
    for (int i = count-1; i >= 0; i--) 
    {
        cout << leaders[i]<< " ";
    }
    cout << endl;

    return 0;
}
   