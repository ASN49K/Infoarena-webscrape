#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f;
    f.open("euclid2.in.txt");
    ofstream g;
    g.open("euclid2.out.txt");

    int T,a,b,i;
    f>>T;
    for (i=1; i<=T; i++) {  f>>a>>b;
                            while (a!=b){if (a>b) a=a-b;
                                         if (b>a) b=b-a;}
                            g << a << endl;}
    f.close();
    g.close();
    return 0;
}
