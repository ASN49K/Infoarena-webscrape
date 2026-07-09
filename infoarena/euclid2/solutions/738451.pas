var i,j,k,l,m,n:longint; f1,f2:text;
function Euclid(nr1,nr2:longint):longint;
var t,o:longint;
begin
o:=0;
while nr2<>0 do begin
t:=nr2;
nr2:=nr1 mod nr2;
nr1:=t;
end;
Euclid:=nr1;
end;
begin
assign(f1,'euclid2.in');
reset(f1);
assign(f2,'euclid2.out');
rewrite(f2);
readln(f1,n);
for i:=1 to n do begin
readln(f1,k,l);
writeln(f2,Euclid(k,l));
end;
close(F1);
close(f2);
end.
