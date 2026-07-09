var f,g:text;
    A,B,C:array[1..20] of byte;
    ttl,la,lb,i,j:integer;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
readln(f,la,lb);
for i:=1 to la do
read(f,a[i]);
for i:=1 to lb do
read(f,b[i]);
for i:=1 to la do begin
  for j:=1 to lb do
      if a[i]=b[j] then begin ttl:=ttl+1;c[ttl]:=a[i];end;
end;
writeln(g,ttl);
for i:=1 to ttl do
write(g,c[i],' ');
close(g);
end.