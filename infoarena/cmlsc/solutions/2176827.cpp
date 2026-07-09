#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int A[1024], B[1024], M, N, common = 0, C[1024];
        fin >> M >> N;
            for(int i = 1; i<=M; i++)
                 fin >> A[i];
            for(int i = 1 ; i<=N ; i++)
                 fin >> B[i];

        for(int i = 1 ; i<=M ; i++)
            for(int j = 1 ; j<=N ; j++)
                if(A[i] == B[j])
                {
                    ++common;
                    C[common] = A[i];
                }
        fout << common <<"\n";
            for(int i = 1; i<=common ; i++)
                fout << C[i]<<" ";

    return 0;


}
