#include <iostream>
#include <fstream>
#define NMAX 1024
#define maxim(a,b) ((a>b) ? a:b)
using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

void tabel();
int detabel();

int A[NMAX], B[NMAX], M, N, result[NMAX][NMAX], r[NMAX];



int main()
{
    int k;
    if (input)
    {

        input >> M >> N;
        if (M==0 || N==0)
        {
            cout<< " empty file";
            return 0;
        }

        for (int i=1; i<=M; i++) input >> A[i];
        for (int i=1; i<=N; i++) input >> B[i];

        tabel();

        k=result[M][N];

        output<<k<<endl;

        k=detabel();

        for (int i=k-1; i>0; i--) output << r[i] << " ";
        output<<r[0];
    }
    else cout<< " not open ";




    return 0;
}

void tabel()

{
    int i,j;

    for (i=1; i<=M; i++)
        for (j=1; j<=N; j++)
            if (A[i]==B[j])
                result[i][j]=1+result[i-1][j-1];
            else result[i][j] = maxim(result[i-1][j],result[i][j-1]);


}

int detabel()
{
    int i,j,aux=0;

    for (i=M; i>=1;)
        for (j=N; j>=1;)
                if (A[i]==B[j])
                {
                    r[aux++]=A[i];
                    i--;
                    j--;
                }
                else if (result[i-1][j]<result[i][j-1])
                    j--;
                else
                    i--;
    return aux;

}
