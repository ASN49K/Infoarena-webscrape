#include <stdio.h>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <limits.h>
#include <algorithm>
#include <deque>
using namespace std;
int t,n,m,i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
inline int cmmdc(int a,int b)
{
    if (b==0) return (a); else
        return cmmdc(b,a%b);
}
int main(){
fin>>t;
for (i=1;i<=t;i++){
    fin>>n>>m;
    fout<<cmmdc(n,m)<<'\n';
}
return 0;
}
