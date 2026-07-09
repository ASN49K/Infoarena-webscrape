#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

#define ing long long


int cmmdc(int a, int b)
{
    int c;

    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

 main()
{
   int n;
   in >> n;

   while(n--)
   {
       int x, y;
       in >> x >> y;
       out << cmmdc(x, y)<<'\n';
   }
    return 0;
}
