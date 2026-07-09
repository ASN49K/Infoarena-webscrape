program euclid;
var f,g:Text;
    t,a,b,i:longint;

function eu (a,b:longint):longint;
begin
 if b=0 then
  eu:=a
 else
  eu:=eu (b,a mod b);
end;

begin
 assign (f,'euclid2.in'); reset (f);
 assign (g,'euclid2.out'); rewrite (g);
 readln (f,t);
 for i:=1 to t do
 begin
  readln (f,a,b);
  writeln (g,eu(a,b));
 end;
 close (f); close (G);
end.