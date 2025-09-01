#include <iostream>
using namespace std;

int main() 
{
    long long N;
    cout << "Enter Any Number: ";
    cin >> N;

    int count = 0;

    for (long long i = 1; i * i <= N; i++) 
    {
        if (N % i == 0) 
        {
            if (i * i == N)
            {
                count++;
            }
            else
            {
                count = count + 2;
            }
        }
    }

    cout << count << endl;
    return 0;
}
   