#include <iostream>
#include <fstream>
using namespace std;
int algorithm(int x , int y){
    int z;
    z=x%y;
    x=y;
    y=z;
    if(y>0) algorithm(x , y);
    else return x;

}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int x,y;
    f>>x>>y;
    if(x<y) switch(x , y);
    g<<algorithm(x , y);
    return 0;
}
