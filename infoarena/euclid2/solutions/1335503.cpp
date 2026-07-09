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
        while(b)
        {
                r=a%b;
                a=b;
                b=r;
        }
        fout<<a<<endl;
    }
    //cout << "Hello world!" << endl;
    return 0;
}
