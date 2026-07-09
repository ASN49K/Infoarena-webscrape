#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin>>T;
    int a , b ,r;
    int cmmdc;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        if(a*b==0)
        {
            cmmdc=a+b;
        }else
        {
        while(a!=b)
        {
            if(a>b)
            {
                a=a-b;
            }
            if(b>a)
            {
                b=b-a;
            }
        }
        cmmdc=b;

        }
 fout<<cmmdc<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
