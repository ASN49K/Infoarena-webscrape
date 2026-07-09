#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, s, x;

int main()
{
    fin >> t;
    while(t--)
    {
        fin >> n;
        s=0;
        for(int i=0;i<n;i++)
            {
                fin >> x;
                s^=x;
            }
        if(s==0) fout << "NU\n";
         else fout << "DA\n";
    }








    return 0;
}

