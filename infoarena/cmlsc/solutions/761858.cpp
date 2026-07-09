#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> cmlsc( std::vector<int> a, std::vector<int> b )
{
    //initializare
    std::vector< std::vector<int> > present, past;
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
                present[j].push_back( a[i] );
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
    std::vector<int> r = cmlsc( a, b );
    out << r.size() << '\n';
    for( int i = 0; i < r.size(); i++ )
    {
        out << r[i] << " ";
    }
    in.close();
    out.close();
    return 0;
}
