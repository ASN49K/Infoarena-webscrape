#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,n,minim,x;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=0;i<n;i++){
        f>>a>>b;
        x=1;
        minim=min(a,b);
        for(int j=2;j<=minim;j++){
            if(a%j==0 && b%j==0)
                x=j;
        }
        g<<x<<endl;
    }
    f.close();
    g.close();
    return 0;
}
