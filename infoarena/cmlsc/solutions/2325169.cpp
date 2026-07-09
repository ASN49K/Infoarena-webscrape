#include <iostream>
#include <fstream>


int main()
{

    std::ifstream fin("cmlsc.in");
    unsigned int M, N, A[1024], B[1024], C[1024];

    fin >> M >> N;

    for(unsigned int i = 0; i < M; i++)
        fin >> A[i];

    for(unsigned int i = 0; i < N; i++)
        fin >> B[i];

    fin.close();

    unsigned int cnt = 0;
    for(unsigned int i = 0; i < M; i++)
        for(unsigned int j = 0; j < N; j++)
            if(A[i] == B[j] && A[i] && B[j])
            {
                C[cnt] = A[i];
                A[i] = B[i] = 0;
                cnt++;
            }

    std::ofstream fout("cmlsc.out");
    fout << cnt << "\n";
    for(unsigned int i = 0; i < cnt; i++)
        fout << C[i] << " ";
    fout.close();

    return 0;
}
