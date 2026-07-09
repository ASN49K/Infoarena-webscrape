#include <iostream>
#include <fstream>
#define NMAX 1024
using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

int A[NMAX], B[NMAX], M, N, result[NMAX], k=1, indices[NMAX];

void bkt (int x, int y)
{
    if ((x<M) && (y<N))
    {
        if (A[x]==B[y])
        {
            if (indices[k-1]!=x)
            {
             indices[k]=x;
             result[k-1]=A[x];
             k++;
             bkt(x+1,y+1);
            }
        }
        bkt(x+1,y);
        bkt(x,y+1);

    }
}

int main()
{
    indices[0]=1025;
    if (input)
    {

        input >> M >> N;
        if (M==0 || N==0)
        {
            cout<< " empty file";
            return 0;
        }
        for (int i=0; i<M; i++) input >> A[i];
        for (int i=0; i<N; i++) input >> B[i];

        bkt(0, 0);

        output<< k-1 <<endl;
        for (int i=0; i<k-1; i++)
            if (i<k-2) output<<result[i]<<" ";
            else output<<result[i];




    }
    else cout<< " not open ";




    return 0;
}
