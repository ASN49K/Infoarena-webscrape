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
        fscanf(fin,"%d",&b[i]);

    for (int i=1; i<n; i++)
        for (int j=1; j<m; j++)
        {
            d[i][j]=maxl(i?d[i-1][j]:0,j?d[i][j-1]:0);
            if ((a[i]==b[j])&&((i&&j)?d[i-1][j-1]:0+1>d[i][j]))
                d[i][j]=(i&&j)?d[i-1][j-1]:0+1;
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
        if (max==mi?d[mi-1][mj]:0)
        {
            mi--; 
            continue;    
        }
        if (max==mj?d[mi][mj-1]:0)
        {
            mj--; 
            continue;    
        }
        b[m++]=a[mi];
        mi--; mj--;
        max--;
    }
    for (int i=m-1; i>=0; i--)
        fprintf(fout,"%d ",b[i]);
    fputc('\n',fout);
    fclose(fin);
    fclose(fout);
    return 0;
}
