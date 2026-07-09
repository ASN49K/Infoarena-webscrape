#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int T,a,b,i;
    fin>>T;
    for(i=0;i<T;i++)
    {
        fin>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        out<<a<<endl;
    }
    fin.close();
    out.close();
    return 0;
}
