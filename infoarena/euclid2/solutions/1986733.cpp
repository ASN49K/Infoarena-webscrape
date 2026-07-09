#include <stdio.h>   
#include<iostream>   
#include<fstream>   

int t,a,b;   

int cmmdc(int a, int b)   
  {   
       if(!b) return a;   
       return cmmdc(b,a%b);   
  }  

int main(void)   
{   
     	ifstream f("euclid2.in");   
  	ofstream g("euclid2.out"); 

	fscanf(f,"%d", &t);   
  
    for (; t; --t)   
    {    
	fscanf(f,"%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));   
    }           
  
    return 0;   
} 