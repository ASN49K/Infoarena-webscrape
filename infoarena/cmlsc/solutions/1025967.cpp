#include <fstream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
#define DMax 1026

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void Read();
void Solve();
void PrintSubSeq(int i, int j);

int a_length, b_length;
vector<int> a, b;
int mat[DMax][DMax];
deque<int> sol;

int main()
{
    Read();
    Solve();


    fin.close();
    fout.close();
    return 0;
}

void Solve()
{
    for (int i = 1; i <= a_length; ++i)
        for (int j = 1; j <= b_length; ++j)
            if ( a[i] == b[j] )
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max ( mat[i-1][j], mat[i][j-1] );


    fout << mat[a_length][b_length] << '\n';
    PrintSubSeq(a_length, b_length);
}

void PrintSubSeq(int i, int j)
{
    if ( i == 0 || j == 0 )
        return;
    if ( a[i] == b[j] )
    {
        PrintSubSeq(i-1, j-1);
        fout << a[i] << ' ';
        return;
    }
    if ( mat[i-1][j] > mat[i][j-1] )
        PrintSubSeq(i-1, j);
    else
        PrintSubSeq(i, j-1);
}

void Read()
{
    fin >> a_length >> b_length;
    a.resize(a_length + 1);
    b.resize(b_length + 1);
    for (int i = 1; i <= a_length; ++i)
        fin >> a[i];

    for (int i = 1; i <= b_length; ++i)
        fin >> b[i];
}




