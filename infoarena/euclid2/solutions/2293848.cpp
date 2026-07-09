#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a,int b)
{
    if(!b)
      return a;
    else
        return euclid(b,a%b);
}
int main()
{
    int A,B,T;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>A;
        fin>>B;
        fout<<euclid(A,B)<<endl;
    }

    return 0;
}
