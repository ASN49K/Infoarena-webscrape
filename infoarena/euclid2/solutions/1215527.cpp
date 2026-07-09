#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen ("euclid2.in" , "r" , stdin);
    freopen ("euclid2.out" , "w" , stdout);
    int t;
    scanf ("%d" , &t );
    while (t!=0){
            int a,b,r;
            scanf ("%d %d" , &a ,&b);
            while(b!=0){
                r=a%b;
                a=b;
                b=r;
            }
          printf ("%d" , a);
          printf ("\n");
          --t;
    }


    return 0;
}
