program cmmdc;
var i,n:longint;
		a,b,aux:^int64;
		f1,f2:text;

begin
	assign(f1,'euclid2.in'); reset(f1);
	assign(f2,'euclid2.out'); rewrite(f2);
	readln(f1,n);
	new(a);
	new(b);
	new(aux);
	for i:=1 to n do
	begin
		readln(f1,a^,b^);
		while b^<>0 do
			begin
				aux^:=b^;
				b^:=a^ mod b^;
				a^:=aux^;
			end;
		writeln(f2,a^);
	end;
	close(f1);
	close(f2);
end.
