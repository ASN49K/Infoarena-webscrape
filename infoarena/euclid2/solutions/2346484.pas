var a,b,i,aux:longint;
    f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f);
while not eof(f) do
begin
readln(f,a,b);
if a<b then
   begin
        aux:=a;
        a:=b;
        b:=aux;
   end;
           while b<>0 do
                    begin
                         aux:=a mod b;
                         a:=b;
                         b:=aux;
                    end;
           writeln(g,a);
end;
close(f);
close(g);
end.