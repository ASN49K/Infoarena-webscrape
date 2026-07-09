#include <iostream>
#include <fstream>

using namespace std;

int euclid(int x , int y)
{
    if(y == 0)
        return x;
    else
    {
        return euclid(y , x % y);
    }
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n;
    in>>n;
    for (int i = 0; i < n; ++i)
    {
        long int x, y;
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }
    

}