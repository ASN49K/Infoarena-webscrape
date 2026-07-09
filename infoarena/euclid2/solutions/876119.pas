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
begin
r:=a mod b;
while r<>0 do begin
              a:=b;
              b:=r;              
              r:=a mod b;                 
              end;  
writeln(g,b);
end;
end;
close(f);close(g);
end.