program cmlsc;


var
 a,b,c:array[1..1024] of word;
 m,n,i,j,l:word;
 f:text;
begin
assign(f,'cmlsc.in');
reset(f);
readln(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do
              begin
              read(f,b[i]);
              for j:=1 to n do if a[j]=b[i] then begin
                                                  l:=l+1;
                                                  c[l]:=a[j];
                                                 end;
              end;
close(f);
i:=1;
assign(f,'cmlsc.out');
rewrite(f);
repeat
if c[i]=c[i+1] then i:=i+1
               else write(f,c[i],' ');
i:=i+1;
until (i>l);
close(f);
end.