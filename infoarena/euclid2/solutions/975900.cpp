
#include <fstream>
using namespace std;
int main()
{
    ofstream fo;
    fo.open("euclid2.out");

    ifstream fi("euclid2.in");
    int T,a,b,aux;;
    fi>>T;
    for(int i=T;i>0;i--)
       {
          fi>>a>>b;
          do
            {
               aux=a;
               a=b;
               b=aux%b;
            }
          while(b>0);
          fo<<a<<endl;
       }
      fo.close();


    return 0;
}


