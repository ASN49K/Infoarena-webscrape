#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int c[1026][1026];
char sol[1026];

short int LCS (char *a , short int max_a, char *b, short int max_b)
{
    for(short int i = 0; i <= max_a; i++) c[i][0] = 0;
    for(short int j = 0; j <= max_b; j++) c[0][j] = 0;
    for(short int i = 1; i <= max_a; i++)
    {
        for(short int j = 1; j <= max_b; j++)
        {
            if(a[i] == b[j]) {c[i][j]=c[i-1][j-1]+1; sol[c[i][j]]=a[i];}
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    return c[max_a][max_b];

}


int main()
{
    short int max_a, max_b;
    char a[1026], b[1026];
    short int len;
    fin>>max_a>>max_b;
    for(short int i = 1; i <= max_a; i++) fin>>a[i];
    for(short int i = 1; i <= max_b; i++) fin>>b[i];
    len = LCS(a, max_a, b, max_b);
    fout<<len<<'\n';
    for(short int i = 1; i <= len; i++) fout<<(int)sol[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
