#include <iostream>
#include <fstream>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

int main() {
    int t;
    long long a, b, r;
    in>>t;
    for(int i = 0;i < t;i++)
    {
        in>>a>>b;
        while(b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        out<<a<<'\n';
    }
    in.close();
    out.close();
    return 0;
}
