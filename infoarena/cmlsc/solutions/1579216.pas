program cmlsc;
var
	i,l,j,n,m:Longint;
	a,b,t:array[1..1024] of Integer;
	d:array[0..1024,0..1024] of Integer;
	f1,f2:text;
function max(a,b:Integer): Integer;
begin
	if a>b then max:=a 
	else max:=b;
end;
begin
	assign(f1,'cmlsc.in');
	assign(f2,'cmlsc.out');
	reset(f1); rewrite(f2);
	read(f1,n,m);
	for i:=1 to n do 
		read(f1,a[i]);
	for j:=1 to m do
		read(f1,b[j]);
	for i:=1 to n do
		for j:=1 to m do
		if a[i]=b[j] then
			d[i,j]:=d[i-1,j-1]+1
		else
			d[i,j]:=max(d[i-1,j],d[i,j-1]);
	i:=n; j:=m; l:=0;

	while i<>0 do 
	begin
		if a[i]=b[j] then
		begin
			inc(l);
			t[l]:=a[i];
			dec(i); dec(j)
		end 
		else
			if d[i-1,j]<d[i,j-1] then 
			dec(j) else dec(i);
	end;
		writeln(f2,l);
		for i:=l downto 1 do
			write(f2,t[i],' ');
	close(f1); close(f2);
end.
