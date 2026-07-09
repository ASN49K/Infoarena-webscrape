#include <iostream>
#include <fstream>

#define NMax 1030
using namespace std;

int input1[NMax], input2[NMax], T[NMax][NMax], LCS[NMax];
int N, M, K = 0;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{

    //Citire
    in >> N >> M;
    for(int i = 1; i <= N; i++)
        in >> input1[i];
    for(int j = 1; j <= M; j++)
        in >> input2[j];

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(input1[i] == input2[j])
            {
                T[i][j] = T[i-1][j-1] + 1;
            }
            else
            {
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
    }
    int p = N, k = M;
    while(p != 0 && k != 0)
    {
        if(input1[p] == input2[k])
        {
            LCS[K] = input1[p];
            K++;
            p--;
            k--;
        }
        else if(T[p-1][k] < T[p][k-1])
        {
            k--;
        }
        else
        {
            p--;
        }
    }
    out << T[N][M] << endl;
    for(int i = K-1; i >= 0; i--)
    {
        out << LCS[i] << " ";
    }
    return 0;
}
