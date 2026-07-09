type tip1=0..2000000000;
     tip2=0..100000;
var a,b,aux:tip1;
    t:tip2;

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
