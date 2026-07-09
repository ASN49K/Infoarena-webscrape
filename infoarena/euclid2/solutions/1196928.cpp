#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t;
    in >> t;
    for (int i= 0; i<t; i++){
        int a, b, aux;
        in >> a >> b;
        while (b !=0){
            aux = b;
            b = a % b;
            a = aux;
        }
        out << a << endl;
    }
    return 0;
}
