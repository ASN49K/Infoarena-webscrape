 #include<fstream.h>
 using namespace std;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 long a, b, n;


 int cmmdc(int x, int y)
 {
 if(y==0) return x;
 return cmmdc(y, x%y); 
 }  



 void citire()
 {
 f>>n;
 for(int i=1;i<=n;i++)
 {
 f>>a>>b;
 g<<cmmdc(a, b)<<endl;
 }
 }





 int main()
 {
 citire();
 return 0;
 }