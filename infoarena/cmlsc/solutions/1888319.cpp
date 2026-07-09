#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a,b,v[2000][2000];
int max(int a,int b)
{
    if(a<=b)
    return b;
    else
    return a;
}
void recursiv(int i,int j)
{
    if(i!=1&&j!=1)
    {
        if(v[i-1][j]>v[i][j-1])
            recursiv(i-1,j);
        if(v[i-1][j]<v[i][j-1])
            recursiv(i,j-1);
        if((v[i-1][j]==v[i][j-1]))
        {
            recursiv(i-1,j-1);
            if(v[i][j-1]!=v[i][j])
            g<<v[i][0]<<" ";
        }
    }
}
int main()
{
    f>>a>>b;
    for(int i=2;i<=a+1;i++)
    f>>v[0][i];
    for(int i=2;i<=b+1;i++)
    f>>v[i][0];
    for(int i=2;i<=b+1;i++)
    {
        for(int j=2;j<=a+1;j++)
        {
            if(v[0][j]==v[i][0])
            v[i][j]=v[i-1][j-1]+1;
           else
            v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
    }
    g<<v[b+1][a+1]<<'\n';
    recursiv(b+1,a+1);
    return 0;
}
