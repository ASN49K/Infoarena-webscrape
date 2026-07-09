#include <iostream>
#include <fstream>
#define MAX 1024
using namespace std;
int m, n, a[MAX], b[MAX];
int c[MAX][MAX], solution[MAX], nr;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int maxim(int a, int b)
{
    return a > b ? a : b;
}
void Length()
{
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
            {
                c[i][j] = 1 + c[i-1][j-1];
            }
            else
            {
                c[i][j] = maxim(c[i-1][j], c[i][j-1]);
            }
        }
    }

}
void Decode()
{
    for(int i = m; i > 0; i--)
    {
        for(int j = n; j > 0; j--)
        {
            if(a[i] == b[j])
                solution[++nr] = a[i];
            else if(c[i-1][j] > c[i][j-1])
                i--;
            else
                j--;
        }
    }
}
int main()
{
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
        fin >> b[i];
    Length();
    Decode();
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i==0 && j==0)
                cout<<0<<" ";
            else if(i==0)
                cout<<b[j]<<" ";
            else if(j==0)
                cout<<a[i]<<" ";
            else
                cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    fout << nr << "\n";
    for(int i = nr; i > 0; i--)
        fout << solution[i] << " ";
    return 0;
}
