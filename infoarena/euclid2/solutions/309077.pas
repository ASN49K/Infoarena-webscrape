program cmmdc;
var a,b,c:array[1..100000] of longint;
    fin,fout:text;
    t,i:longint;
function euclid(var a,b:longint):longint;
var k:longint;
begin
while (a mod b) <>0 do
begin
k:=a mod b;
a:=b;
b:=k;
end;
euclid:=b;
end;
begin
assign(fin,'euclid2.in'); reset(fin);
assign(fout,'euclid2.out'); rewrite(fout);
readln(fin,t);
for i:=1 to t do
readln(fin,a[i],b[i]);
close(fin);
for i:=1 to t do
c[i]:=euclid(a[i],b[i]);
for i:=1 to t do
writeln(fout,c[i]);
close(fout);
end.
