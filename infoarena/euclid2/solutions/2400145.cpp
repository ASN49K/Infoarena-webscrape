//#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b,c,n;
int main()
{
    cin>>n;
    while(n)
    {
        cin>>a>>b;

        while(a!=b)
        {
            a=abs(a-b);
            b=abs(b-a);
        }
        cout<<a<<"\n";
        n--;
    }
    return 0;
}
