#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n, i, a, b;
int cmmdc(int a, int b){
    int r = a%b;
    while(r>0){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int main()
{
    in >> n;
    for(i=1;i<=n;i++){
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }
    return 0;
}
