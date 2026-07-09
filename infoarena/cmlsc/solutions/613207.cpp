#include <iostream>
#include <fstream>

using namespace std;

int m,n;
int a[1026],b[1026],c[1026],q[1026][1026];
int k;

int max(int x, int y)
{
    if (x>y)
        return x;
    else
        return y;
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin>>m>>n;
    for(int i=1;i<=m;i++)
        fin>>a[i];
    for(int i=1;i<=n;i++)
        fin>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if (a[i]!=b[j])
                q[i][j]=max(q[i][j-1], q[i-1][j]);
            else
            {
                q[i][j]=1+max(q[i][j-1], q[i-1][j]);
                c[k]=b[j];
                k++;
            }
    fout<<q[m][n]<<endl;
    for (int i=0;i<k;i++)
        fout<<c[i]<<" ";

    fin.close();
    fout.close();
    return 0;
}
