
#include <iostream>

#include <cstdio>



using namespace std;



inline int euclid(int a, int b){

    int r;

    while(b){

        r = a%b;

        a=b;

        b=r;

    }

    return a;

}



int main()

{

    freopen("euclid2.in","r",stdin);

    freopen("euclid2.out","w",stdout);



    int a, b, n;



    scanf("%d", &n);

    for(int i = 0; i < n; ++i){

        scanf("%d%d", &a,&b);

        printf("%d\n", euclid(a,b));

    }



    return 0;

}
