#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int v[1030][1030];
int n,m;

ifstream fin ("in.in");
ofstream fout ("out.out");

vector<int> a[1];

int main(){

    fin >> n >> m;

    for(int i=2;i<=n+1;++i)
        fin >> v[0][i];
    for(int i=2;i<=m+1;++i)
        fin >> v[i][0];

    for(int i=2;i<=n+1;++i)
        for(int j=2;j<=m+1;++j)
        {
            if(v[0][i]==v[j][0])
            {
                v[j][i]=v[j-1][i-1]+1;
                a[0].push_back(v[0][i]);
            }
            else
            {
                if(v[j-1][i]>v[j][i-1])
                    v[j][i]=v[j-1][i];
                else
                    v[j][i]=v[j][i-1];
            }
        }

    fout << v[m+1][n+1] << "\n";

    int k=-1;
    for(int i=0;i<a[0].size();++i)
        if(k<a[0][i])
        {
            fout<<a[0][i]<<" ";
            k=a[0][i];
        }

    fout << "\n";

    fin.close();
    fout.close();

    return 0;
}
