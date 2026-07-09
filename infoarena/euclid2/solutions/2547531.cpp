#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include <fstream>

using namespace std;

#define x first
#define y second

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, a, b;

int gcd(int a, int b)
{
    int aux;
    while(a%b!=0)
    {
        aux=a%b;
        a=b;
        b=aux;
    }
    return b;
}

int main (){

    f >> t;
    for(int i = 1; i <= t; i++) {
        f >> a >> b;
        g << gcd(a, b) << '\n';
    }
    
    return 0;
}
