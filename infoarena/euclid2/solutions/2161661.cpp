#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long long N, a, b;
int main()
{
    in >> N;
    for(int i = 1;i <= N;i++){
        in >> a >> b;
        while(b){
            int r = a % b;
            a = b;
            b = r;
        }
        out << a << '\n';
    }
    return 0;
}
