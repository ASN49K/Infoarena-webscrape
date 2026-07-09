#include <iostream>
#include <fstream>

using namespace std;
int cmmdc(int a, int b)
  {
       if(!b) return a;
       return cmmdc(b,a%b);
  }

int main()
{
    int n,i,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        fin>>b;
        fout<<cmmdc(a,b)<<"\n";
    }


    fin.close();
    fout.close();
    return 0;
}
