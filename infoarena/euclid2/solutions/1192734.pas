var n,i,r:longint;
    a,b:longint;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
readln(f,n);
assign(g,'euclid2.out');rewrite(g);
i:=0;

repeat
i:=i+1;
readln(f,a,b);
while b<>0 do
begin
r:=a mod b;
a:=b;
b:=r;
end;
writeln(g,a);
until i=n;
close(f); close(g);
end.