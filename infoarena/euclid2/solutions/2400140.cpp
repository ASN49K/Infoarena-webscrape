//#include <iostream>
#include <fstream>

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
            if(a>b) a-=b;
            else b-=a;
        }
        cout<<a<<"\n";
        n--;
    }
    return 0;
}
