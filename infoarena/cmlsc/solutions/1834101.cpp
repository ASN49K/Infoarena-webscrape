#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A , B , V1[1030], V2[1030];
int T[1030][1030] = {0} , R[1030] , r = 0;

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
            {
                T[i][j] = T[i-1][j-1] + 1;
                r = T[i][j];
                R[r] = V1[i];
            }
            else
            {
                T[i][j] = max(T[i-1][j] , T[i][j-1]);
            }
        }
    }
    for(int i = 1; i <= A; i++)
    {
        for(int j = 1; j<= B; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }
    fout << T[A][B] << endl;
    for(int q = 1; q <= T[A][B]; q++)
        fout << R[q] << " ";
}

int main()
{
    Read();
    cmlsc();
    return 0;
}
