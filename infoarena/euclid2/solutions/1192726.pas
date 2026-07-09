var n,i,r:longint;
    a,b:array[1..100000]of qword;
    f:text;
begin
assign(f,'euclid2.in');reset(f);
read(f,n);
close(f);
for i:=1 to n do
readln(a[i],b[i]);
assign(f,'euclid2.out');rewrite(f);i:=0;

repeat
i:=i+1;
while b[i]<>0 do
begin
r:=a[i] mod b[i];
a[i]:=b[i];
b[i]:=r;
end;
writeln(f,a[i]);
until i=n;
close(f);
end.