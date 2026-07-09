#include <iostream>
#include <fstream>
using namespace std;

int N,A,B;

int CMMDC(int x,int y)
{
    if(!y)
        return x;
    return CMMDC(y,x%y);
}

int main()
{
 fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>> N;
    for(int i=0;i<N;++i)
    {
       f>>A>>B;
      g<<CMMDC(A,B);
    }
    return 0;
}
