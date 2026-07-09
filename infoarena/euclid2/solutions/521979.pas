var a,b,aux,t:longint;

begin
 assign(input,'euclid2.in');
 assign(output,'euclid2.out');
 reset(input);
 rewrite(output);
 readln(t);
 while t<>0 do
  begin
   readln(a,b);
   while b<>0 do
     begin
        aux:=(a mod b);
        a:=b;
        b:=aux;
     end;
   writeln(a);
   t:=t-1;
  end;
 close(input);
 close(output);
end.
