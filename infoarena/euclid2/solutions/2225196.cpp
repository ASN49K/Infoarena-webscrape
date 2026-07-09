#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    int n, a, b, i = 0, r = 0;
    int cmmdc[n];
    in >> n;
    while(i < n){
        in >> a >> b;
        while(a != b){
            if(a > b){
                a -= b;
            } else {
                b -= a;
            }
        }
        cmmdc[r] = a;
        r += 1;
        ++i;
    }
    ofstream out("euclid2.out");
    for(int j = 0;j<n;++j){
        out << cmmdc[j] << endl;
    }
}
