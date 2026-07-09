#include <fstream>
using namespace std;
ifstream fin("scmax.in");
ofstream fout("scmax.out");

int N, K, X, v[100001];

int main()
{
    fin >> N;
    for(int i = 1; i <= N; ++ i)
    {
        fin >> X;
        if(v[K] < X)
            v[++K] = X;
        else
        {
            int st = 1, dr = K, mij;
            while(st <= dr)
            {
                mij = (st + dr) / 2;
                if(v[mij] < X)
                    st = mij + 1;
                else
                    dr = mij - 1;
            }
            v[st] = X;
        }
    }
    fout << K << '\n';
    for(int i = 1; i <= K; ++ i)
        fout << v[i] << ' ';
    return 0;
}
