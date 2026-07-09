#include <bits/stdc++.h>
using namespace std;

int main()
{ ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;
f>>t;

int a[t][2], i;
for (i=0;i<t;i++)
    for(int j=0;j<2;j++) f>>a[i][j];
int r[t];
 for (i=0;i<t;i++) r[i]=1;

for (i=0;i<t;i++){

    int m=max(a[i][0], a[i][1]);

    for(int j=1;j<m;j++)
            {
            if(a[i][1]%j==0 && a[i][0]%j==0) { r[i]=j;}}


} for (i=0;i<t;i++) g<<r[i]<<endl;
f.close();
g.close();
    return 0;
}
