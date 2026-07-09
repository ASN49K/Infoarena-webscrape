#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define N 1025

int A[N], B[N], M[N][N], S[N], n, m, f, lmax;

int main()
{
    in >> n >> m;

    for(int i=1;i<=n;i++)
        in >> A[i];

    for(int i=1;i<=m;i++)
        in >> B[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(A[i] == B[j])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j]=max(M[i-1][j], M[i][j-1]);

            if(M[i][j] > lmax)
            {
                S[++f] = i;
                lmax = M[i][j];
            }
        }

    out << lmax << "\n";

    for(int i=1; i <= f ;i++)
        out << A[S[i]] << " ";

    in.close();
    out.close();
    return 0;
}
