var i,a,b,n:longint;
f:text; aa,bb:array[1..1000] of longint;
begin
assign(f,'euclid2.in');reset(f);
readln(f,n);
for i:=1 to n do begin
    read(f,aa[i]); readln(f,bb[i]); end;
close(f);
assign(f,'euclid2.out');rewrite(f);
for i:=1 to n do begin
    a:=aa[i]; b:=bb[i];
while a<>b do
      if a>b then a:=a-b
             else b:=b-a;
writeln(f,a) end; close(f); end.

