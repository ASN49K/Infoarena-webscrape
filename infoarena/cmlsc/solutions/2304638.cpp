#include <bits/stdc++.h>
#define nmax 1024
using namespace std;
ifstream raul1("cmlsc.in");
ofstream raul2("cmlsc.out");
int main()
{
    short n,m,x;
    raul1>>m>>n;
    vector<short> a(m,0),b(n,0),sir(nmax,0);
    vector<vector<short> > c(nmax, vector<short>(nmax,0));
    for(short i=1;i<=m;i++){
        raul1>>a[i];
    }
    for(short i=1;i<=n;i++){
        raul1>>b[i];
    }
    for(short i=1;i<=m;i++){
        for(short j=1;j<=n;j++){
            if(a[i] == b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j], c[i][j-1]);
        }
    }
    short bst=0;
    for(short i=m,j=n;i;)
        if(a[i]==b[j])
           sir[++bst]=a[i], i-- , j--;
        else if (c[i-1][j]<c[i][j-1])
            j--;
        else
            i--;
     raul2<<bst<<"\n";
    for(short i=bst;i>0;i--){

        raul2<<sir[i]<<" ";
    }


    return 0;
}
