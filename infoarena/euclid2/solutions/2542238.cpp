#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,p,t;
int main()
{   f>>t;
   for(int i=1;i<=t;i++){f>>a>>b;
                         while(a%b!=0){p=a%b;
                                      a=b;
                                      b=p;


                                      }
                         g<<b<<'\n';

                        }

    return 0;
}
