#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef unordered_map<long long,vector<int>> Hash;

int main() {
    int n;
    cout<<"Enter The Size Of the Array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" Elements In The Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    long long sum=0;
    bool found=false;
    Hash mymap;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==0){
            cout<<"Subarray containing sum 0 ";
            cout<<"( "<<0<<" , "<<i<<" )"<<endl;
            found=true;
        }

        if(mymap.find(sum)!=mymap.end()){
            for(int idx:mymap[sum]){
                cout<<"Subarray containing sum 0 ";
                cout<<"( "<<idx+1<<" , "<<i<<" )"<<endl;
                found=true;
            }
        }

        mymap[sum].push_back(i);
    }

    if(!found){
        cout<<"No Subarray found with sum 0 \n ";
        cout<<"[]"<<endl;
    }

    return 0;
}
