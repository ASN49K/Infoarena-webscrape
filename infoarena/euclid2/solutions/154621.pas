var a,b,r,t,i:longint;   
    f,g:text;   
begin  
assign(f,'euclid2.in');   
assign(g,'euclid2.out');   
reset(f);   
rewrite(g);   
readln(f,t);
for i:=1 to t do begin
readln(f,a,b);
r:=a mod b;
while r<>0 do begin
              a:=b;
              b:=r;
              r:=a mod b;
              end;
if b=1 then writeln(g,'1')
       else writeln(g,b);
		 end;
close(f);
close(g);   
end.  