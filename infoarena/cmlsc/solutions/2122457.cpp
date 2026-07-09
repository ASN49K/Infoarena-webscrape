#include <iostream>
#include <fstream>
#define N (1<<10)+1
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int A[N],B[N],MAP[N][N],S[N];
int main()
{
    int n,m,i,j,sol=0;
    in>>n>>m;
    for(i=1;i<=n;i++) in>>A[i];
    for(i=1;i<=m;i++) in>>B[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(A[i]==B[j]) MAP[i][j] = MAP[i-1][j-1] + 1;
            else MAP[i][j] = max(MAP[i-1][j],MAP[i][j-1]);
        }
    out<<MAP[n][m]<<"\n";
    i = n; j = m; sol = MAP[n][m];
    while(i && j){
        if(A[i] == B[j]) S[sol--]=A[i],i--,j--;
        else if(MAP[i-1][j] > MAP[i][j-1]) i--;
        else j--;
    }
    for(i=1;i<=MAP[n][m];i++) out<<S[i]<<" ";
    return 0;
}
