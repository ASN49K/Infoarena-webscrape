program cmmdc;
var i,n:longint;
		a,b:int64;
		f1,f2:text;

function cmmdc(a,b:int64):int64;
	var aux:int64;
	begin
		while b<>0 do 
			begin
				aux:=b;
				b:=a mod b;
				a:=aux;
			end;
			cmmdc:=a;
	end;

begin
	assign(f1,'euclid2.in'); reset(f1);
	assign(f2,'euclid2.out'); rewrite(f2);
	readln(f1,n);
	for i:=1 to n do 
	begin 
		readln(f1,a,b);
		writeln(f2,cmmdc(a,b));
	end;
	close(f1);
	close(f2);
end.