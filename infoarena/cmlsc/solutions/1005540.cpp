#include <cstdio>
#include <iostream>
using namespace std;

int s1[1069],s2[1069],m[1069][1069];


int main()
{
    FILE *in=fopen ("cmlsc.in", "r");
    FILE *out=fopen ("cmlsc.out", "w");
    int N,M,i,j;
    fscanf (in, "%d %d", &M, &N);
    for (i=1;i<=M;i++)
        fscanf (in, "%d ", &s2[i]);
    for (i=1;i<=N;i++)
        fscanf (in, "%d ", &s1[i]);
    int p[1069],k=0;
    for (i=1;i<=N;i++)
        for (j=1;j<=M;j++)
            if (s1[i]==s2[j])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=max(m[i-1][j],m[i][j-1]);
    i=N;
    j=M;
    while (m[i][j])
    {
        while (m[i][j]==m[i][j-1]) j--;
        while (m[i][j]==m[i-1][j]) i--;
        p[++k]=s1[i];
        i--,j--;
    }
    fprintf (out, "%d\n", m[N][M]);
    for (i=k;i>0;i--)
        fprintf (out, "%d ", p[i]);
    fclose(in);
    fclose(out);
    return 0;
}
