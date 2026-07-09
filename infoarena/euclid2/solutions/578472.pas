program euclid2;
const fi='euclid2.in';
      fo='euclid2.out';
var f,g:text;
a,b,i,n:longint;
function cmm(a,b:longint):longint;
begin
if b=0 then
   cmm:=a
   else
   cmm:=cmm(b,a mod b);
end;
begin
assign(f,fi);
reset(f);
assign(g,fo);
rewrite(g);
read(f,n);
for i:=1 to n do
  begin
  read(f,a,b);
  writeln(g,cmm(a,b));
  end;
  close(f);
  close(g);
  end.
