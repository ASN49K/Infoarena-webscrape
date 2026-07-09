 #include<iostream.h>
 #include<fstream.h>
  fstream f("euclid2.in",ios:: in);
  fstream g("euclid2.out", ios :: out);

 int main()

 {
  long long T,i,a,b,r;

  f>>T;
  for(i=1;i<=T;i++)
  {
   f>>a;f>>b;
   do
   {
    r=a%b;
    a=b;
    b=r;
   }while(r!=0);
   g<<a<<"\n";
  }
  g.close();
  f.close();
  return 0;
 }