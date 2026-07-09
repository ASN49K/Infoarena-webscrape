uses crt;
var i,n:longint;
    f,g:text;
    h,j:longint;
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
assign(g,'euclid2.out');
rewrite(g);
read(f,n);
for i:=1 to n do
   begin
   read(f,h);
   read(f,j);
   writeln(g,cmmdc(h,j));
   end;
close(f);
close(g);
end.
