var f,g:text;
    A,B,C:array[1..1025] of integer;
    ttl,la,lb,i,j,k:integer;
    ok:boolean;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
ttl:=0;
readln(f,la,lb);
for i:=1 to la do
	read(f,a[i]);
for i:=1 to lb do
	read(f,b[i]);
for i:=1 to la do begin
  for j:=i+1 to lb do
      if a[i]=b[j] then begin
         ok:=false;
         for k:=1 to ttl do
             if a[i]=c[k] then ok:=true;
         if ok=false then begin
            ttl:=ttl+1;
            c[ttl]:=a[i];
            end;
         end;
end;
writeln(g,ttl);
for i:=1 to ttl do
write(g,c[i],' ');
close(g);
end.