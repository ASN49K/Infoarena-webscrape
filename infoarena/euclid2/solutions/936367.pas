program euclid;
var f,g:text;a,b,t,i,rest:longint;
 begin
  assign(f,'euclid2.in');reset(f);
  assign(g,'euclid2.out');rewrite(g);
  readln(f,t);
  for i:=1 to t do
   begin
    readln(f, a,b);
    repeat
     rest:=a mod b;
     a:=b;
     b:=rest;
    until b=0;
    writeln(g,a);
   end;
  close(f);
  close(g);
 end.