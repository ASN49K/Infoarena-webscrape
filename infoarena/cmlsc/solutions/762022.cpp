#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string cmlsc( std::vector<int> a, std::vector<int> b )
{
    //initializare
    std::vector< std::string > present, past;
    present.resize( b.size() + 1 );

    //programare dinamica
    for( int i = 0; i < a.size(); i++ )
    {
        past = present;

        for( int j = 1; j < b.size() + 1; j++ )
        {
            if( a[i] == b[j - 1] )
            {
                present[j] = past[j-1];
                present[j] += a[i]+'0';
                present[j] += ' ';
            }
            else
            {
                present[j] = ( present[j-1].size() > past[j].size() ) ? present[j-1] : past[j];
            }
        }
    }

    return present[b.size()];
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
    std::string r = cmlsc( a, b );
    out << ( r.size() / 2 ) << '\n' << r;
    in.close();
    out.close();
    return 0;
}
