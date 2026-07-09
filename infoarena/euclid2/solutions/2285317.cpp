#include <iostream>
#include <fstream>

using namespace std;
ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int v[100001];

int main()
{
    int n,a,b,r;
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    return 0;
}
