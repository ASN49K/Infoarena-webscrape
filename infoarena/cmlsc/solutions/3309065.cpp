//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,A[1030],B[1030],M[1030][1030],T[1030],q;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)  {cin>>A[i];}
    for(int j=1;j<=m;++j) cin>>B[j];
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=m;++j)
        {
            int a=A[i]==B[j];
            int t1=(a + M[i-1][j-1]);
            int t2=M[i-1][j];
            int t3=M[i][j-1];
            M[i][j]=max(a + M[i-1][j-1], max(M[i-1][j],M[i][j-1]));
            if(M[i][j]>q) q=M[i][j],T[i]=1;
            cout<<M[i][j]<<" ";
        }
    cout<<M[n][m]<<endl;

    int i=n,j=m;
    while(i>0 && j>0 && M[i][j])
    {
        if(A[i]==B[j]) {cout<<A[i]<<" "; i--, j--;}
        else if(M[i][j]==M[i-1][j]) i--;
        else if(M[i][j]==M[i][j-1]) j--;
    }

    return 0;
}
