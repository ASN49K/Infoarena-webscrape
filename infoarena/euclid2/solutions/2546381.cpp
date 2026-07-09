
#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int T,b,a;
    in >> T;
    for (int i = 1; i <= T; i++)
    {
        in >> a >> b;
        out << euclid(a, b) << "\n";
    }
    
   return 0;
}

