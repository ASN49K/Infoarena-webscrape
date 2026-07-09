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
int n , A , B;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,  int b)
{
    if(!b)return a;
    return cmmdc(b, a%b);
}
int main(){
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>A>>B;
        g<<cmmdc(A, B)<<"\n";
    }
    return 0;
}

