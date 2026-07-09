#include <iostream> 
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid (long long int x , long long  int y)
{
    while(x!=0)
    {
        long long int r = y % x ;
        y = x ;
        x = r ;

    }
    return y;
}
int main()
{
    long long int n ;
    f >> n ;

    for(int i = 1 ; i <= n ; i++ )
    {
        long long int x , y ;
        f >> x ;
        f >> y ;
        g << euclid(x,y) << endl ;
    }
 

}