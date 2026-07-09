#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int t, a, b, i, m, d;

int main ()
{

    fin >> t;

    for ( i=1; i <= t; i++)
    {
        fin >> a >> b;

        if ( a < b)
            m = a;
            
            else
                m = b;

        for ( d = m; d >= 1; d --)
            {
                if ( a % d == 0 && b % d == 0 )
                    break;
            }        

            fout << d << "\n";
    }

    fclose;
    return 0;
    
}