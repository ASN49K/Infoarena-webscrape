#include<iostream>
#include<fstream>

int euclid(int a, int b)
{
    do{

      std::swap(a, b);
      b = b%a;

    }while(b);

    return a;

}

int main(void)
{
    std::ifstream ifs;
    std::ofstream ofs;

    ifs.open("euclid2.in");
    ofs.open("euclid2.out");

    int n, a, b;

    ifs >> n;

   do{
        ifs >> a >> b;
        ofs << euclid(a, b) << std::endl;
        --n;
     }while(n);

    return 0;
}
