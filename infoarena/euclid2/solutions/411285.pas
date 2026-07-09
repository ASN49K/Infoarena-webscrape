var
 t,a,b,i:longint;
 f,g:text;
function divizor(a,b:longint):longint;
var
 aux,rest:longint;
begin
 if a<b
  then
   begin
    aux:=a;
    a:=b;
    b:=aux;
   end;
 rest:=a mod b;
 while rest<>0 do
  begin
   a:=b;
   b:=rest;
   rest:=a mod b;
  end;
  divizor:=b;
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


