#include <iostream>
#include <fstream>

using namespace std;
fstream fout("cmlsc.out", ios::out);

int v[1025][1025], a[1025], b[1025], sol[1025], n, m, sl;
int maxx(int a, int b)
{
    if(a>b) return a;
    return b;
}
void ReadData()
{
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    for (int i=1; i<=n; ++i)
        fin>>a[i];
    for (int i=1; i<=m; ++i)
        fin >> b[i];
    fin.close();
}
void PrintResult()
{
    ofstream fout("cmlsc.out");
    fout<<v[n][m]<<'\n';
    for (int i=1; i<=sl; i++)
        fout<<sol[i]<<' ';
    fout.close();
}
int main()
{
    ReadData();
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            if(i==0 || j==0) v[i][j]=0;
            else if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=maxx(v[i][j-1], v[i-1][j]);

    int i=1, j=1;
    while(i<=n && j<=m)
    {
        if(v[i][j]>sl){
            sl++;
            if(n<m){
                sol[sl]=a[i];
            } else{
                sol[sl]=b[j];
            }
        }
        if(v[i+1][j+1]>sl){
            i++; j++;
        } else if(n>m) i++;
        else j++;
    }
    PrintResult();
    return 0;
}
