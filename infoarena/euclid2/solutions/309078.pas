program cmmdc;
var a,b,c:longint;
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
begin
readln(fin,a,b);
c:=euclid(a,b);
writeln(fout,c);
end;
close(fin);
close(fout);
end.
