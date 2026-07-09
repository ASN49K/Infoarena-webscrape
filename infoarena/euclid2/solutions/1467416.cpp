#include <iostream>
#include <fstream>

using namespace std;

int divide(int x,int y){
 if (y==0){
         return x;
} else {
         return divide(y, x%y);
}
 }

int main()
{
    ifstream fi("euclid2.in");
    ofstream fo("euclid2.out");

    int a,b,t,i;
    fi >> t;

    for (i=t;i>0;i--){
     fi>>a>>b;

  fo << divide(a,b) << endl;
}
fi.close();
fo.close();
}
