#include<iostream>
#include <fstream>
using namespace std;
int A=2 ,B=2;
void eRead()
{
fstream f("euclid2.in");
    f>>A>>B;
    f.close();
}
void eWrite(int answer)
{
    fstream g("euclid2.out");
    g<<answer;
    g.close();
}
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    eRead();
    eWrite(euclid(A,B));
    return 0;
}
