program arhiva000;
type tip1=1..2000000000;
     tip2=1..100000;
var a,b,t:longint;

function euclid(a,b:longint):longint;
var aux:longint;
begin
 while b<>0 do
   begin aux:=(a mod b);
         a:=b; b:=aux;
   end;
 euclid:=a;
end;

begin
 assign(input,'euclid2.in'); assign(output,'euclid2.out');
 reset(input); rewrite(output);
 readln(t);
 while t<>0 do
  begin readln(a,b);
        writeln(euclid(a,b));
        t:=t-1;
  end;
 close(input); close(output);
end.
