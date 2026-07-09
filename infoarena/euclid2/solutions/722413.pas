uses math;
var t,a,b,i,m,j:longint;
fin,fout:text;
c:array[1..100000,1..2] of longint;
begin
assign(fin,'euclid2.in');
assign(fout,'euclid2.out');
reset(fin);
rewrite(fout);
read(fin,t);
readln(fin);
for i:=1 to t do readln(fin,c[i,1],c[i,2]);
for j:=1 to t do begin
for i:=1 to max(c[j,1],c[j,2]) do
if (c[j,1] mod i=0) and (c[j,2] mod i=0) then m:=i;
if m<>1 then
writeln(fout,m)
else writeln(fout,'1');
end;
close(fin);
close(fout);
end.
