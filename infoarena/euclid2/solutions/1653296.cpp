#include<iostream>
#include<fstream>
using namespace std;
int main()
{   ifstream f("bac.txt");
    ofstream g("bac1.txt");
    int a,b,t,r;
    f>>t;
    while(t>0)
        { f>>a>>b;
          r=a%b;
                    while(r>0)
                        { a=b;
                          b=r;
                           r=a%b;
                        }
            g<<b<<endl;
            t--;

        }

    return 0;
}
