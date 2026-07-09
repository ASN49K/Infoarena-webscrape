#include<iostream>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    i=1;
    while(i*i<n)
    {
        i++;
    }
    cout<<i;
    return 0;
}
