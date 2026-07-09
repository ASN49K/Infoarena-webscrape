   1. #include<fstream.h>  
   2.   
   3. ifstream fin("euclid2.in");  
   4. ofstream fout("euclid2.out");  
   5.   
   6. long long int a,b,T;  
   7.   
   8. long long int cmmdc()  
   9. {long long r;  
  10. while(b>0)  
  11.   {r=a%b;  
  12.   a=b;  
  13.   b=r;  
  14.   }  
  15. return a;  
  16. }  
  17.   
  18. void eval()  
  19. {long long int i;  
  20. fin>>T;  
  21. for(i=1;i<=T;i++)  
  22.   {fin>>a>>b;  
  23.   fout<<cmmdc()<<'\n';  
  24.   }  
  25. }  
  26.   
  27. int main()  
  28. {eval();  
  29. fin.close();  
  30. fout.close();  
  31. return 0;  
  32. }  

