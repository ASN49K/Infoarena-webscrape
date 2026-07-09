var a,b,t,i:longint;

function euclid(a,b:longint):longint;
var aux:longint;
begin
 while b<>0 do
  begin
   aux:=a mod b;
   a:=b;
   b:=aux;
  end;
 euclid:=a;
end;

begin
 assign(input,'euclid2.in');
 reset(input);
 assign(output,'euclid2.out');
 rewrite(output);
 readln(t);
 for i:=1 to t do
  begin
   readln(a,b);
   writeln(euclid(a,b));
  end;
 close(input);
 close(output);
end.
