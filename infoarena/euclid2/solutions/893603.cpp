#include <iostream>
#include <fstream>
using namespace std;
    ifstream fin("euclid2.in");
    ofstream gout("euclid2.out");
int nr, a, b,i;
int heuclid (int a, int b) {
    if(b==0) return a;
    return heuclid(b, a%b);
}
void ciunga();
 int main() {
    fin>>nr;
    ciunga ();
return 0;
 }

    void ciunga ()
    {
        while (fin>>a>>b)
   gout<<heuclid(a,b)<<endl;
    }
