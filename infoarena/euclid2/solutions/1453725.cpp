#include <iostream>
#include <limits.h>
#include <cmath>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include <list>
#include <queue>
#include <iomanip>
#include <deque>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

#define cin f
#define cout g

int gcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        int a,b;
        cin >> a >> b;
        cout<<gcd(a,b)<<'\n';
    }

  return 0;
}
