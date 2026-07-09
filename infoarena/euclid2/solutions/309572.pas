var f,g:text;
n,i,a,b,aux:longint;
begin
assign(f,'cmmdc.in');reset(f);
assign(g,'cmmdc.out');rewrite(g);
readln(f,n);
for i:=1 to n do begin
readln(f,a,b);
while a mod b>0 do begin
aux:=a mod b;
a:=b;
b:=aux;
end;
writeln(g,b);
end;
close(f);
close(g);
end.