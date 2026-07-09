var  i,n,a,b,r:longint;  
f,g:text;  
begin  
assign(f,'euclid2.in'); reset(f);  
assign(g,'euclid2.out'); rewrite(g);  
   
readln(f,n);  
for i := 1 to n do begin
	readln(f,a,b);
	r:=0;
	while b<>0 do begin
		r:=a mod b;
		b:=a;
		a:=r;
	end;
	writeln(g,a);
end;
close(f);  
close(g);  
   
end.  