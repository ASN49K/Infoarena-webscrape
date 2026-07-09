#include <fstream>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int gcd(int a, int b){
    if(!b) return a;
    else return gcd(b, a % b);

}
int main(){
        int a, b;
        int n;
        f >> n;
        f >> a >> b;
        for(int i = 1; i <= n; ++i){
            f >> a >> b;
            g << gcd(a, b);
            g << endl;
        }
        f.close();
        g.close();
        return 0;

}
