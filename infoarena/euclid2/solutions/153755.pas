var i,a,b,x,t:longint;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out'); reset(input);rewrite(output);
readln(T);
for i:=1 to t do begin
readln(a,b);
if a>b then begin
			x:=a;
			a:=b;
			b:=x;
			end;
while a<>0 do
	begin
	x:=b mod a;
	b:=a;
	a:=x;
	end;
writeln(B);
end;
close(input);
close(output);
end.
