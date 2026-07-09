#include <cstdio>
#include <iostream>
using namespace std;

int s1[1069],s2[1069],m[1069][1069];


int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    int N,M,i,j;
    scanf ("%d %d", &M, &N);
    for (i=1;i<=M;i++)
        scanf ("%d ", &s2[i]);
    for (i=1;i<=N;i++)
        scanf ("%d ", &s1[i]);
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
    printf ("%d\n", m[N][M]);
    for (i=k;i>0;i--)
        printf ("%d ", p[i]);
    return 0;
}
