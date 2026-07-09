#include<stdio.h>
#define MAXN 1025
inline void precalc();
inline int maxim(int a,int b);
FILE*fin,*fout;
int r[MAXN][MAXN];
int s1[MAXN],s2[MAXN];
int cmlsc[MAXN],ult=-1;
int N,M;
int main()
{
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        fscanf(fin,"%d",&s1[i]);
    }
    for(int i=1;i<=M;i++)
    {
        fscanf(fin,"%d",&s2[i]);
    }
    precalc();
    fprintf(fout,"%d\n",r[N][M]);
    int p1=N,p2=M;
    while(p1 && p2)
    {
        if(s1[p1]==s2[p2])
        {
            cmlsc[++ult]=s1[p1];
            p1--;
            p2--;
        }
        else
        {
            if(r[p1-1][p2]>r[p1][p2-1])
            {
                p1--;
            }
            else
            {
                p2--;
            }
        }
    }
    for(int i=ult;i>=0;i--)
    {
        fprintf(fout,"%d ",cmlsc[i]);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
inline void precalc()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(s1[i]==s2[j])
            {
                r[i][j]=r[i-1][j-1]+1;
            }
            else
            {
                r[i][j]=maxim(r[i-1][j],r[i][j-1]);
            }
        }
    }
}
inline int maxim(int a,int b)
{
    return a>b?a:b;
}
