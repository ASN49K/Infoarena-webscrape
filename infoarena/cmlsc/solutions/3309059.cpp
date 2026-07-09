//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,A[1030],B[1030];
int P(int i, int j)
{
    if(i<=n && j<=m)
    {
        if(A[i]==B[j]) return 1+P(i+1,j+1);
        else return max(P(i+1,j),P(i,j+1));
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int j=1;j<=m;++j) cin>>B[j];
    cout<<P(1,1);
    return 0;
}
