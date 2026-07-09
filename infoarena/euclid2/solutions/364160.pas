program euclid;
var f,g : text;
    t,a,b,r,i,d : longint;
 begin
  assign(f,'euclid2.in');
  assign(g,'euclid2.out');
  reset(f);
  rewrite(g);
  readln(f,t);
  i:=1;
  while i<=t do
  begin
   read (f,a);
   readln (f,b);
  while b>0 do
   begin
    r:=a mod b;
    a:=b;
    b:=r;
   end;d:=a;
  writeln(g,d);inc(i);
  end;
  close(f);
  close(g);
 end.

