#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int c[100][100], sol[100];

int LCS (int *a , int max_a, int *b, int max_b)
{
    for(int i = 0; i <= max_a; i++) c[i][0] = 0;
    for(int j = 0; j <= max_b; j++) c[0][j] = 0;
    for(int i = 1; i <= max_a; i++)
    {
        for(int j = 1; j <= max_b; j++)
        {
            if(a[i] == b[j]) {c[i][j]=c[i-1][j-1]+1; sol[c[i][j]]=a[i];}
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    return c[max_a][max_b];

}


int main()
{
    int a[100], b[100], max_a, max_b;
    int len;
    fin>>max_a>>max_b;
    for(int i = 1; i <= max_a; i++) fin>>a[i];
    for(int i = 1; i <= max_b; i++) fin>>b[i];
    len = LCS(a, max_a, b, max_b);
    fout<<len<<'\n';
    for(int i = 1; i <= len; i++) fout<<sol[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
