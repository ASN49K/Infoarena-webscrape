#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream fout("euclid2.out");
int T,A,B;
int gbf(int a, int b)
{
    if(!b) return a;
    else return gbf(b,a%b);

}
void citire()
{
    f>>T;
    for(; T; --T)
    {
        f>>A>>B;
        fout<<gbf(A,B)<<" ";
    }
}
int main()
{
    citire();




}
