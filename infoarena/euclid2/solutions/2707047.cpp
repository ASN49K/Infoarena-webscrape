#include <iostream>
#include <fstream>
using namespace std;
ifstream in("drept.in");
ofstream out("drept.out");
int gcd(int a, int b) {
    if (b==0){
        out << a;
        return 0;}
    return gcd(b, a % b);
}
int main() {

    int T;
    in >> T;
    for(int i =1;i<=T;i++)
    {
        int a,b;
        in >> a >> b;
        gcd(a,b);
        out << endl;
    }
    return 0;
}
