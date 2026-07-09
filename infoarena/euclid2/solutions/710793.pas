var n,i,t:integer;
a,b:int64;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do begin
readln(f,a,b);
while b<>0 do begin
t:=b;
b:=a mod b;
a:=t;end;
writeln(g,t);end;
close(g);close(f);end.