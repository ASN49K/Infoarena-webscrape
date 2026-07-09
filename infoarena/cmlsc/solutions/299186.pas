var a,b,rez:array[1..1024] of integer;
    d:array[0..1024,0..1024] of integer;
	m,n,i,j,nr:integer;

function max(a,b:integer):integer;
begin
	if a>b then max:=a else max:=b;
end;

begin
assign(input,'cmlsc.in');reset(input);
assign(output,'cmlsc.out');rewrite(output);
readln(m,n);
for i:=1 to m do read(a[i]);
for i:=1 to n do read(b[i]);

fillchar(d,sizeof(d),0);
for i:=1 to m do
  for j:=1 to n do
    if a[i]=b[j] then d[i,j] := d[i-1,j-1]+1
			     else d[i,j] := max(d[i-1,j],d[i,j-1]);
writeln(d[m,n]);

i:=m; j:=n;
while (i>0)and(j>0) do
begin
	if (a[i] = b[j]) then
		begin
		inc(nr);
		rez[nr]:=a[i];
		dec(i); dec(j);
		end
	else if d[i-1,j]<d[i,j-1] then
		dec(j)
	else dec(i);
end;

for i:=nr downto 1 do write(rez[i],' ');
writeln;

close(input); close(output);
end.
		
	

