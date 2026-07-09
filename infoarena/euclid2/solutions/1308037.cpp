#include <iostream>
#include <fstream>
using namespace std;

    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    int i,x,y,t;

       inline int euclid(int x, int y)
        {
            if(y==0)
                return x;
            else return euclid(y,x%y);
        }

        int main()
        {
            fin>>t;
            while(t--)
            {
                fin>>x>>y;
                fout<<euclid(x,y)<<endl;
            }
            fin.close();
            fout.close();
            return 0;
        }
