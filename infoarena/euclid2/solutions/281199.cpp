    #include<fstream>  
    using namespace std;  
    int main()  
    {  
        int a,b,n,r;  
        ifstream in("euclid2.in");  
        ofstream out("euclid2.out");  
        in>>n;  
        while(n--)  
       {  
           in>>a>>b;  
           r=a%b;  
           while (r)  
       {  
           a=b;  
           b=r;  
           r=a%b;  
       }  
       out<<b<<"\n";  
       }  
       in.close();  
       out.close();  
       return 0;  
   }  