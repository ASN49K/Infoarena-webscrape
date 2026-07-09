#include <iostream>
#include <fstream>
using namespace std;
int gcd(int a, int b)
{
    if(!b)return a;
    return gcd(b, a%b);
}
int main()
{
    int N;
    long A,B;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>N;

    for(;N;--N)
    {
        fin>>A>>B;
        fout<<gcd(A,B)<<endl;
    }
    return 0;
}
