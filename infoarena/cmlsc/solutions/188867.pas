program cmlsc;
var a,b:array[1..1024]of integer;
		f,g:text;
		m,n,i,min,max,s:integer;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
min:=maxint;
max:=-maxint;
for i:=1 to n do begin
								 read(f,s);
								 a[s]:=1;

								 end;
n:=0;
for i:=1 to m do begin
								 read(f,s);
								 if a[s]=1 then begin
																if s>max then max:=s;
																if s<min then min:=s;
																a[s]:=2;
																n:=n+1;
																end;
								 end;
								 writeln(g,n);
for i:=min to max do
	if a[i]=2 then write(g,i,' ');
close(f);close(g);
end.