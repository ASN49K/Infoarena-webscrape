#include <cstdio>
#include <cstdlib>

FILE * fin = fopen("cmlsc.in","r");
FILE * fout = fopen("cmlsc.out","w");

int d[1024][1024];
int a[1024];
int b[1024];
int n,m;

inline int maxl(int a, int b)
{
    return a>b?a:b;
}

int main()
{
    fscanf(fin,"%d %d",&n,&m);
    for (int i=0; i<n; i++)
        fscanf(fin,"%d",&a[i]);
    int max=-1;
    int mi,mj;
    for (int i=0; i<m; i++)
    {
        fscanf(fin,"%d",&b[i]);
        d[0][i]=(a[0]==b[i])+(i==0)?0:d[0][i-1];
        if (d[0][i]>max)
        {
            max=d[0][i];
            mi=0; mj=i;
        }
    }
    for (int i=1; i<n; i++)
    {
        d[i][0]=(a[i]==b[0])+d[i-1][0];
        if (d[i][0]>max)
        {
            max=d[i][0];
            mi=i; mj=0;
        }
    }
    for (int i=1; i<n; i++)
        for (int j=1; j<m; j++)
        {
            d[i][j]=maxl(d[i-1][j],d[i][j-1]);
            if ((a[i]==b[j])&&(d[i-1][j-1]+1>d[i][j]))
                d[i][j]=d[i-1][j-1]+1;
            if (d[i][j]>max)
            {
                max=d[i][j];
                mi=i; mj=j;
            }
        }  
    fprintf(fout,"%d\n",max);
    m=0;
    while (max)
    {
        if (mi&&(max==d[mi-1][mj]))
        {
            mi--; 
            continue;    
        }
        if (mj&&(max==d[mi][mj-1]))
        {
            mj--; 
            continue;    
        }
        //if (mi&&mj&&(a[mi]=b[mj])&&(max==d[mi-1][mj-1]+1))
        //{    
            b[m++]=a[mi];
            mi--; mj--;
            max--;
        //    continue;
        //}
    }
    for (int i=m-1; i>=0; i--)
        fprintf(fout,"%d ",b[i]);
    fputc('\n',fout);
    fclose(fin);
    fclose(fout);
    return 0;
}
