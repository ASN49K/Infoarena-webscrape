#include <iostream>
#include <fstream>
#include <memory.h>

using namespace std;

int m[1025][1025],P[1025];

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int i,j,N,M,s1[1025],s2[1025];
    fin>>N>>M;
    for (i=1;i<=N;i++)
        fin>>s1[i];
    for (j=1;j<=M;j++)
        fin>>s2[j];
    memset(m,sizeof(m),0);
    for (i=1;i<=N;i++)
    {
        for (j=1;j<=M;j++)
        {
            if (s1[i]==s2[j])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=max(m[i-1][j],m[i][j-1]);
        }
    }
    int x=m[N][M];
    int y;
    y=x;
    fout<<y<<"\n";
    i=N;
    j=M;
    while (m[i][j])
    {
        while (m[i][j]==m[i-1][j]) i--;
        while (m[i][j]==m[i][j-1]) j--;
        P[x--]=s1[i];
        i--;
        j--;
    }
    for (i=1;i<=y;i++)
        fout<<P[i]<<" ";
    return 0;
}
