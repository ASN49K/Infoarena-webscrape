#include <iostream>
#include <fstream>

using namespace std;

ifstream ci("euclid2.in");
ofstream cou("euclid2.out");

int cmmdc (int a, int b)
{
    while (b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int n,x,y;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x>>y;
        cout<<cmmdc(x,y)<<'\n';
    }
}
