#include <fstream>
#include <iostream>
using namespace std;
int d[1024][1024];
int main()
{
    int i, j, m, n;
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>m>>n;
    int a[m];
    int b[n];
    for(i=1;i<=m;i++)
    in>>a[i];
    for(i=1;i<=n;i++)
    in>>b[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
    out<<d[m][n]<<endl;
    int lg=d[m][n] +1;
    int v[d[m][n] + 1]; i=m; j=n;
    while(d[m][n]>0){
        if(d[i-1][j] == d[m][n]) --i;
        else if(d[i][j-1] == d[m][n]) --j;
        else{v[d[m][n]] = a[i];
            --i;--j;--d[m][n];}
    }
    i=1;
    while(i<lg){
        out<<v[i]<<" ";
        i++;
    }
    return 0;
}
