#include <fstream>
#include <list>
#define f 0
#define s 1
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, i, j, maxi, drumLin, drumCol, drumVal;
int vals[2][1050], dynProg[1050][1050];
list<int> solution;

int main()
{
    fin>>n>>m;
    maxi = max(n, m);
    for (i = 1 ; i <= maxi ; i++) {
        if (i <= n)
            fin>>vals[f][i];
        else
            vals[f][i] = -1;
    }

    for (i = 1 ; i <= maxi ; i++) {
        if (i <= m)
            fin>>vals[s][i];
        else
            vals[s][i] = -2;
    }

    for (i = 1 ; i <= maxi ; i++) {
        for (j = 1 ; j <= maxi ; j++) {
            if (vals[f][i] == vals[s][j])
                dynProg[i][j] = dynProg[i-1][j-1] + 1;
            else
                dynProg[i][j] = max(dynProg[i-1][j] , dynProg[i][j-1]);

            /// fout<<dynProg[i][j]<<' '; /// DEBUG
        }
        /// fout<<'\n'; /// DEBUG
    }

    drumLin = maxi; drumCol = maxi;
    drumVal = dynProg[maxi][maxi];

    fout<<drumVal; fout<<'\n';

    while (drumVal > 0) {
        while(dynProg[drumLin - 1][drumCol] == drumVal) drumLin--;
        while(dynProg[drumLin][drumCol - 1] == drumVal) drumCol--;

        solution.push_front(vals[f][drumLin]);
        drumVal--; drumLin--; drumCol--;
    }

    for (list<int>::iterator it = solution.begin() ; it != solution.end() ; it++)
        fout<<*it<<' ';

    return 0;
}
