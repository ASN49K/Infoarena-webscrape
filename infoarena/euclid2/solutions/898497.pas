var
a,b,c,r,n,i,aux:integer;
f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
for i:=1 to n do begin
        readln(f,a,b);
        if b>a then begin
                                aux:=b;
                                b:=a;
                                a:=aux;
                                end;
while  b<>0 do
        begin
        c:=a mod b;
        a:=b;
        b:=c;
        end;

writeln(g,a);
end;
close(f);
close(g);
end.