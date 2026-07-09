#include <iostream>
#include <fstream>

using namespace std;


int gcd(int a, int b){
    int temp;
    while(b){
        temp = a;
        a = b;
        b = temp % b;
    }
    return (a < 0) ? -a : a;
}
int a, b, n;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> n ;
    for(int i = 0; i < n; i++){
        in >> a >> b;
        out << gcd(a,b) << endl;
    }
}
