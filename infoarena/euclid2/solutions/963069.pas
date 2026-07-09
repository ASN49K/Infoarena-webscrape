uses crt;
type vector=array[1..1000]of longint;
var i,n:longint;
    f,g:text;
    a,b:vector;
function cmmdc(a,b:longint):longint;
var x,y,k:longint;
 begin
 x:=a mod b;k:=x;
 if x=0 then cmmdc:=b
   else
  begin
  repeat
  y:=b mod x;
  b:=x;
  x:=y;
  if x<>0 then k:=x;
  until x=0;
  cmmdc:=k;
  end;
 end;
begin
clrscr;
assign(f,'euclid2.in');
reset(f);
read(f,n);
for i:=1 to n do
   begin
   read(f,a[i]);
   read(f,b[i]);
   end;
close(f);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to n do writeln(g,cmmdc(a[i],b[i]));
close(g);
end.
