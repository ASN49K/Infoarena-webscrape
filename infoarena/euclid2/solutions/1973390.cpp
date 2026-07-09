#include <iostream>
#include <fstream>

#define MAX 100000

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int K,a,b;


int cmmdc(int a, int b)
{
    if (!b) return a;
    return cmmdc(b, a % b);
}

int main()
{
    in>>K;
    for(int i = 1; i <= K; i++){
        in>>a>>b;
        out<<cmmdc(a,b)<<endl;

    }





    return 0;
}

