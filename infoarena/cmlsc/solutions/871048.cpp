#include <iostream>
#include <fstream>
#define nmax 1027
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,u,v[nmax],w[nmax],p[nmax],i,j,k;
void citire(){
    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>v[i];
    for(int i=1;i<=n;i++)
        fin>>w[i];
}
bool ok;
int main()
{   k=1;u=0;
    citire();
    for(i=1;i<=m;i++)
    {
        for(j=u+1;j<=n;j++)
        {
            if(v[i]==w[j])
            {
             p[k]=v[i];j++;
             k++;u=j;
             break;
            }
        }
    }
    i=1;
    while(p[i]!=0)
    {
        i++;

    }
    fout<<i-1<<'\n';
    for(j=1;j<=i;j++)
    {   if(p[j]!=0)
        fout<<p[j]<<" ";
    }

    return 0;
}
