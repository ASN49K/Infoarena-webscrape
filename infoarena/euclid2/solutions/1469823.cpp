#include <fstream>
using namespace std;

int euclid(int a,int b)
{
    if(!b) return a;
    else euclid(b,a%b);
}

int main(void) {
    int a, b;
    int T;
    ifstream input("euclid2.in");
    ofstream output("euclid2.out");
    input >> T;

    for(int i = 1; i <= T; i++) {
        int d;
        input >> a >> b;
        euclid(b,a);
        output << d;
    }
}    
