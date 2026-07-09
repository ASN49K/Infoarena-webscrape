var a,b,r:longint;   
    f,g:text;   
begin  
assign(f,'euclid2.in');   
assign(g,'euclid2.out');   
reset(f);   
rewrite(g);   
readln(f,a,b);
if b=0 then write(g,a)
       else begin
r:=a mod b;
while r<>0 do begin
              a:=b;
              b:=r;
              r:=a mod b;
              end;
if b=1 then write(g,'0')
       else write(g,b);
            end;
close(f);   
close(g);   
end.  