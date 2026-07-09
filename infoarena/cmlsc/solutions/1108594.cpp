#include <iostream>
#include <fstream>
#define N_MAX 1025

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int N, M, n[N_MAX], m[N_MAX], c[N_MAX][N_MAX], sol[N_MAX], is;

int main()
{
    in >> N >> M;
    for(int i = 1; i <= N; i++)
        in >> n[i];
    for(int i = 1; i <= M; i++)
        in >> m[i];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            if(n[i] == m[j])
                c[i][j] = max(c[i][j], c[i - 1][j - 1] + 1);
        }
    }
    /*for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= M; j++)
            cout << c[i][j] << " " ;
        cout << endl;
    }*/
    out << c[N][M] << '\n';
    int i = N, j = M;
    while(i != 0)
    {
        if(n[i] == m[j])
        {
            sol[is++] = n[i--];
            j--;
            //cout << i <<" " << j << endl;
        }
        else if(c[i - 1][j] < c[i][j - 1]) j--;
        else i--;
    }
    for(int i = is - 1; i >= 0; i--)
        out << sol[i] << " ";
    return 0;
}
