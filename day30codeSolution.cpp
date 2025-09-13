#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n,amt;
    cout<<"Enter number of coins : ";
    cin>>n;
    if(n<=0) {
        cout<<"No Coins are selected ";
        return 0;
    }
    int a[n];
    cout<<"Enter coins  : ";
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
    }
    cout<<"Enter the amount: ";
    cin>>amt;

    int dp[10001];
    for(int i=0;i<=amt;i++) {
        dp[i]=INT_MAX;
    }
    dp[0]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<=amt;j++)
        {
            if(dp[j-a[i]]!=INT_MAX)
            {
                dp[j]=min(dp[j],dp[j-a[i]]+1);
            }
        }
    }

    if(dp[amt]==INT_MAX)
    {
        cout<<"Minimum coins required : -1";
    } else {
        cout<<"Minimum coins required : "<<dp[amt];
    }
    return 0;
}
