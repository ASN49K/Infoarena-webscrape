#include<fstream>
#include<iostream>
using namespace std;
int a,b,x;
int main()
{
    cin>>a>>b;
    while(b)
    {
        x=a%b;
        a=b;
        b=x;

    }
    cout<<a;
}
