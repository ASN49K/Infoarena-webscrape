var f,g:text;
    w,n,k,i:longint;
function cmmdc(a,b:longint):longint;
begin
if b = 0 then
cmmdc:=a else

cmmdc:=cmmdc(b,a mod b);


end;
BEGIN



assign(f,'euclid2.in');
assign(g,'euclid2.out');
rewrite(g);
reset(f);
read(f,n);
for i:=1 to n do
begin
readln(f,w,k);
writeln(g,cmmdc(k,w));
end;
close(f);close(g);
END.