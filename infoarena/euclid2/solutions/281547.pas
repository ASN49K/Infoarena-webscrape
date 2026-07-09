program euclid2;
var t,a,c,b,i:longint;
    f1,f2:text;
  
 function cmmdc(a,b:longint):longint;  
  
 begin  
       while b<>0 do begin  
           c:=a mod b;  
           a:=b;          
           b:=c;  
   
       end;  
       cmmdc:=a;  



end;

BEGIN
assign(f1,'euclid2.in');reset(f1);
assign(f2,'euclid2.out');rewrite(f2);


read(f1,t);
      for i:=1 to t do 
   begin
      readln(f1,a,b);
      writeln(f2,cmmdc(a,b));
     
  end;
      close(f1);close(f2);
      end.