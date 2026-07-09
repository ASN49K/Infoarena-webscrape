#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int T,a,b,r;
    fin>>T;
    while(fin>>a>>b&&T!=0)
    {
        while(a!=0&&b!=0)
        {
            if(a>b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            else
             {
                r=b%a;
                b=a;
                a=r;
            }
        }
        fout<<a+b<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
