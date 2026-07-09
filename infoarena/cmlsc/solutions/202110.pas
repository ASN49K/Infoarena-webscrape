program cel_mai_lung_subsir_comun;
var a,b,d:array[1..1050] of word;
	c:array[0..1050,0..1050] of word;
	m,n,p:word;

	procedure citire;
	var f:text; i:word;
	begin
		assign(f,'cmlsc.in'); reset(f);
		readln(f,m,n);
		for i:=1 to m do read(f,a[i]);
		for i:=1 to n do read(f,b[i]);
		close(f);
	end;

	function max(x,y:word):word;
	begin
		if x>y then max:=x else max:=y;
	end;

	procedure lungimea;
	var i,j:word;
	begin
		for i:=1 to m do
			for j:=1 to n do begin
				if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
				else c[i,j]:=max(c[i-1,j],c[i,j-1]);
			end;
		p:=c[m,n]+1;
	end;
	
	procedure sirul(i,j:word);
	begin
		if (i=0) or (j=0) then exit;
		if a[i]=b[j] then begin
			dec(p); d[p]:=a[i];
			sirul(i-1,j-1);
		end
		else if c[i-1,j]>c[i,j-1] then sirul(i-1,j)
		else sirul(i,j-1);
	end;
	
	procedure scriere;
	var f:text; i:word;
	begin
		assign(f,'cmlsc.out'); rewrite(f);
		writeln(f,c[m,n]); write(f,d[1]);
		for i:=2 to c[m,n] do write(f,' ',d[i]);
		writeln(f);
		close(f);
	end;
	
BEGIN
	citire;
	lungimea;
	sirul(m,n);
	scriere;
END.
