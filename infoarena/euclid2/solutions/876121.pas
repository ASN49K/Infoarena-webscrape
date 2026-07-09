var a,b,t:int64; 
    r,i:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
a:=a mod b;
while a<>0 do begin
              r:=b mod a;
              b:=a;
              a:=r;
              end;  
writeln(g,b);
end;
close(f);close(g);
end.