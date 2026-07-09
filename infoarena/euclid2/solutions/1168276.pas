var n,i,r:longint;
    f,g:text;
    a,b:array[1..100000]of integer;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do
read(f,a[i],b[i]);

for i:=1 to n do
begin
while b[i]<>0 do;
begin
r:=a[i] mod b[i];
a[i]:=b[i];
b[i]:=r;
end;
writeln(g,a[i]);
end;
end.
