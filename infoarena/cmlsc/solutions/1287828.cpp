#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define N 1025

int A[N], B[N], M[N][N], S[N], n, m;

void drum(int i, int j, int s)
{
    if(s)
    {
        if(A[i]==B[j])
        {
            drum(i-1, j-1, s-1);
            out << A[i] << " ";
        }
        else if(M[i-1][j] == s)
            drum(i-1, j, s);
        else if(M[i][j-1] == s)
            drum(i, j-1, s);
    }
}


int main()
{
    in >> n >> m;

    for(int i=1;i<=n;i++)
        in >> A[i];

    for(int i=1;i<=m;i++)
        in >> B[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i] == B[j])
                M[i][j] = M[i-1][j-1] + 1;
            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);



    out << M[n][m] << "\n";

    drum(n, m, M[n][m]);


    in.close();
    out.close();
    return 0;
}
