#include <bits/stdc++.h>

using namespace std;
ifstream f("biti.in");
ofstream g("biti.out");

int n,m,nr;
char dest[101],cuv[101];
int extrageCuvant(char dest[],char s[],char sep[],int k)
{
    int n=strlen(s),m=strlen(sep),i,ii,j=0;
    for(i=0;i<n;i++)
    {

    }
}
int main()
{
    int i,j,t,z,k;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n;
        z=0;
        for(j=1;j<=n;j++)
        {
            f>>k;
            z=(z^k);
        }
        if(z==0)
            g<<"NU";
        else
            g<<"DA";
        g<<'\n';
    }
}
