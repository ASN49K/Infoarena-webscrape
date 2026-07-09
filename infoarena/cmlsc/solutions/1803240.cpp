#include <cstdio>
#include <iostream>

using namespace std;
int v[1025],w[1025],d[1025][1025],sol[1025];
int main()
{
    FILE *fin=fopen ("cmlsc.in","r");
    FILE *fout=fopen ("cmlsc.out","w");
    int n,m,i,j,k;
    fscanf (fin,"%d%d",&n,&m);
    for (i=1;i<=n;i++)
        fscanf (fin,"%d",&v[i]);
    for (i=1;i<=m;i++)
        fscanf (fin,"%d",&w[i]);
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            // d[i][j] = subsirul com maxim daca din primul sir iau poz pana la i si din a doilea pana la j
            if (v[i]==w[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    fprintf (fout,"%d\n",d[n][m]);
    i=n;
    j=m;
    k=0;
    while (d[i][j]){
        if (v[i]==w[j]){
            sol[++k]=v[i];
            i--;
            j--;
        }
        else {
            if (d[i-1][j]>d[i][j-1])
                i--;
            else j--;
        }
    }
    for (i=k;i>0;i--)
        fprintf (fout,"%d ",sol[i]);
    return 0;
}
