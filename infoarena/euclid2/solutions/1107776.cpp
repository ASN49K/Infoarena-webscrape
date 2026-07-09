#include <fstream>
using namespace std;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T;
    in >> T;
    int a, b, r;
    for(int i=0; i<T; i++){
        in >> a >> b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        out << a << endl;
    }
}
