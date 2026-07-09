program cmmdc;
var f,g:text;
    a,b,r,i,n:longint;
begin
  assign(f,'cmmdc.in');reset(f);
  assign(g,'cmmdc.out');rewrite(g);
  readln(f,n);
  for i:=1 to n do begin
  readln(f,a,b);
  repeat
    r:=a mod b;
    a:=b;
    b:=r;
  until r=0;
  writeln(g,a);
  end;
  close(f); close(g);
end.