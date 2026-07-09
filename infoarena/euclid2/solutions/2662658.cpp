#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int T,a,b,d;
int main()
{fin>>T;
while (T!=0)
    {fin>>a>>b;
     if (a>b)
        d=b;
     else
        d=a;
     while (a%d!=0 or b%d!=0)
         {d=d-1;
         }
     fout<<d<<endl;
     T=T-1;
    }
    return 0;
}
