program cmmdc_infoarena;
var n,a,b:longint;
    f,g:text;

function divc(a,b:longint):longint;
var r:longint;
begin
 while b<>0 do
  begin
   r:=a mod b;
   a:=b;
   b:=r;
  end;
 divc:=a;
end;

begin
 assign(f,'euclid2.in'); reset(f);
 assign(g,'euclid2.out'); rewrite(g);
 readln(f,n);
 while n<>0 do
  begin
   readln(f,a,b);
   writeln(g,divc(a,b));
   n:=n-1;
  end;
 close(f);
 close(g);
end.