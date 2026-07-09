#include <iostream>
#include <fstream>
using namespace std;

    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int i,a,b,t;

       inline int euclid(int a, int b)
        {
            if(b!=0)
                return euclid(b,a%b);
            else
             return a;
        }

        int main()
        {
            fin>>t;
            while(t--)
            {
                fin>>a>>b;
                fout<<euclid(a,b)<<endl;
            }
            fin.close();
            fout.close();
            return 0;
        }
