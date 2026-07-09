var v1,v2,v3:array [1..1024] of -257..256;
m,n,k,l,i,j:0..1024;
ok:boolean;
f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
readln(f,m,n);
for i:=1 to m do read(f,v1[i]);
readln(f);
for i:=1 to n do read(f,v2[i]);
l:=n+1;
k:=0;
for i:=m downto 1 do begin
                     ok:=false;
                     j:=l;
                     repeat
                     j:=j-1;
                     if (v1[i]=v2[j]) and (j>0) then begin
                                         k:=k+1;
                                         v3[k]:=v1[i];
                                         ok:=true;
                                         l:=j;
                                         end;
                     until (j=0) or (ok);
                     end;
writeln(g,k);
for i:=k downto 1 do write(g,v3[i],' ');
close(f);
close(g);
end.

