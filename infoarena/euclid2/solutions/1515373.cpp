#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int N, int M){
	while(N!=0) {
      int j = N;
      N = M%N;
      M = j;
	}
	return M;
}
int main()
{
    unsigned int n,x,y;
    f>>n;
    while(n!=0){
        f>>x>>y;
    /*if(x>y){
        int j = x;
        x = y;
        y = j;
    }*/
    n--;
        g<<gcd(x,y)<<'\n';
    }
    return 0;
}
