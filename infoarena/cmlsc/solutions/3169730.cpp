#include <fstream>
#include <string>
#define NM 1025


using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");


char A[NM],B[NM];
string C[NM][NM];
int n,m;
void dp()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(A[i]==B[j])
            C[i][j]=C[i-1][j-1] + A[i];
        else
        {
            if(C[i-1][j].length()>=C[i][j-1].length())
                C[i][j]= C[i-1][j];
            else
                C[i][j]=C[i][j-1];

        }
    }
    cout<<C[n][m].length()<<"\n";
    for(int i=0;i<C[n][m].length();i++)
        cout<<C[n][m][i]<<" ";
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
