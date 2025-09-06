#include <iostream>
#include <deque>
using namespace std;

int main() 
{
    int size, k;
    cout << "Enter The size Of The Array : ";
    cin >> size;

    int a[size];
    cout << "Enter "<<size<<" Elements in Array : ";
    for (int i = 0; i < size; i++) 
    {
        cin >> a[i];
    }

    cout << "Enter K : ";
    cin >> k;

    deque<int> q;
    int ans[size - k + 1];
    int pos = 0;

    for (int i = 0; i < size; i++) 
    {
        if (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }

        while (!q.empty() && a[q.back()] <= a[i])
        {
            q.pop_back();
        }
        q.push_back(i);

        if (i >= k - 1) 
        {
            ans[pos++] = a[q.front()];
        }
    }

    cout << "Maximum of each window : ";
    for (int i = 0; i < size - k + 1; i++) 
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}