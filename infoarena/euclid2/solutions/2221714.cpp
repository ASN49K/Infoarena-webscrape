#include <iostream>
#include <bits/stdc++.h>
#include <fstream>


using namespace std;
int T,A,B;
int gg(int a, int b){
    if (b==0) return a;
    return gg(b, a%b);
}

int main()
{
ifstream f("euclid2.txt");
ofstream g("euclid2.out");
cin>> T;
while (T>0){
T--;
f>>A>>B;
g<<gg(A,B)<<'\n';
}


}
