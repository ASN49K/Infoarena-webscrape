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
          r=a%b;
                    while(r>0)
                        { a=b;
                          b=r;
                           r=a%b;
                        }
            fout<<b<<endl;
            t--;

        }


fin.close();
fout.close();
    return 0;
}
