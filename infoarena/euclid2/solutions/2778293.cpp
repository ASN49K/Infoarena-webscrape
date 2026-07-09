#include <fstream>
#include <iostream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid (int a, int b){
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    long long a, b;
    int n;
    f >> n;
    for (int i = 0; i < n;++i){
        f >> a >> b;
        g << euclid (a, b)<< "\n";
    }

}
