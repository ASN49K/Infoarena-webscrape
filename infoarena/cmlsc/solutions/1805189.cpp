#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const int NMAX=1024;
int n,m,x[NMAX+5],y[NMAX+5],d[NMAX+5][NMAX+5],l=0,s[NMAX+5];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=m;i++)
        cin>>y[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(x[i]==y[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);}}
    cout<<d[n][m]<<"\n";
    int i=n,j=m;
    while(i && j && l<d[n][m]) {
        if(x[i]==y[j]) {
            l++;
            s[l]=x[i];
            i--;
            j--;}
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else
            i--;}
    for(int i=l;i>=1;i--)
        cout<<s[i]<<" ";
    return 0;
}
