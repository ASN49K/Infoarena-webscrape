#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,x,i=0,r;
    fin>>x;
    while (fin>>a>>b)
    {
    if (i!=x)
      {
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<" ";
        i++;
      }
    }
    return 0;
}

