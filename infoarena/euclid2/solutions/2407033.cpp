#include <iostream>
#include <fstream>

using namespace std;



int euclid(int x,  int y)
{
    return ( !y  ? x : euclid(y, x % y));

}

void rezolvare()
{

    ofstream out("euclid2.out");
    ifstream in("euclid2.in");
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
