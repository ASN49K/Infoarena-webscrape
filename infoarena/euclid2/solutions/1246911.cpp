#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int A,B,t,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>A>>B;
        fout<<euclid(A,B)<<"\n";
    }
    return 0;
}
