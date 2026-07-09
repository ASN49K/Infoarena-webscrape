#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
long long n,i,x,y,r;
int main()
{fin>>n;
while(n)
{
    n--;
    fin>>x>>y;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    fout<<x<<"\n";
}

    return 0;
}
