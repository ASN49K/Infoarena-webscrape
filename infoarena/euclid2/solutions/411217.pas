var
 t,a,b,i:longint;
 f,g:text;
function divizor(a,b:longint):longint;
begin
 while a<>b do
  if a<b
   then
    b:=b-a
   else
    a:=a-b;
  divizor:=a;
end;
begin
 assign(f,'euclid2.in'); assign(g,'euclid2.out');
 reset(f); rewrite(g);
 readln(f,t);
 for I:=1 to t do
  begin
   readln(f,a,b);
   writeln(g,divizor(a,b));
  end;
 close(f);
 close(g);
end.


