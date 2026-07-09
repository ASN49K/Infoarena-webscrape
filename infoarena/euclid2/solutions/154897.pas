type vec=array[1..2000000] of 0..1;
     vec2=array[1..2000] of longint;
var v:vec;
    v2:vec2;
    n,i,j,k:longint;

procedure ciur;
var i,j:longint;
begin
k:=0;
for i:=2 to n do
	if v[i]=0 then
		begin
                inc(k);
		j:=i+i;
		while j<=n do
			begin
			v[j]:= 1;
			j:=j+i;
			end;
		end;
end;
begin {main}
assign(input,'ciur.in');reset(input);
assign(output,'ciur.out');rewrite(output);

read(n);
ciur;
writeln(k);

end.