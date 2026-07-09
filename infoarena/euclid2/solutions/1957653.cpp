#include <bits/stdc++.h>;

using namespace std;

int main()
{
   long i,n;
    long long a,b;
 ifstream f("cmmdc.in");
 ofstream g("cmmdc.out");
 f>>n;

 for(i=0;i<n,i++){
 f>>a>>b;
while ((a !=0) & (b!=0)) {
    if (a>b) a=a % b; else b=b%a;

}
 }
if ((a>0) g <<a; else g<<b;}
    return 0;
}
