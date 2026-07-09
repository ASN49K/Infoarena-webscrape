function gcd(a, b:integer):integer;
begin
    if (b = 0) then
       gcd:=a 
    else
       gcd:=gcd(b, a mod b);
end;

var x,y,i,n:integer;

begin
	assign(input,'euclid2.in');
	reset(input);
	assign(output,'euclid2.out');
	rewrite(output);
	read(n);
	for i:=1 to n do
	begin
	  read(x,y);
		writeln(gcd(x,y));
	end;
end.