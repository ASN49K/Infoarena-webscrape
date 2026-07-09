program cmmdc_infoarena;
var n,a,b,r:longint;
    f,g:text;

begin
 assign(f,'euclid2.in'); reset(f);
 assign(g,'euclid2.out'); rewrite(g);
 readln(f,n);
 while n<>0 do
  begin
   readln(f,a,b);
   while b<>0 do
  begin
   r:=a mod b;
   a:=b;
   b:=r;
  end;
   writeln(g,a);
   n:=n-1;
  end;
 close(f);
 close(g);
end.