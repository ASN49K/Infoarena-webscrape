//#include <iostream>
#include <fstream>

#define fin cin
#define fout cout

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    short A[1025], M;
    short B[1025], N;

    cin >> M >> N;

    for (int i = 1; i <= M; ++i)
        cin >> A[i];

    for (int i = 1; i <= N; ++i)
        cin >> B[i];

    short C[1025], K = 0;

    for (int p = 1; p <= M; ++p)
    {
        int q = 1;

        short T[1025], U = 0;

        for (int i = p; i <= M; ++i)
        {
            for (int j = q; j <= N; ++j)
                if (A[i] == B[j])
                {
                    T[++U] = A[i];
                    q = j + 1;
                    break;
                }
        }

        //cout << U << '\n';
        //for (int i = 1; i <= U; ++i)
            //cout << T[i] << ' ';

        //cout << "\n\n";

        if (U > K)
        {
            K = U;
            for (int i = 1; i <= K; ++i)
                C[i] = T[i];
        }
    }

    //cout << "FINAL\n";
    cout << K << '\n';
    for (int i = 1; i <= K; ++i)
        cout << C[i] << ' ';
}
