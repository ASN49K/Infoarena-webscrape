program cmlsc;
var a,b:array[1..1024]of integer;
		f,g:text;
		m,n,i,s:integer;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do begin
								 read(f,s);
								 a[s]:=1;
								 end;
n:=0;
for i:=1 to m do begin
								 read(f,s);
								 if a[s]=1 then begin a[s]:=2; n:=n+1; end;
								 end;
								 writeln(g,n);
for i:=1 to 1024 do
	if a[i]=2 then write(g,i,' ');
close(f);close(g);
end.