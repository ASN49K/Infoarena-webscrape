#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,x,y,zed;

int main()
{
    int i;
    fin >> n;
    for(i=1;i<=n;i++){
        fin >> x >> y;
        while(y!=0){
            zed=x%y;
            x=y;
            y=zed;
        }
        fout << x <<"\n";
    }
    return 0;
}
