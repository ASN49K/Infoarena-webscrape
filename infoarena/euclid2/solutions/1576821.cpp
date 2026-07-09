#include <fstream>
using namespace std;
int main()
{
    int a,b,r,n;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    while(n)
      {
    fin>>a>>b;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }fout<<a<<'\n';
      n=n-1;}
    fin.close();
    fout.close();

    return 0;
}
