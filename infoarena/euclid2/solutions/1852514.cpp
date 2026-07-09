#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int nr1,nr2,n,i;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>nr1>>nr2;
       while(nr1 != nr2)
      {
       if(nr1>nr2)
        {
          nr1 = nr1-nr2;
        }
       else
        {
          nr2=nr2-nr1;
        }
      }
      g<<nr1<<endl;
    }
    return 0;
}
