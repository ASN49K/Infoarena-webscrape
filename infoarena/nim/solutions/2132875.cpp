#include<bits/stdc++.h>

using namespace std;

int n,s,v[10000],x;

int main()
{
    ifstream fin("nim.in");
    ofstream fout("nim.out");
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        x=0;
        fin>>s;
        for(int k=1; k<=s; k++)
        {
            fin>>v[k];
            x=x^v[k];
        }
        if(x!=0)
        {
            fout<<"DA"<<"\n";
        }
        else
        {
            fout<<"NU"<<"\n";
        }
    }

}
