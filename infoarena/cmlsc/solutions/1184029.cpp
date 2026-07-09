#include <stdio.h>
#include <algorithm>
using namespace std;
FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");
int a,b,A[10001],B[10001],m[10001][10001],i,j,k,an[10001];
int main()
{
    fscanf(f,"%d%d",&a,&b);
    for(i=1;i<=a;i++)
    {
        fscanf(f,"%d",&A[i]);
    }
    for(i=1;i<=b;i++)
    {
        fscanf(f,"%d",&B[i]);
    }
    for(i=1;i<=a;i++)
        for(j=1;j<=b;j++)
            if(A[i]==B[j])
                m[i][j]=1+m[i-1][j-1];
            else
                m[i][j]=max(m[i-1][j],m[i][j-1]);
    i=a;j=b;
    while(i>0 and j>0)
    {
        if(A[i]==B[j])
        {
            k++;an[k]=A[i];i--;j--;
        }
        else
            if(m[i-1][j]<m[i][j-1])
                j--;
             else
                i--;
    }
    fprintf(g,"%d\n",m[a][b]);
    for(i=k;i>0;i--)
        fprintf(g,"%d ",an[i]);
    return 0;
}
