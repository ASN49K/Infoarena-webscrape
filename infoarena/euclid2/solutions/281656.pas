var n,i,a,b,rest,aux :longint;
    f,g :text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
read(f,n); readln(f);
for i:=1 to n do begin
                 readln(f,a,b);
                 if a<b then begin
                             aux:=a;
                             a:=b;
                             b:=aux;
                             end;
                 while b<>0 do begin
                               rest:=a mod b;
                               a:=b;
                               b:=rest;
                               end;
                 writeln(g,a);
                 end;
close(g);
end.