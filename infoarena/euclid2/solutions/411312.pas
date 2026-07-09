var
 a,b:longint;
 t:1..100000;
function divizor(a,b:longint):longint;
var
 aux:longint;
 rest:longint;
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
procedure facem;
var
 f,g:text;
begin
 assign(f,'euclid2.in'); assign(g,'euclid2.out');
 reset(f); rewrite(g);
 readln(f,t);
 while not eof(f) do
  begin
   readln(f,a,b);
   writeln(g,divizor(a,b));
  end;
 close(f);
 close(g);
end;
begin
 facem;
end.


