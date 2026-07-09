var r,a,b:int64;
f,g:text;
t:longint;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do
begin
readln(f,a,b);
repeat
r:=a mod b;
a:=b;
b:=r;
until b=0;
write(g,a);
end;
close(f);
close(g);
end.