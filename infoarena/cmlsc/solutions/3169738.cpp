#include <fstream>
#include <string>
#define NM 1025


using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");


int A[NM],B[NM];
int C[NM][NM];
int rez[NM];
int n,m;
void dp()
{
    int ras=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(A[i]==B[j])
            C[i][j]=C[i-1][j-1]+1;
        else if(C[i-1][j]>=C[i][j-1])
            C[i][j]=C[i-1][j];
        else
            C[i][j]=C[i][j-1];

    for(int i=n,j=m;i;)
    if(A[i]==B[j])
        rez[++ras]= A[i],i--,j--;
    else if(C[i-1][j]>C[i][j-1])
            i--;
        else
            j--;

    cout<<ras<<"\n";
    for(int i=ras;i;i--)
        cout<<rez[i]<<" ";


}


int main()
{

   cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>A[i];
    for(int j=1;j<=m;j++)
        cin>>B[j];
    dp();

}
