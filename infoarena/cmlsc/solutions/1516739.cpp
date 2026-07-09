#include <iostream>
#include<limits.h>
#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{
    int M,N,i,j,A[100],B[100],S[100][100];
    cin>>N>>M;
    for(i=1;i<=N;i++) cin>>A[i];
    for(j=1;j<=M;j++) cin>>B[j];
    for(i=1;i<=N;i++)
    for(j=1;j<=M;j++)
    if(A[i]==B[j]){S[i][j]=S[i-1][j-1]+1; cout<<A[i]<<" ";}
    else S[i][j]=max(S[i][j-1],S[i-1][j]);
    cout <<S[N][M]<< endl;
    return 0;
}
