var t,aux,i,bo,a,b:longint;
f,g:text;
begin

assign(f,'euclid.in'); reset(f);
assign(g,'euclid.out'); rewrite(g);

read(f,t);


for i:=1 to t do begin
read(f,a);
read(f,b);
while b<>0 do begin
 aux:=a mod b;
 a:=b;
 b:=aux;
end;
writeln(g,a);
end;





reset(g);
reset(f);

end.