program alex;
var f:text;
    a,b,c:array[0..1100]of integer;
    viz,z:array[-100..256]of integer;
    m,n,i,max,k:longint;
begin
assign(f,'cmlsc.in');reset(f);
readln(f,m,n);
for i:=1 to m do
    begin
    read(f,a[i]);
    viz[a[i]]:=viz[a[i]]+1;
    end;
readln(f);
for i:=1 to n do
    begin
    read(f,b[i]);
    z[b[i]]:=z[b[i]]+1;
    end;
close(f);
if n<m then max:=m
       else max:=n;
k:=0;
for i:=1 to max do
    begin
    if viz[a[i]]<>0 then begin
                         if z[a[i]]<>0 then begin
                                            k:=k+1;
                                            c[k]:=a[i];
                                            z[a[i]]:=z[a[i]]-1;
                                            viz[a[i]]:=viz[a[i]]-1;
                                            end;
                         end;
    end;
assign(f,'cmlsc.out');rewrite(f);
writeln(f,k);
for i:=1 to k do
    write(f,c[i],' ');
close(f);
end.