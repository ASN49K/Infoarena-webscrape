var a,b:longint;
begin
	assign(input,'euclid2.in'); reset(input);
	assign(output,'euclid2.out'); rewrite(output);
	read(input,a,b);
	while b<>0 do
		if a>b then a:=a-b
		else b:=b-a;
	write(output,a);
end.
