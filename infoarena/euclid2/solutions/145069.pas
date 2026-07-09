program cmmdc;  
var a,b,r:integer;  
  
 procedure citire;  
 begin  
 assign(input,'cmmdc.in');  
 reset(input);  
 read(a,b);  
 close(input);  
 end;  
   
 procedure cmmdc;  
 var w,q:integer;  
 begin  
 w:=a;  
 q:=b;  
 repeat  
        r:=w mod q;  
        w:=q;  
        q:=r;  
        until q=0;  
 if (w=1) and (a<>1) and (b<>1) then  
    write(0)  
    else write(w);  
 end;  
   
  28. begin  
  29. citire;  
  30. assign(output,'cmmdc.out');  
  31. rewrite(output);  
  32. cmmdc;  
  33. close(output);  
  34. end.  