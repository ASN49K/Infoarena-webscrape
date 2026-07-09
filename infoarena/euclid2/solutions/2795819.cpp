#include <iostream> 
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long int euclid (long long int a , long long int b)
{
    while(b!=0)
    {
        int r = a % b ;
        a = b ;
        b = r ;

    }return a ;

}
int main()
{
    
    long long int n ;
    f >> n ;
    for(long long int i = 1 ; i <= n ; i++ )
    {
        long long int x , y ;
        f >> x >> y ;
        g << euclid(x,y) << endl ;

    }

  
}