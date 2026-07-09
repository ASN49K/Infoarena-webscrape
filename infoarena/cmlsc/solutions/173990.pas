program cmlsc;
var f,g:text;
    a,b:array[1..1024] of integer;
    c:array[0..102,0..102] of integer;
    i,j,m,n,nr:longint;
procedure rec(i,j:longint);
   var q,w:longint;
  begin
     if a[i]=b[j] then
                    begin
                       inc(nr);
                      if (nr<c[m,n]) then rec(i-1,j-1);
                      write(g,a[i],' ');
                    end
                  else
                     begin
                       if c[i-1,j]>c[i,j-1] then begin q:=i-1; w:=j; end
                           else begin q:=i; w:=j-1; end;
                       rec(q,w);
                     end;
   end;
begin
assign(f,'cmlsc.in'); reset(f);
readln(f,m,n);
for i:=1 to m do begin
                  read(f,a[i]);
                  c[i,0]:=0;
                 end;
readln(f);
for i:=1 to n do
              begin
                read(f,b[i]);
                c[0,i]:=0;
              end;
close(f);
for i:=1 to m do
  for j:=1 to n do
     begin
       if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
         else
            begin
              c[i,j]:=c[i-1,j];
              if c[i,j-1]>c[i,j] then c[i,j]:=c[i,j-1];
            end;
     end;

assign(g,'cmlsc.out'); rewrite(g);
writeln(g,c[m,n]);
nr:=0;
rec(m,n);
close(g);
end.