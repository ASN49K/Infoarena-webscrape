var a,b,t,i,r:longint;
f1,f2:text;
begin
assign(f1,'euclid2.in');
reset(f1);
assign(f2,'euclid2.out');
rewrite(f2);
read(f1,t);
for i:=1 to t do begin
readln(f1,a,b);
while b<>0 do begin
r:=a mod b;
a:=b;
b:=r;
end;
write(f2,a);
end;
close(f1);
close(f2);
end.