#include <iostream> 
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid (long long int x , long long  int y)
{
    while(x!=y)
    {
        if(x < y)
            y = y - x ;
        else 
            x = x - y ;
    }
    return x;
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