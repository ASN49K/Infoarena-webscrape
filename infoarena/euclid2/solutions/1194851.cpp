#include <iostream>
#include <fstream>

using namespace std;
int cmmdc (int a, int b){
    int r;
    while (b){
        r= a%b;
        a=b;
        b=r;
    }
    return a;
}


int main()
{
    ifstream in("./euclid2.in");
    int n;
    in>> n;
    int a [n][2];
    for(int i=0; i<n; i++){
        in >> a[i][0] >> a[i][1];
    }
    ofstream out("./euclid2.out");
    for(int i = 0; i< n; i++){
        out << cmmdc(a[i][0], a[i][1]) <<"\n";
    }

    return 0;
}
