#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int v[1030][1030];
int a[1030];
int n,m;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int maxim(int i, int j){
    if (i>j)
        return i;
    else return j;
}

int main(){

    fin >> n >> m;

    for(int i=2;i<=n+1;++i)
        fin >> v[0][i];
    for(int i=2;i<=m+1;++i)
        fin >> v[i][0];

    int l=0;

    for(int i=2;i<=n+1;++i)
        for(int j=2;j<=m+1;++j)
        {
            if(v[0][i]==v[j][0])
                v[j][i]=v[j-1][i-1]+1;
            else v[j][i]=maxim(v[j][i-1],v[j-1][i]);
        }

    fout << v[m+1][n+1] << "\n";

    int j=m+1;
    int i=n+1;
    l=0;

    while(v[j][i])
    {
        while (v[j][i]==v[j-1][i])
            j--;
        while (v[j][i]==v[j][i-1])
            i--;
        if(v[j][i]==v[j-1][i-1]+1)
        {
            l++;
            a[l]=v[j][0];
            i--;
            j--;
        }
    }

    for (i=l;i>=1;--i)
    {
        fout<<a[i]<<" ";
    }

    fout << "\n";

    fin.close();
    fout.close();

    return 0;
}
