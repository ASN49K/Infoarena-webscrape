#include <iostream>
#include <fstream>

using namespace std;


ofstream out("euclid2.in");

int euclid(int x,  int y)
{
    return ( !y  ? x : euclid(y, x % y));

}

void rezolvare()
{
    ifstream in("euclid");
    int n=0 ;
    int x,y ;

    in>>n;


    for(int i = 0 ; i < n ; i++)
            {
                in>>x>>y;
                out<<euclid(x,y)<<'\n';
            }


}
int main()
{

  rezolvare();


    return 0;
}
