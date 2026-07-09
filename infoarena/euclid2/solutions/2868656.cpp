#include <bits/stdc++.h>
#define cin fin
#define cout fout
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int t,l,c,a,b;
void Euclid(int a,int b)
{
    if(b==0)
        c=a;
    else
    Euclid(b,a%b);
}
int main()
{
    cin>>t;
    for(l=1;l<=t;l++)
    {
        cin>>a>>b;
        Euclid(a,b);
        cout<<c<<'\n';
    }
    return 0;
}
