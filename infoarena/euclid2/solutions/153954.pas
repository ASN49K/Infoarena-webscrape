var a,b,r,i,n:longint;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,n);
for i:=1 to n do begin
read(f,a,b);
while b<>0 do begin
r:=a mod b;
a:=b;
b:=r;
end;
write(g,a);
end;
close(f);
close(g);
end.