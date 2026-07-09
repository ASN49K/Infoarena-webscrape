var f,g:text;   
   a,b,c,d:longint;   
begin  
assign(f,'euclid2.in'); reset(f);   
assign(g,'euclid2.out'); rewrite(g);   
readln(f,a);   
readln(f,b);   
while a<>b do begin  
     if a > b then a:=a-b else  
                   b:=b-a;   
              end;   
if (a=1) and (b=1) then writeln(g,'0') else  
   writeln(g,a);   
   close(f);   
   close(g);   
   end.  
