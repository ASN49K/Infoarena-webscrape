#include <iostream>
#include <fstream>


using namespace std;
ifstream fin("euclid2.in");
ofstream gout("euclid2.out");


int euclid(int a,int b)
{
    if ( b ==0 ) return a;
    else return euclid(b,a%b);
}
int main()
{
    int T,a,b;
    fin>>T;
    for(int i=0;i<T;++i)
    {
        fin>>a>>b;
        gout<<euclid(a,b)<<endl;
    }
    return 0;
}
