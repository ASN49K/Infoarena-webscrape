program cmlsc;
var a,b,c:array[1..1024]of integer;
		f,g:text;
		m,n,i,s:integer;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do begin
								 read(a[i]);
								 c[a[i]]:=1;
								 s:=s+1;
								 end;
for i:=1 to m do begin
								 read(b[i]);
								 if c[a[i]]=0 then begin c[a[i]]:=1; s:=s+1;end;
								 end;
writeln(g,s);
for i:=1 to 1024 do
	if c[i]=1 then write(g,i);
close(f);close(g);
end.