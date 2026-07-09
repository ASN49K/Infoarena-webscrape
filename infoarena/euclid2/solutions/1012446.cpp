#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int t, a, b, aux;
    in >> t;
    while(t > 0){
        in >> a >> b;
        while(b){
            aux = b;
            b = a%b;
            a = aux;
        }
        out << a << "\n";
        t--;
    }
    return 0;
}
