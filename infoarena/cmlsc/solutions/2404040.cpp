#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

#define maxim(a, b) ( (a > b) ? a : b )
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;


int main()
{
    int i, j;

    //Citirea din fisier
    fin >> M >> N;
    for(i = 1; i <= M; ++i)
        fin >> A[i];
    for(i = 1; i <= N; ++i)
        fin >> B[i];

    //Construirea matricei D
    for(i = 1; i <= M; ++i)
        for(j = 1; j <= N; ++j){
            if(A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
        }

    //Pastram in sir[] cel mai lung subsir comun
    i = M;
    j = N;
    while(i){
        if(A[i] == B[j]){
            sir[++bst] = A[i];
            --i;
            --j;
        }
        else if(D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    }

    //Afisam lungimea sirului si afisam sirul pe o linie nou
    fout << bst << "\n";
    for(i = bst; i > 0; --i)
        fout << sir[i] << " ";


    fin.close();
    fout.close();
    return 0;
}
