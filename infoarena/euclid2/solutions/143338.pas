var a,b,r:longint;   
    f,g:text;   
begin  
assign(f,'euclid2.in');   
assign(g,'euclid2.out');   
reset(f);   
rewrite(g);   
readln(f,a,b);
r:=a mod b;
while r<>0 do begin
              a:=b;
              b:=r;
              r:=a mod b;
              end;
if b=1 then write(g,'1')
       else write(g,b);
close(f);
close(g);   
end.  