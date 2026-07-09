var a,b,x:longint;
begin
assign(input,'euclid2.in');
assign(output,'euclid2.out');
readln(a,b);
if a>b then begin
			x:=a;
			a:=b;
			b:=x;
			end;
while a<>0 do
	begin
	x:=b mod a;
	b:=b div a;
	a:=x;
	end;
writeln(B);
close(input);
close(output);
end.
