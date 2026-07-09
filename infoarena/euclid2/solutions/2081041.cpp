#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(long long a ,long long  b)
{
    if(b)
        return a;
    else
        return cmmdc(b , a%b);
}
int main()
{   long int  t;

    f>>t;
    long long  w[t] , e[t] ;
    for(long int i=0 ; i<t ; i++)
    {
        f>>w[i]>>e[i];

    }
    for(long int j=0 ; j<t ; j++)
    {   if(w[j]>=e[j])
        g<<cmmdc(w[j] , e[j] )<<endl;
        else
            g<<cmmdc( e[j] , w[j])<<endl;

    }


}
