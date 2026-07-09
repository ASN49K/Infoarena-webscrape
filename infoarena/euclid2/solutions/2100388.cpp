#include <fstream>


using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{ int i,n,a,b;
f>>n;
for(i=1;i<=n;i++){
    f>>a>>b;
    g<<euclid(a,b)<<endl;

}

    return 0;
}
