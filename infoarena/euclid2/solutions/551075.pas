var  a,b,c,n,i : longint;
     t,t2 : text;

procedure cmmdc(a,b : integer);
begin
if (b=0) then begin c:=a; exit; end
else cmmdc(b, a mod b);
end;

begin
assign(t,'euclid2.in');
reset(t);
assign(t2,'euclid2.out');
rewrite(t2);
readln(t,n);
for i:=1 to n do
begin
readln(t,a,b);
cmmdc(a,b);
writeln(t2,c);
end;
close(t);
close(t2);
end.