#include <iostream>
#include <fstream>

using namespace std;

int euclid(const int a, const int b){
    return (b==0) ? a : euclid(b, a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t;
    f >> t;
    for(int a, b; t > 0; --t){
        f >> a >> b;
        g << euclid(a, b) << '\n';
    }
    return 0;
}
