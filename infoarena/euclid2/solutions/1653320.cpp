#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
  int a,b,t,r;
    fin>>t;
    while(t>0)
        { fin>>a>>b;

                    while(b>0)
                        { r=a%b;
                           a=b;
                          b=r;

                        }
            fout<<a<<"\n";
            t--;

        }


fin.close();
fout.close();
    return 0;
}
