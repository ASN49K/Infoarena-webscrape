#include <bits/stdc++.h>
using namespace std;
#define e "\n"
ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    if(a == b) return a;
    else return(b, b%a);
}

int main()
{
    int t, a, b;
    in  >> t;

    while(t--)
    {
        in >> a >> b;
        out << euclid(a, b) << e;
    }


    return 0;
}
