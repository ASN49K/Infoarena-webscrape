// Matteo Verzotti - C++
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <ctime>
#include <map>
#include <chrono>
#include <cmath>
#define INF 0x3f3f3f3f
#define MAX(a,b) a>b ? a:b
#define MIN(a,b) a<b ? a:b

using namespace std;

/*mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rand_seed() {
    long long a = rng();
    return a;
}*/

void euclid(int a,int b,int &d) {
    if(!b)
        d = a;
    else
        euclid(b,a%b,d);
}

int main() {
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,a,b,c,d,x,y;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&a,&b);
        euclid(a,b,d);
        printf("%d\n",d);
    }
    return 0;
}
