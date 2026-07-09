
#include <fstream>
using namespace std;
int main()
{
    ofstream fo;
    fo.open("euclid2.out");

    ifstream fi("euclid2.in");
    int T;
    fi>>T;
    int a,b,aux;
    for(int i=T;i>0;i--)
       {
          fi>>a>>b;
          while(b!=0)
            {
               aux=a;
               a=b;
               b=aux%b;
            }
          fo<<a<<endl;
       }
      fo.close();


    return 0;
}


