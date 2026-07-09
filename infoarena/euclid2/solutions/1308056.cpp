#include <iostream>
#include <fstream>
using namespace std;

    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int a,b,T;

       inline int euclid(int a, int b)
        {
            if(b!=0)
                return euclid(b,a%b);
            else
             return a;
        }

        int main()
        {
            fin>>T;
            while(T--)
            {
                fin>>a>>b;
                fout<<euclid(a,b)<<"\n";
            }
            fin.close();
            fout.close();
            return 0;
        }
