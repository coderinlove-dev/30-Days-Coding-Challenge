#include<iostream>
using namespace std;

int main(){
   
    int n;
    cout<<"Enter Size of the Array : ";
    cin>>n;

    if(n<3)
    { 
        cout<<"Total water trapped = 0 bcz no enough bars"<<endl;
        return 0;
    }

    int arr[n];
    cout<<"Enter "<<n<<" elements In the Array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int l=0,r=n-1;
    int lmax=0,rmax=0;
    int total=0;

    while(l<=r)
    {
        if(arr[l]<=arr[r])
        {
            if(arr[l]>=lmax)
            {
                lmax=arr[l];
            }
            else
            {
                total = total + (lmax-arr[l]);
            }
            l++;
        }
        else{
            if(arr[r]>=rmax)
            {
                rmax=arr[r];
            }
            else
            {
                total = total + (rmax-arr[r]);
            }
            r--;
        }
    }

    cout<<"Total water trapped = "<<total<<endl;

    return 0;
}
   