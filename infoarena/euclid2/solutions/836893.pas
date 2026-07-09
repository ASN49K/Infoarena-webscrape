program cmmdc;
var f,g:text;
    a,b,r:longint;
begin
  assign(f,'cmmdc.in');reset(f);
  assign(g,'cmmdc.out');rewrite(g);
  readln(f,a,b);
  r:=0;
  repeat
    r:=a mod b;
    a:=b;
    b:=r;
  until r=0;
  writeln(g,a);
  close(f); close(g);
end.