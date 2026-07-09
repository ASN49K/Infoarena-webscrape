#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A , B , V1[1030], V2[1030];
int T[1030][1030] = {0} , R[1030] , vf = 0;

void Read()
{
    fin >> A >> B;
    for(int i = 1; i <= A; i++)
        fin >> V1[i];
    for(int j = 1; j <= B; j++)
        fin >> V2[j];
}

void cmlsc()
{
    for(int i = 1; i <= A; i++)
    {
        for(int j = 1; j <= B; j++)
        {
            if(V1[i] == V2[j])
                T[i][j] = T[i-1][j-1] + 1;
            else
                T[i][j] = max(T[i-1][j] , T[i][j-1]);
        }
    }
}

void afisare()
{
    int a = A;
    int b = B;
    while(a != 0 && b != 0)
    {
        if(V1[a] == V2[b])
        {
            vf++;
            R[vf] = V1[a];
            a--;
            b--;
        }
        else
        {
            if(T[a][b] == T[a-1][b])
                a--;
            else
                b--;
        }
    }
    fout << T[A][B] << endl;
    for(int q = vf; q >= 1; q--)
    {
        fout << R[q] << ' ';
    }
}

int main()
{
    Read();
    cmlsc();
    afisare();
    return 0;
}
