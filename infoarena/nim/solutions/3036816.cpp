#include <bits/stdc++.h>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream cin ("nim.in");
ofstream cout ("nim.out");
int t,l,i,aux,x,n;
int main()
{
    cin>>t;
    for(l=1;l<=t;l++)
    {
        cin>>n;
        aux=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            aux=(aux^x);
        }
        if(aux==0)
            cout<<"NU";
            else
            cout<<"DA";
        cout<<'\n';
    }
    return 0;
}
