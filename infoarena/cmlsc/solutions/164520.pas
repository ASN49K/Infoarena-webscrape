type vector=array [1..1024] of -257..256;
var v,w:vector;
i,j,m,n:integer;
f,g:text;
procedure subsir(v,w:vector;m,n:integer);
var i,j,k,l:integer;
ok:boolean;
q:vector;
begin
l:=0;
k:=0;
for i:=1 to m do begin
                 j:=l;
                 ok:=false;
                 repeat
                 j:=j+1;
                 if v[i]=w[j] then begin
                                   k:=k+1;
                                   q[k]:=v[i];
                                   l:=j;
                                   ok:=true;
                                   end;
                 until (j=n) or (ok);
                 end;
writeln(g,k);
for i:=1 to k do write(g,q[i],' ');
end;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,m,n);
for i:=1 to m do read(f,v[i]);
readln(f);
for i:=1 to n do read(f,w[i]);
subsir(v,w,m,n);
close(f);
close(g);
end.