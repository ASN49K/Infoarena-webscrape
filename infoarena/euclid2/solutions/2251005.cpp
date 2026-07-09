#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b){
    while (b!=0){
        int rest = a%b;
        a = b;
        b = rest;
    }
    return a;
}




int main()
{

    int data[100];
    int flx;
    int i = 0;
   ifstream infile;
   ofstream infile2;


   infile.open("euclid2.in");
   while(infile>>flx)
   {
     if(flx ==(int)flx){
        data[i] = flx;
     }
     i++;
   }
   infile.close();

   infile2.open("euclid2.out");
for(int i = 0 ; i<data[0];i++){
    int x= gcd(data[i+1],data[i+2]);
    cout << x<<endl;
    infile2 <<x<<endl;

}


   return 0;
}
