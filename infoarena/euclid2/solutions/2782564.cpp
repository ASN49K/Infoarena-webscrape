#include<fstream>
#include<algorithm>
using namespace std;
ifstream gin("euclid2.in");
ofstream gout("euclid2.out");
int euclid(int a,int b)
{
    while(b){
        int c = a % b;
        a = b;
        b = c;
    }
    return a;

}
int main()
{
    long long a, b;
    int n;
    gin>>n;
    for (int i = 0; i < n; i++){

    gin >> a >> b;

    gout <<euclid(a, b) <<"\n";
    }

}
