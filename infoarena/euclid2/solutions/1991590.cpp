//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b;
int t,i;

int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b;
        while(a!=b)
            if(a>b) a-=b;
            else b-=a;
        cout<<a<<"\n";
    }
    return 0;
}
