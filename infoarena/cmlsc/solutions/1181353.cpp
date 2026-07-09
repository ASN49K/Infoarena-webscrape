/*
    Keep It Simple!
*/

#include<fstream>
#include<vector>
using namespace std;

#define MaxN 1025

int A[MaxN],B[MaxN],Mat[MaxN][MaxN],N,M;
vector<int> Final;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> N >> M;
    for(int i=1;i<=N;i++) f >> A[i];
    for(int i=1;i<=M;i++) f >> B[i];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            if(A[i] == B[j])
                Mat[i][j] = Mat[i-1][j-1] + 1;
            else
                Mat[i][j] = max(Mat[i-1][j],Mat[i][j-1]);
        }
    g << Mat[N][M] << '\n';

    int x = N, y = M;

    while( x >= 1 && y >= 1)
    {
        if(A[x] == B[y])
        {
            Final.push_back(A[x]);
            x--;
            y--;
        }
        else if(Mat[x-1][y] > Mat[x][y-1]) x--;
        else y--;
    }
    for(size_t i = Final.size() - 1; i > 0; i--)
        g << Final[i] <<  " ";
        g << Final[0];
}
