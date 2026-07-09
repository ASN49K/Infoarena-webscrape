program euclid;
var
 t,i:integer;
 a,b:longint;
 f,g:text;
begin
 assign(f,'euclid2.in');reset(f);
 assign(g,'euclid2.out');rewrite(g);
 readln(f,t);
 for i:=1 to t do
  begin
   read(f,a);
   readln(f,b);
   while a<>b do
    if a>b then a:=a-b
           else b:=b-a;
   writeln(g,a);
  end;
 close(f);
 close(g);
end.
