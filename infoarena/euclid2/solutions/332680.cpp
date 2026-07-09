#include <iostream>
#include <fstream>

using namespace std;
int N,a,b;
int cmmdc(int a, int b) {
    if (b==0) return a;
    return cmmdc(b, a%b);
}
int main(){
    ifstream input;
    input.open("euclid2.in");
    input >> N;
    ofstream output;
    output.open("euclid2.out");
    for (int i=0; i<N; i++)
    {
        input >> a >> b;
        output << cmmdc(a,b) << "\n";
    }
    return 0;
}
