#include<fstream>

using namespace std;

int cmmdc(int a, int b){

   if(b==0) return a;
   else return cmmdc(b, a%b);


}


int main()
{
        ifstream fin("euclid2.in");
        ofstream fout("euclid2.out");
    int a, b, i, n ;
    fin>>n;


    for(i=1; i<=n; ++i)
{
    fin>>a;
    fin>>b;
    fout<<cmmdc(a,b);
    fout<<endl; }

    fin.close();
    fout.close();



    return 0;
}
