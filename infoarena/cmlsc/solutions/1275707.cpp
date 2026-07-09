#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define Nmax 1026
using namespace std;

int mat[Nmax][Nmax], N, M, A[Nmax], B[Nmax];

int main()
{
    ifstream f("cmlsc.in");
    f>>N>>M;
    for(int i=1;i<=N;++i)
        f>>A[i];

    for(int i=1;i<=M;++i)
        f>>B[i];

    f.close();

    for(int i=0; i<=N;++i)
        for(int j=0;j<=M;++j)
            mat[i][j] = 0;

    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
        {
            if(A[i] == B[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }

    ofstream g("cmlsc.out");
    g<<mat[N][M]<<"\n";
    int i, j;
    vector<int> vec;

    for(i = N; i > 0; --i)
        for(j = M; j > 0; --j)
        {
            if(A[i] == B[j])
            {
                vec.push_back(A[i]);
                if(vec.size() == mat[N][M])
                {
                    i=j=-1;
                }
                --i;
                if(i == 0)
                    j = 0;
            }
        }
    reverse(vec.begin(), vec.end());
    for(auto it=vec.begin(); it != vec.end();++it)
        g<<*it<<" ";
    g.close();
    return 0;
}
