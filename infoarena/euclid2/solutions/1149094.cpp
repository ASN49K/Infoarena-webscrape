#include <iostream>
#include <fstream>

using namespace std;


int gcd(int a, int b){
    for(int c ; b ; c = a % b , a = b , b = c);
    return a;
}


int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b;
    f>>a>>b;
    cout<<gcd(a,b);
    f.close();
    g.close();
    return 0;
}
