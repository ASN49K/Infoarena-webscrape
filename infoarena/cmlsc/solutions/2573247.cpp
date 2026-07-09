#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define cin fin
#define cout fout
#define NMAX 1030
int A[NMAX],B[NMAX],D[NMAX][NMAX],n,m,k,sir[NMAX];
int main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> A[i];
    for (int j=1;j<=m;j++)
        cin >> B[j];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (A[i]==B[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);

    for (int i=n, j=m;i>0;){
        if (A[i]==B[j])
            sir[++k]=A[i], --i, --j;
        else
            if(D[i][j-1]>D[i-1][j])
                --j;
        else
            --i;
    }

    cout << k << "\n";

    for (int i=k;i>=1;i--)
        cout << sir[i] << " ";
    return 0;
}
