#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <list>
#include <iterator>
#include <limits>
#include <numeric>
#include <functional>

using namespace std;

#define nl "\n"

typedef long long ll;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned char uchar;

const double PI = acos(-1.0);

int cmmdc(int a,int b)
{
   b==0?a:cmmdc(b,a%b);
}

int main()
{
   freopen("euclid2.in","r",stdin);
   freopen("euclid2.out","w",stdout);
   int _;
   cin>>_;
   for(int __=0;__<_;__++)
   {
      int n,m;
      cin>>n>>m;
      cout<<cmmdc(n,m)<<nl;
   }
   return 0;
}
