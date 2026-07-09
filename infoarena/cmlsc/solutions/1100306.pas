type tab=array[1..1050] of longint;
	 tab2=array[0..1050,0..1050] of longint;
var a,b:text;
	u,t:tab;
	s:tab2;
	x,y,i:longint;

function max(a,b:longint):longint;
begin
	if a>b then max:=a else max:=b;
end;

procedure creeaza;
var i,j:longint;
begin
	for i:=1 to x do
		for j:=1 to y do
		begin
			if t[i]=u[j] then s[i,j]:=s[i-1,j-1]+1 else
			s[i,j]:=max(s[i-1,j],s[i,j-1]);
		end;
end;	

procedure gaseste(n,m:longint);
begin
	if s[n,m]>0 then
	if (s[n,m]>s[n-1,m]) and (s[n,m]>s[n,m-1]) then
	begin
		gaseste(n-1,m-1);
		write(b,t[n],' ');
	end else if s[n-1,m]>s[n,m-1] then 
		gaseste(n-1,m) else
		gaseste(n,m-1);
	
end;
	
begin
assign(a,'cmlsc.in');
reset(a);
assign(b,'cmlsc.out');
rewrite(b);
readln(a,x,y);

for i:=1 to x do
read(a,t[i]);

for i:=1 to y do
read(a,u[i]);

creeaza;

writeln(b,s[x,y]);

gaseste(x,y);


close(a);
close(b);
end.
