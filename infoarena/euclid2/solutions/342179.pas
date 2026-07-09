var i,j,a,z,ii:longint;
    t,te:text;
begin
assign(t,'euclid2.in'); reset(t);
assign(te,'eulcid2.out'); rewrite(te);
readln(t,z);
for ii:=1 to z do
begin
readln(i,j);
    if j>i then
      begin
        a:=j;
        j:=i;
        i:=a;
      end;

repeat
  begin
    a:=j;
    j:=i mod j;
    i:=a;
  end;
until j=0;
writeln(te,i);
end;
close(te);
end.
