#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n,nr,i,x;
    fin>>t;
    while(t)
    {
        fin>>n>>x;
        for(i=1;i<n;i++)
        {
            fin>>nr;
            x^=nr;
        }
        if(x==0)
            fout<<"NU"<<'\n';
        else
            fout<<"DA"<<'\n';
        t--;
    }
    return 0;
}
