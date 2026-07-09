#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int n,m,s,x;
    fin>>n;
    while(n--)
    {
        fin>>m;
        fin>>x;
        s=x;
        for(int i=2;i<=m;i++)
            {fin>>x;s=x xor s;}
        if(s)
            fout<<"DA";
        else
            fout<<"NU";
    }
    return 0;
}
