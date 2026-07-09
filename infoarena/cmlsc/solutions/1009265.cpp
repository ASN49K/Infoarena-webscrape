#include "stdio.h"
int mat[1026][1026];

int a[1026];
int b[1026];
//#define max(a,b) ((a)<(b)?(b):(a))

int& max(int &a, int& b)
{
    if(a>b)
    {   return a;
    }
    else
    {   return b;
    }
}

void rec(FILE* fout, int n, int m)
{   
    if(n<1||m<1)
    {   return;
    }
    if(mat[n][m]!=mat[n-1][m] && mat[n][m]!=mat[n][m-1])
    {   rec(fout,n-1,m-1); 
        fprintf(fout,"%d ",a[n]);
    }
    else if(mat[n][m]==mat[n-1][m])
    {   rec(fout,n-1,m);
    }
    else if(mat[n][m]==mat[n][m-1])
    {   rec(fout,n,m-1);
    }
}

int main ()
{
    int m,n;
    int i,j;
    FILE *fin=fopen("cmlsc.in","r");    
    FILE *fout=fopen("cmlsc.out","w");    
    fscanf(fin,"%d %d",&n,&m); 
    for(i=1;i<=n;i++)
    {   fscanf(fin,"%d",&a[i]);
    }  
    for(i=1;i<=m;i++)    
    {   fscanf(fin,"%d",&b[i]);
    }

    for(i=1;i<=n;i++)
    {   for(j=1;j<=m;j++)
        {   if(a[i]==b[j])
            {   mat[i][j]=mat[i-1][j-1]+1; 
            }
            else
            {   mat[i][j]=max(mat[i-1][j],mat[i][j-1]); 
            }
        }
    }   
/*
    for(i=1;i<=n;i++)
    {   for(j=1;j<=m;j++)
        {
           printf("%d ",mat[i][j]);  
        }
        printf("\n");
    }
*/
    fprintf(fout,"%d\n",mat[n][m]);

    rec(fout,n,m);
    fprintf(fout,"\n");
    return 0;
}
