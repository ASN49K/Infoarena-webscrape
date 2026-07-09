#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

//1024
int a[1200][1200],n,m,v1[1200],v2[1200];
int b[1200],q;

void recons_vect()
{int i=n,j=m;
while(i!=0 && j!=0)
        if(v1[i]==v2[j])
            {b[++q]=v1[i];
            i--;
            j--;
            }
        else
            {
            if(a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
            }

}

int main()
{int i,j;
ifstream f("cmlsc.in");
FILE *g=fopen("cmlsc.out","w");

f>>n>>m;
for(i=1;i<=n; i++)
    f>>v1[i];
for(i=1;i<=m; i++)
    f>>v2[i];

for(i=1;i<=n; i++)
    for(j=1;j<=m; j++)
        {if(v1[i]==v2[j])
            a[i][j]=a[i-1][j-1]+1;
        else
            if(a[i][j-1]>a[i-1][j])
                a[i][j]=a[i][j-1];
            else
                a[i][j]=a[i-1][j];
        }


recons_vect();
fprintf(g,"%d\n",q);
for(i=q;i>=1; i--)
    fprintf(g,"%d ",b[i]);




return 0;
}
