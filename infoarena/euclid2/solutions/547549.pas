var a,b,t,i:longint;

procedure euclid(a,b:longint);
var aux:longint;
begin
 while b<>0 do
  begin
   aux:=(a mod b);
   a:=b;
   b:=aux;
  end;
 writeln(a);
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
   euclid(a,b);
  end;
 close(input);
 close(output);
end.
