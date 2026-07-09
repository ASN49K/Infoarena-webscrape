#include <fstream>

using namespace std;

int euclid(int a, int b){
    while( a!= b)
        a > b ? a-=b : b-=a;
    return a;
}
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
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
