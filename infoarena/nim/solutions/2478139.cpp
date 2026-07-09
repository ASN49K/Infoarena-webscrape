#include <bits/stdc++.h>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n,a,sum,elem;

int main()
{
    fin>>n;
    for(int i=0; i<n; i++)
    {
        fin>>a;
        fin>>sum;
        for(int j=1; j<a; j++)
        {
            fin>>elem;
            sum=sum^elem;
        }
        if(sum==0) fout<<"NU"<<"\n";
        else fout<<"DA"<<"\n";
    }
}
