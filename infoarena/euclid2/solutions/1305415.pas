var t,aux,i,a,b:longint;
f,g:text;
begin

assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);

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