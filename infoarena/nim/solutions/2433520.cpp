#include <fstream>

using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");
int t, n, s, i, a;
int main()
{
    fin >> t;
    while(t--)
    {
        fin >> n;
        s=0;
        for(i=1;i<=n;i++)
            {
                fin >> a;
                s^=a;
            }
        if(s)
            fout << "DA\n";
        else fout << "NU\n";
    }
    return 0;
}
