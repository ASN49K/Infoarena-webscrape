#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int gcd(int a, int b) {
    if (a%b==0)
        return b;
    else
        if((a%b) <= (a/b) || (a%b)%(a/b)==0)
            return (a%b);
        return (a%b)/(a/b);
    return 0;
}
int main() {

    int T;
    in >> T;
    for(int i =1;i<=T;i++)
    {
        int a,b;
        in >> a >> b;
        out << gcd(max(a,b),min(a,b)) << endl;
    }
    return 0;
}
