/*
 * euclid.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: andreir
 */
/*
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int x,int y){
    if(!y) return x;
    else return cmmdc(y,x%y);
}


int main() {
    int N,x,y;
    cin>>N;
    for(;N>0;N--){
        cin>>x>>y;
        cout<<cmmdc(x,y);
    }
    return 0;
}
*/
#include <stdio.h>

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }

    return 0;
}
