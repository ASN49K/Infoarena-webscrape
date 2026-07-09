#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int nr1, nr2, v[1030], t[1030], lin[1030][1030];

void rec(int linie, int coloana)
{
    if(lin[linie][coloana] == 0)
    return;
    if(v[linie] == t[coloana])
    {
        rec(linie-1, coloana-1);
        cout << v[linie] << ' ';
    }
    else
    {
        if(linie == 1)
        {
            rec(linie, coloana-1);
            return;
        }
        if(coloana == 1)
        {
            rec(linie-1, coloana);
            return;
        }

        if(lin[linie-1][coloana] > lin[linie][coloana-1])
        rec(linie-1, coloana);
        else
        rec(linie, coloana-1);
        return;
    }
}

int main()
{
    cin >> nr1 >> nr2;
    for(int i=1; i <= nr1; i++)
    cin >> v[i];
    for(int i=1; i <= nr2; i++)
    cin >> t[i];

    for(int i=1; i <= nr1; i++)
    {
        for(int j=1; j <= nr2; j++)
        {
            if(v[i] == t[j])
            {
                lin[i][j] = lin[i-1][j-1]+1;
            }
            else
            {
                lin[i][j] = max(lin[i-1][j], lin[i][j-1]);
            }
        }
    }
    /*for(int i=1; i <= nr1; i++)
    {
        for(int j=1; j <= nr2; j++)
        {
            cout << lin[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << lin[nr1][nr2] << '\n';
    rec(nr1, nr2);
}
