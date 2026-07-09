#include <iostream>
#include <fstream>
#include <algorithm>

//LCS longest common subsequence

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void read_from_file(int m,int n,int x[],int y[])
{
    for(int i=0;i<m;i++)
        f>>x[i];
    for(int j=0;j<n;j++)
        f>>y[j];
}
//length of the LFC
int len_lfc(int m, int n, int x[],int y[],int count[],int &ct)
{
    
    
    //int **c = new int [m,n];
    int **c = new int*[m+1];
    for(int i = 0; i <= m; ++i) 
    {
        c[i] = new int[n+1];
    }
    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        c[0][j]=0;
    }
    //int c[m][n]; c[m-1][n-1]
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                count[++ct] = i-1;
            }
            else
            {
                c[i][j] = max(c[i][j-1],c[i-1][j]);
            }
     //for(int i=1;i<=m;i++,cout<<"\n")
        //for(int j=1;j<=n;j++)
            //cout<<c[i][j]<<" ";
    return c[m][n];
}
int main()
{
    int n,m,ct=0;
    f>>m>>n;
    int *count = new int[m];
    int x[1024],y[1024];
    read_from_file(m,n,x,y);
    g<<len_lfc(m,n,x,y,count,ct)<<"\n";
    for(int i=1;i<=ct;i++)
        g<<x[count[i]]<<" ";
    return 0;
}