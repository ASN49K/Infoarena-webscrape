#include <iostream>
#include <fstream>
#define NMAX 1024
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int N, M;
int sequenceOne[NMAX];
int sequenceTwo[NMAX];

int subsequenceTable[NMAX][NMAX];
int arrowTable[NMAX][NMAX];

void TraceBack(int x, int y)
{
    if(arrowTable[x][y] == 2)
        return;

    if(arrowTable[x][y] == 0 && sequenceOne[x] == sequenceTwo[y])
    {
        TraceBack(x-1,y-1);
        fo << sequenceOne[x] << " ";
        cout<<sequenceOne[x];
    }
    else if(arrowTable[x][y] == -1)
        TraceBack(x, y - 1);
    else if(arrowTable[x][y] == 1)
        TraceBack(x - 1, y);
}


int main()
{
    fi >> N >> M;
    subsequenceTable[0][0] = 0;
    arrowTable[0][0] = 2;
    for(int i = 1; i <= N; ++i)
    {
        fi >> sequenceOne[i];
        subsequenceTable[i][0] = 0;
        arrowTable[i][0] = 2;
    }
    for(int i = 1; i <= M; ++i)
    {
        fi >> sequenceTwo[i];
        subsequenceTable[0][i] = 0;
        arrowTable[i][0] = 2;
    }

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(sequenceOne[i] == sequenceTwo[j])
            {
                subsequenceTable[i][j] = subsequenceTable[i-1][j-1] + 1;
            }
            else if(subsequenceTable[i-1][j] > subsequenceTable[i][j-1])
            {
                subsequenceTable[i][j] = subsequenceTable[i-1][j];
                arrowTable[i][j] = 1;
            }
            else
            {
                subsequenceTable[i][j] = subsequenceTable[i][j-1];
                arrowTable[i][j] = -1;
            }
        }
    }
    fo << subsequenceTable[N][M]<<"\n";
    TraceBack(N, M);

}
