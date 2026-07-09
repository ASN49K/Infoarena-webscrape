#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int C[1025][1025];

int main()
{
    int M, N;
    fin >> M >> N;

    int A[1025], B[1025];
    for(int i=1; i<=M; i++)
        fin >> A[i];
    for(int i=1; i<=N; i++)
        fin >> B[i];

    for(int i=0; i<=M; i++)
        C[i][0] = 0;
    for(int j=0; j<=N; j++)
        C[0][j] = 0;

    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            if(A[i] == B[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                if(C[i-1][j] > C[i][j-1])
                    C[i][j] = C[i-1][j];
                else
                    C[i][j] = C[i][j-1];


    int sol[1025];
    int i = M;
    int j = N;
    int len = C[M][N];

    fout << len << '\n';

    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            sol[len] = A[i];
            len--;
            i--;
            j--;
        }
        else
            if(C[i-1][j] > C[i][j-1])
                i--;
            else
                j--;
    }



    for(int i = 1; i<=C[M][N]; i++)
        fout << sol[i] << ' ';
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
