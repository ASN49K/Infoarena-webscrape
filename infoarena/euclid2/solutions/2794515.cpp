#include <iostream> 
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid (int x , int y)
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
    int n ;
    f >> n ;

    for(int i = 1 ; i <= n ; i++ )
    {
        int x , y ;
        f >> x ;
        f >> y ;
        cout << euclid(x,y) << endl ;
    }
 

}