var f,g:text;
    i,t,a,b:longint;
begin
 assign(f,'euclid2.in');reset(f);
 assign(g,'euclid2.out');rewrite(g);
 read(f,t);
 for i:=1 to t do
  begin
  readln(f,a,b);
  repeat
   if a>b then a:=a-b;
   if b>a then b:=b-a;
  until a=b;
  writeln(g,a);
  end;
 close(f);close(g);
end.