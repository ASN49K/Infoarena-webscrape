#include <iostream>
#include<fstream>

using namespace std;

int cmmdc(int a, int b){

   if(b==0) return a;
   else return cmmdc(b, a%b);


}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a, b, i, n ,r;
    fin>>n;


    for(i=1; i<=n; ++i)
{
    fin>>a;
    fin>>b;
    /*while(b){

        r=a%b;

        a=b;
        b=r; }

    fout<<a;
    fout<<endl; */
    fout<<cmmdc(a,b)<<endl;
    fin.close();
    fout.close();}



    return 0;
}
