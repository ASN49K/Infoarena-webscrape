#include    <iostream>
#include    <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int FindNumber(unsigned int x, unsigned int v[],unsigned int poz_inceput, unsigned int lungime_sir){
    for(unsigned int i{poz_inceput}; i < lungime_sir; ++i){
        if(x == v[i])
            return i;
    }
    return -1;
}

int main()
{
    unsigned int M, N, v[1030], w[1030];
    fin >> M >> N;

    for(unsigned int i{0}; i < M; ++i)
        fin >> v[i];
    for(unsigned int i{0}; i < N; ++i)
        fin >> w[i];

    unsigned int j{0}, nrAfisate{0};
    for(unsigned int i{0}; i < N; ++i){
        int pozitie = FindNumber(w[i], v, j, M);
        if(pozitie != -1){
            j = pozitie;
            ++nrAfisate;
        }
        else
            w[i] = 0;
    }

    fout << nrAfisate << "\n";
    for(unsigned int i{0}; i < N; ++i)
        if(w[i]) fout << w[i] << " ";


    fin.close();
    fout.close();
    return 0;
}
