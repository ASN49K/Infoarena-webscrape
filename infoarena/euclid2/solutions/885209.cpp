#include<iostream>
#include<fstream>
using namespace std;
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
int main ()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    int nr_p,a ,b;
    
    fin >> nr_p;
    for(int i=1;i<=nr_p;i++)
    {
      fin >> a>>b;
      fout << euclid(a, b) << "\n";
    }
    
}
