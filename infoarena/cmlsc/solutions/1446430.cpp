#include <fstream>
using namespace std;
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int main()
{
    int n=0,m=0,i=0,j=0,t=0,c[1025]={0},a[1025]={0},b[1025]={0},x=0;
    fscanf(f,"%d %d",&m,&n);
    for(i=1;i<=m;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&b[i]);
    x=1;
    for(i=1;i<=m;i++)
    {
        for(j=x;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                x=j;
                t++;
                c[t]=a[i];
            }
        }
    }
    fprintf(g,"%d\n",t);
    for(i=1;i<=t;i++)
        fprintf(g,"%d ",c[i]);
    return 0;
}
