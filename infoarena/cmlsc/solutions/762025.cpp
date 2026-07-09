#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

std::string cmlsc( std::ofstream &out, std::vector<int> a, std::vector<int> b )
{
    //initializare
    std::vector< std::string > present, past;
    present.resize( b.size() + 1 );
    int space = 0;

    //programare dinamica
    for( int i = 0; i < a.size(); i++ )
    {
        past = present;

        for( int j = 1; j < b.size() + 1; j++ )
        {
            if( a[i] == b[j - 1] )
            {
                char tmp[100];
                present[j] = past[j-1];
                itoa( a[i], tmp, 10 );
                present[j] += tmp;
                present[j] += ' ';
                space++;
            }
            else
            {
                present[j] = ( present[j-1].size() > past[j].size() ) ? present[j-1] : past[j];
            }
        }
    }

    out << space << '\n' << present[b.size()];
}

void read( std::ifstream &f, std::vector<int> &v, int n )
{
    v.resize( n );
    for( int i = 0; i < n; i++ )
    {
        f >> v[i];
    }
}

int main()
{
    std::ifstream in ( "cmlsc.in" );
    std::ofstream out ( "cmlsc.out" );
    std::vector<int> a, b;
    int na, nb;
    in >> na >> nb;
    read( in, a, na );
    read( in, b, nb );
    cmlsc( out, a, b );
    in.close();
    out.close();
    return 0;
}
