#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int LCSMatrix[1025][1025], v1[1025], v2[1025], n, m;
int maximum(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
void printLCS(int i,int j)
{
    if(i<1 || j<1)
        return;

    if(LCSMatrix[i][j]==LCSMatrix[i-1][j-1]+1 && LCSMatrix[i-1][j]==LCSMatrix[i][j-1])
    {
        printLCS(i-1,j-1);
        out<<v1[i]<<' ';
    }
    else
    {
        if(LCSMatrix[i-1][j]>LCSMatrix[i][j-1])
            printLCS(i-1,j);
        else
            printLCS(i,j-1);
    }
}
void LCS()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v1[i] == v2[j])
                LCSMatrix[i][j]=LCSMatrix[i-1][j-1] + 1;
            else
                LCSMatrix[i][j]=maximum(LCSMatrix[i-1][j],LCSMatrix[i][j-1]);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>v1[i];
    for(int i=1;i<=m;i++)
        in>>v2[i];
    LCS();
    out<<LCSMatrix[n][m]<<'\n';
    printLCS(n,m);
    return 0;
}
