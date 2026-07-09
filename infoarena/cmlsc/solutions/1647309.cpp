#include <iostream>
#include <fstream>

#define minim(a,b) ((a<b)? a : b)
#define maxim(a,b) ((a>b)? a : b)

using namespace std;
int main()
{
int n, m, v1[1025], v2[1025], v3[1025], k=0, j=1, x=1;
int mi, mx;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

f>>n>>m;
for(int i=1; i<=n; i++)
    f>>v1[i];
for(int i=1; i<=m; i++)
    f>>v2[i];

if(minim(n,m)==n)
{
    for(int i=1; i<=n; i++)
    {   j=x;
        while(j<=m)
        {
            if(v1[i]==v2[j]){v3[++k]=v1[i]; j++; x=j; break;}
            j++;
        }
    }

}
else
    for(int i=1; i<=m; i++)
    {   j=x;
        while(j<=n)
        {
            if(v2[i]==v1[j]){v3[++k]=v2[i]; j++; x=j; break;}
            j++;
        }
    }


g<<k<<endl;
for(int i=1; i<=k; i++)
    g<<v3[i]<<" ";

g.close();
f.close();

return 0;
}
