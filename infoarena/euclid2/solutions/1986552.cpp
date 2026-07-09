#include <fstream>

using namespace std;

int euclid(int a, int b){
    if( b == 0 ) return a;
    else return euclid( b, a%b );
}
int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int a,b,rep;
    f >> rep;
    for( ;rep ; --rep ){
        f >> a >> b;
        g << euclid(a,b) << endl;
    }
    f.close();
    g.close();
    return 0;
}
