#include <iostream>
#include <unordered_map>
using namespace std;

int findFirst(int a[], int size, int times) 
{
    unordered_map<int,int> mp;

    for(int i=0;i<size;i++)
    {
        mp[a[i]]++;
    }

    for(int i=0;i<size;i++)
    {
        if(mp[a[i]]==times)
        {
            return a[i];
        }
    }
    return -1;
}

int main()
{
    int n,k;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter value of k it should be from 0 to "<<n<<" : ";
    cin>>k;

    int ans=findFirst(arr,n,k);
    cout<<"Answer = "<<ans<<endl;

    return 0;
}
