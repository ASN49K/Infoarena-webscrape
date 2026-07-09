#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
void euclid(int m, int n){
    int aux;
    if(n == 0){
        return;
    } else{
        while(n){
            aux = n;
            n = m%n;
            m = aux;
        }
    }
}
int main()
{
    int t, a, b;
    in >> t;
    while(t > 0){
        in >> a >> b;
        euclid(a, b);
        out << a << "\n";
        t--;
    }
    return 0;
}
