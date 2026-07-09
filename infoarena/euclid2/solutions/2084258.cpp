#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, n;
void euclid(int a, int b)
{
 int c;
 while(b)
 {
     c=a%b;
     a=b; b=c;
 }
g<<a<<"\n";

}
int main()
{
    f>>n;
    while(n)
    {
        f>>a>>b;
        euclid(a,b);
        n--;
    }
    return 0;
}
