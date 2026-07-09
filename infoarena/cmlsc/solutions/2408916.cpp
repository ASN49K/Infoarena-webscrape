#include <iostream>
#include <fstream>
#define NMAX 1024
using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

int A[NMAX], B[NMAX], M, N, result[NMAX], k=0, frecv[NMAX], resultnew[NMAX];

void bkt (int x, int y)
{
    if ((x<M) && (y<N))
    {
        if (A[x]==B[y])
        {
            result[k++]=A[x];
            bkt(x+1,y+1);
        }
        bkt(x+1,y);
        bkt(x,y+1);

    }

}

int main()
{
    int knew=0;

    if (input)
    {

        input >> M >> N;
        if (M==0 || N==0)
        {
            cout<< " empty file";
            return 0;
        }
        for (int i=0; i<M; i++)
        {
            input >> A[i];
            frecv[A[i]]+=1;
        }
        for (int i=0; i<N; i++) input >> B[i];

        bkt(0, 0);



        for (int i=0; i<k; i++)
            if (frecv[result[i]]>0)
            {resultnew[knew++]=result[i];
             frecv[result[i]]--;
            }

        output<< knew <<endl;
        for (int i=0; i<knew; i++)
            if (i<knew-1) output << resultnew[i]<<" ";
            else output<<resultnew[i];



    }
    else cout<< " not open ";




    return 0;
}
