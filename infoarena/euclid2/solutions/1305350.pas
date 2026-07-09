var t,aux,i,cmmdc,bo,a,b:longint;
f,g:text;
begin

assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);

read(f,t);


for i:=1 to t do begin
 bo:=1;
 while bo=1 do begin
  read(f,a);
  read(f,b);
  if a<b then begin
  aux:=a; a:=b; b:=aux;

  end;
 while a>b do begin
 a:=a-b;
 end;
 writeln(g,a);
 bo:=0;
 end;
end;

reset(g);
reset(f);

end.