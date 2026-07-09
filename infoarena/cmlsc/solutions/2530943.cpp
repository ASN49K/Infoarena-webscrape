#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M,N,A[1030],B[1030],MAX,C[1030];

int main()
{
    fin >> M >> N;
    int i,j,poz=1;
    for (i=1;i<=M;++i)
    {
        fin >> A[i];
    }
    for (i=1;i<=N;++i)
    {
        fin >> B[i];
    }
    for (i=1;i<=M;++i)
    {
        int gasit=0;
        for (j=poz;j<=N && gasit==0;++j)
        {
            if (A[i]==B[j])
            {
                poz=j;
                gasit=1;
                ++MAX;
                C[MAX]=A[i];
            }
        }
    }
    fout << MAX << '\n';
    for (i=1;i<=MAX;++i)
    {
        fout << C[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
