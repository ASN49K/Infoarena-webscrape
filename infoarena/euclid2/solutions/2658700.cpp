#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
#include <map>
#include <math.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,  int b)
{
    if(!b)return a;
    return cmmdc(b, a%b);
}
int main(){
    int n;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        int a , b;
        f>>a>>b;
        g<<cmmdc(a, b)<<endl;
    }
    return 0;
}

