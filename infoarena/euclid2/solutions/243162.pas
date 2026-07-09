program euclid;
var f,g:text;
    a,b,n,i:longint;
function cmmdc(a,b:longint):longint;
 var r:longint;
 begin
  repeat
  r:=a mod b;
  a:=b;
  b:=r;
  until r=0;
  cmmdc:=a;
 end;
begin
 assign(f,'euclid2.in');
 reset(f);
 readln(f,n);
 assign(g,'euclid2.out');
 rewrite(g);
 for i:=1 to n do
  begin
   readln(f,a,b);
   writeln(g,cmmdc(a,b));
  end;
 close(f);
 close(g);

end.