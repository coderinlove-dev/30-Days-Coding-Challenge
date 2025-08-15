#include<iostream>
using namespace std;

int main()
{
    int n =0 ;
    cout << " Enter Size Of Array : ";
    cin >> n;
    if(n==0||n<0){
    cout << "The Size Of The Array Should Be Positive" << endl;
    return 0;
    }
    int array[n];
    cout << "Enter The Elements Of Array : ";
    for (int i = 0 ; i<=n-1; i++){
    cin >> array[i];
    }
    //sorting logic
    int low,high,mid;
    low=0;
    mid=0;
    high=n-1;
    
    while(mid<=high){
    if (array[mid]==0){
    swap(array[low],array[mid]);
    mid++;
    low++;
    }
    else if (array[mid]==1){
    mid++;
    }
    else {
     swap(array[high],array[mid]);
     high--;
    }
   }
    cout << "The Array After Sorting " << endl;
    
    for (int i = 0 ; i<=n-1; i++){
    cout << array[i] << endl;
    }
    return 0;
}