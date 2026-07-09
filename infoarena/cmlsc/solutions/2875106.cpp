#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector <int> vect1, vect2, rez;
int ptr2, i, j, nrelem1, nrelem2;

int main()
{
    fin >> nrelem1 >> nrelem2;
    vect1.assign(nrelem1, 0);
    vect2.assign(nrelem2, 0);
    for (i = 0; i < nrelem1; i++)
    {
        fin >> vect1[i];
    }

    for (i = 0; i < nrelem2; i++)
    {
        fin >> vect2[i];
    }
    for (i = 0; i < nrelem1; i++)
        for(j = 0; j < nrelem2; j++)
        {
            if (vect1[i] == vect2[j] && j >= ptr2)
            {
                rez.push_back(vect1[i]);
                ptr2 = j + 1;
                break;
            }
        }
    fout << rez.size() << '\n';
    for (auto i : rez)
        fout << i << ' ';
    return 0;
}
