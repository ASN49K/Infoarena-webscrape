#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");


int v1[1026],v2[1026];
int lung[1026],cpy[1026],i,n,m;

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v1[i];
    for(i=1;i<=m;i++)
        cin>>v2[i];
    for(i=1;i<=n;i++)
    {
        int lgmax=0;
        for(int j=1;j<=m;j++)
        {
            if(v1[i]!=v2[j])
                lgmax=max(lgmax,lung[j]);
            if(v1[i]==v2[j])
                lung[j]=max(lung[j],lgmax+1);
        }

    }
    int lgmax = *max_element(lung+1,lung+1+m),counter=lgmax;
    cout<<lgmax<<'\n';
    for(i=m;i>=1;i--)
    {
        if(counter==lung[i])
            cpy[counter]=v2[i],counter--;
    }

    for(i=1;i<=lgmax;i++)
        cout<<cpy[i]<<" ";
    return 0;
}
