type vector=array [1..1024] of byte;
var f,g:text;
    a,b,c:vector;
    m,n,i,j,k:integer;
begin
assign(f,'cmlsc.in');
reset(f);
assign(g,'cmlsc.out');
rewrite(g);
read(f,n);
read(f,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
for i:=1 to n do begin
                 for j:=1 to m do if a[i]=b[j] then begin
                                                    k:=k+1;
                                                    c[k]:=a[i];
                                                    end;
                 end;
writeln(g,k);
for i:=1 to k do write(g,c[i],' ');
close(f);
close(g);
end.