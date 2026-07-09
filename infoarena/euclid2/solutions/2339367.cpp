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
    int N,A,B;
    ifstream fin("euclid2.in");
    ofstream fout("euclid.out");

    fin>>N;

    for(;N;--N)
    {
        fin>>A>>B;
        fout<<gcd(A,B)<<endl;
    }
    return 0;
}
