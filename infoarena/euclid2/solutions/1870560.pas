var a,b,i,n,t:longint;f1,f2:text;
begin
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
read(f1,n);
repeat
inc(i);
read(f1,a,b);
while b<>0 do begin
t:=b;
b:=a mod b;
a:=t;
end;
writeln(f2,a)
until i=n;
close(f1);close(f2);
end.