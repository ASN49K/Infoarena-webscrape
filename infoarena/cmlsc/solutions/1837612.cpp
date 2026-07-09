#include <fstream>
#include <math.h>

using namespace std;
ifstream f("fractal.in");
ofstream g("fractal.out");

int k,x,y;
long long int fn (int x, int y, double k) {
    int pk = (int) pow(2 , k)/2;
    if(k==1) {
        if(x==1 && y==1) return 0;
        if(x==1 && y==2) return 1;
        if(x==2 && y==1) return 3;
        if(x==2 && y==2) return 2;
        return -1;
    }


    if(x<= pk && y<= pk)  return fn(y, x, k-1);
    if(x<= pk && y> pk) return pow(2,2*k-2)+fn(x, y-pk, k-1);
    if(x> pk && y> pk) return 2*pow(2,2*k-2)+fn(x-pk, y-pk, k-1);
    else return 3*pow(2,2*k-2)+fn(pk-y+1, 2*pk-x+1, k-1);

}

int main()
{
    f>>k>>x>>y;
    g<<fn(x,y,k);
}
