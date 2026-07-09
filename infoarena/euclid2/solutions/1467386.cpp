#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int T,a,b,i,r;
    fin>>T;
    for(i=0;i<T;i++)
    {
        fin>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<endl;
    }
    fin.close();
    out.close();
    return 0;
}
