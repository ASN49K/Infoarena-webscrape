#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b){
    while(a != b){
        if(a > b)
            a-=b;
        else
            b-=a;
    }

    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");


    int t;
    f >> t;

    for(int i = 1; i <= t; i++){
        int a, b;
        f >> a >> b;

        g << cmmdc(a, b) << endl;
    }

    f.close();
    g.close();

    return 0;
}
