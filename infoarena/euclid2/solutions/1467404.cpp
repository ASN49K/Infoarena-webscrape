#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fi("euclid2.in");
    ofstream fo("euclid2.out");

    int a,b,t,i;
    fi >> t;

    for (i=t;i>0;i--){
     fi>>a>>b;

    while (a!=0) {
     if(a<b) swap(a,b);
   a=a%b;
    }
  fo << b << endl;
}

}
