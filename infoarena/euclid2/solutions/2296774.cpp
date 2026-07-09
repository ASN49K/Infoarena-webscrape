#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r=0,t;
int main()
{
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        if(a>b)
        swap(a,b);
        while(a)
        {
            r=b%a;
            b=a;
            a=r;
        }
        fout<<b<<endl;
        t--;
    }
  return 0;
}
