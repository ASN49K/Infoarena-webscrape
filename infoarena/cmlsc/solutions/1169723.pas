program cmlsc;


var
 a,b,c:array[1..1024] of word;
 m,n,i,j,l,x:word;
 f:text;
 k:boolean;

begin
l:=0;
x:=0;
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
for i:=1 to l-1 do if (c[i]=c[i+1]) then begin
                                       k:=false;
                                       for j:=i+1 to l-1 do if c[j]<>c[j+1] then
                                                                            begin
                                                                            c[j]:=c[j+1];
                                                                            k:=true;
                                                                            end;
                                       if k then x:=x+1;
                                       end;
if c[l]=c[l-1] then l:=l-1;


assign(f,'cmlsc.out');
rewrite(f);
writeln(f,l-x);
for i:=1 to l-x do write(f,c[i],' ');
close(f);
end.