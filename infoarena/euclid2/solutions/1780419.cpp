#include <iostream>
#include <fstream>
using namespace std;

int T, A, B;

int wut(int a, int b)
{
    if (!b) return a;
    return wut(b, a % b);
}

int main(void)
{
ifstream in("euclid2.in");
ofstream out("euclid2.out");
   in>>T;


    for (int i=1;i<=T;i++)
    {
      in>>A>>B;
    out<<wut(A, B)<<".\n";
    }

    return 0;
}
