#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("Euclid2.in");
ofstream fout("Euclid2.out");
long long Euclid2(long long x,long long y)
{   int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{   long long n,a,b;
    fin >> n;
    for(int i=1; i<=n; ++i)
    {
        fin >> a >> b;
        fout << Euclid2(a,b) << endl;
    }

    return 0;
}


