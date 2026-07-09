#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main()
{
    int t , x , y ;
    fin >> t ;
    for ( int i = 0 ; i < t ; i++ )
        {
            fin >> x >> y ;
            while ( y != 0 )
                {
                    int rest = x % y ;
                    x = y ;
                    y = rest ;
                }
            fout << x << '\n' ;
        }
    return 0;
}
