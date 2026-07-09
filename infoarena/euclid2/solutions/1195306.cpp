#include <fstream>
using namespace std;
int gcd(int a, int b){
    if (!b) return a;
    else return gcd(b, a%b);
}
int main()
{
    int a,b,n,i;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> n;


    for (i=0;i<n;i++){
        in >> a >> b;
        out << gcd(a,b) << "\n";
    }
    return 0;
}
