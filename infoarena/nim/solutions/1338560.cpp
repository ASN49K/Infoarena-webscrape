#include    <iostream>
#include    <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, N;
void Read()
{
    int s, x;
    fin >> t;
    for(int i = 1; i <= t; i++)
    {
        s = 0;
        fin >> N;
        for(int j = 1; j <= N; j++)
        {
            fin >> x;
            s = s ^ x;
        }
        if(s)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
}

int main()
{
    Read();
    return 0;
}
