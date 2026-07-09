var f,g:text;
    m,n,i,j,nr:integer;
    x:array[0..1024,0..1024] of integer;
    a,b:array[1..1024] of word;
procedure rec(i,j:integer);
        begin
          if (i<>0)and(j<>0) then
             begin
               if a[i]=b[j] then
                  begin
                    inc(nr);
                    if nr<x[m,n] then rec(i-1,j-1);
                    write(g,a[i],' ');
                  end
                           else
                  begin
                    if x[i-1,j]>x[i,j-1] then rec(i-1,j)
                                         else rec(i,j-1);
                  end;
             end;
        end;

begin
assign(f,'cmlsc.in'); reset(f);
assign(g,'cmlsc.out'); rewrite(g);
readln(f,m,n);
for i:=1 to m do
   begin
     read(f,a[i]); x[i,0]:=0;
   end;
x[0,0]:=0;
readln(f);
for i:=1 to n do
  begin
    read(f,b[i]); x[0,i]:=0;
  end;
for i:=1 to m do
   for j:=1 to n do
     begin
       if a[i]=b[j] then x[i,j]:=x[i-1,j-1]+1
                    else
                      begin
                        x[i,j]:=x[i-1,j];
                        if x[i,j]<x[i,j-1] then x[i,j]:=x[i,j-1];
                      end;
     end;
writeln(g,x[m,n]);
nr:=0;
rec(m,n);
close(f); close(g);
end.
