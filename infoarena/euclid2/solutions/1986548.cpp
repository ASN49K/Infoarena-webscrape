#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int euclid(int a, int b){
    if( b == 0 ) return a;
    else return euclid( b, a%b );
}
int main()
{
    int rep; f >> rep;
    for( int i = 1 ; i <= rep ; i ++ ){
        int a,b; f >> a >> b;
        g << euclid(a,b) << endl;
    }
    f.close();
    g.close();
    return 0;
}
