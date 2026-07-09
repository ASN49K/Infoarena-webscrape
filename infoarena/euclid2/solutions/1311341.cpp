#include <fstream>

using namespace std;

int n,a,b;

int euclid(int a,int b);

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;

    for(int i=1;i<=n;i++){
        f>>a>>b;
        g<<euclid(a,b)<<"\n";

    }

    return 0;
}

int euclid(int a,int b){
    int r;
    if(a!=0 && b!=0){
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
    }

    return a;
}
