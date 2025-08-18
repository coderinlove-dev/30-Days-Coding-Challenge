#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter size of First Array: ";
    cin >> m;
    cout << "Enter size of Second Array: ";
    cin >> n;

    int arr1[m], arr2[n];

    cout << "Enter elements of First Sorted Array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of Second Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    auto getGap = [](int g) {
        if (g <= 1) return 0;
        return (g + 1) / 2;  
    };

    int gap = m + n;

    for (gap = getGap(gap); gap > 0; gap = getGap(gap)) {

        for (int i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap]) {
                swap(arr1[i], arr1[i + gap]);
            }
        }

      int i, j;
        if (gap > m) {
            i = gap - m;
            j = 0;
        } else {
            i = 0;
            j = m - gap;
        }

        while (j < m && i < n) {
            if (arr1[j] > arr2[i]) {
                swap(arr1[j], arr2[i]);
            }
            j++;
            i++;
        }

        for (int k = 0; k + gap < n; k++) {
            if (arr2[k] > arr2[k + gap]) {
                swap(arr2[k], arr2[k + gap]);
            }
        }
    }

    cout << "Array 1 = ";
    for (int i = 0; i < m; i++) cout << arr1[i] << " ";
    cout << "\nArray 2 = ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
