program cel_mai_lung_subsir_comun; 								//programare dinamica

var a,b:array[1..1024] of integer;
	t:array[1..1025,1..1025] of integer;
	i,j,m,n:integer;
	f,g:text;


function max(a,b:integer):integer;

begin 

	max:=a;
	if b>a then max:=b;

end;


BEGIN

	assign(f,'cmlsc.in');reset(f);
	readln(f,n,m);
	for i:=1 to n do
	  read(f,a[i]);
	readln(f);
	for i:=1 to m do
	  read(f,b[i]);
	close(f);

	for i:=n downto 1 do 												//bottom up
	  for j:=m downto 1 do
	    if a[i]=b[j] then t[i,j]:=t[i+1,j+1]+1
	    			 else t[i,j]:=max(t[i+1,j],t[i,j+1]);

	assign(g,'cmlsc.out');rewrite(g);
	writeln(g,t[1,1]);

	i:=1; j:=1;

	while t[i,j]<>0 do
		if t[i+1,j+1]=t[i,j] then
			begin
			  inc(i);
			  inc(j);
			end		
							 else
							   if t[i+1,j]=t[i,j] then inc(i)
							   					  else
							   					    if t[i,j+1]=t[i,j] then inc(j)
							   					    			else
							   					    			  begin 
							   					    			    write(g,a[i],' ');
							   					    			    inc(i);
							   					    			    inc(j);
							   					    			  end;
	close(g);

END.





