#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b){
    if(b==0) return a;
    return euclid(b,a%b);
}
int main()
{ int n,a,b;
f>>n;
for(;n;n--){
    f>>a>>b;
    g<<euclid(a,b)<<endl;

}

    return 0;
}
