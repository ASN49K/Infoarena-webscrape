var i,n:longint;
    a,b:array[1..1000000] of longint;
    f,g:text;
function cmmdc(a,b:longint):longint;
var r,aux:longint;
begin
if b>a then begin
   aux:=b;
   b:=a;
   a:=aux;
   end;
while b<>0 do
      begin
      r:=a mod b;
      a:=b;
      b:=r;
      end;
cmmdc:=a;
end;
begin
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
read(f,n);
for i:=1 to n do read(f,a[i],b[i]);
for i:=1 to n do writeln(g,cmmdc(a[i],b[i]));
close(f);
close(g);
end.