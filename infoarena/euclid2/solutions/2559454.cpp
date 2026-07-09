#include <fstream>
#include <iostream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n, a,b;

int main()
{
    cin>>n;
    while(n)
    {
    cin>>a>>b;
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
        cout<<a<<'\n';
    }
    return 0;
}
