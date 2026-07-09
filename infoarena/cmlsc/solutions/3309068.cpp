//#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,A[1030],B[1030],M[1030][1030],T[1030],q;
stack <int> S;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)  {cin>>A[i];}
    for(int j=1;j<=m;++j) cin>>B[j];
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=m;++j)
        {
            int a=A[i]==B[j];
            M[i][j]=max(a + M[i-1][j-1], max(M[i-1][j],M[i][j-1]));
        }
    cout<<M[n][m]<<endl;

    int i=n,j=m;
    while(i>0 && j>0 && M[i][j])
    {
        if(A[i]==B[j]) {S.push(A[i]); i--, j--;}
        else if(M[i][j]==M[i-1][j]) i--;
        else if(M[i][j]==M[i][j-1]) j--;
    }
while(!S.empty())
{
    cout<<S.top()<<" ";
    S.pop();
}
    return 0;
}
