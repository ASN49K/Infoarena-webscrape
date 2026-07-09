#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b;

int euclid(int, int);

int main()
{
    fin>>n;
    for(int i=0; i<n; i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b);
    }

    return 0;
}

int euclid(int a, int b)
{
    if(b!=1 && a!=b)
        return (b,a%b);
    else
        return 1;
}
