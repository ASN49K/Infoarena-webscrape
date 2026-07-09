#include<fstream>
using namespace std;
int main()
{
 int K;
 ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");
 fin>>K;
 int c;
 for(c = 0; c < K;c++)
   {
    int a,b;
    fin>>a>>b;
       fout<<cmmdc(a,b)<<endl;
   }
    return 0;
}
int cmmdc(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
