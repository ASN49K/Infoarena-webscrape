#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N , M , a , b , v[257] , w[257] , y[257] , o, i;

int main()
{
    f >> N >> M;
    for( i = 1 ; i <= N ; i ++ )
    {
        f >> a;
        v[a]++;
    }
    for( i = 1 ; i <= M ; i ++ )
    {
        f >> b;
        w[b]++;
    }
    for( i = 1 ; i <= 256 ; i ++ )
    {
        if( v[i] != 0 && w[i] != 0) {
                                      o++;
                                      y[o] = i;
                                    }
    }

    g << o << endl;

    for( i = 1 ; i <= o ; i ++ )
    {
        g << y[i] << " " ;
    }
}
