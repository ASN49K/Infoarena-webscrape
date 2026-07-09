#include<fstream>
#include<iostream>

using namespace std;

class Euclid
{
  private:
    int first;
    int second;
  public:
    int euclid ();
    void setup (const int, const int);
};

int Euclid::euclid ()
{
  int aux;
  while (second)
  {
    aux=first%second;
    first=second;
    second=aux;
  }
  return first;
}

void Euclid::setup (const int a, const int b)
{
  first=a;
  second=b;
}

int main ()
{
  ifstream in;
  ofstream out;
  in.open("euclid2.in");
  out.open("euclid2.out");
  int T;
  int a,b,res;
  Euclid e;
  in>>T;
  while (T)
  {
    in>>a>>b;
    e.setup(a,b);
    res=e.euclid();
    out<<res<<endl;
    --T;
  }
  in.close();
  out.close();
  return 0;
}