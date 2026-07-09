program euclid;
var
 t,i:integer;
 a,b:longint;
 f,g:text;
begin
 assign(f,'euclid2.in');reset(f);
 assign(g,'euclid2.out');rewrite(g);
 readln(f,t);
 if (t>=1)and(t<=100000) then
  for i:=1 to t do
   begin
    read(f,a);
    readln(f,b);
    if (a>=2)and(b>=2)and(a<=2000000000)and(b<=2000000000) then
     begin
      while a<>b do
       if a>b then a:=a-b
              else b:=b-a;
      writeln(g,a);
     end;
   end;
 close(f);
 close(g);
end.
