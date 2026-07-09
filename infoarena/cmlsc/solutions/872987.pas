program info;
var a,b,viz1,viz2,sir:array[1..1024] of byte;
    i,j,c,m,n:integer;
    f,g:text;
begin
 assign(f,'cmlsc.in'); reset(f);
 assign(g,'cmlsc.out'); rewrite(g);
   readln(f,m,n);
     for i:=1 to m do
      begin
      read(f,a[i]);
      viz1[a[i]]:=1;
      end;
     for i:=1 to n do
     begin
      read(f,b[i]);
      viz2[b[i]]:=1;
     end;
   for i:=1 to 1024 do
     begin
      if (viz1[i]=1) and (viz2[i]=1) then
        begin
          c:=c+1;
          sir[c]:=i;
        end;
     end;
     writeln(g,c);
 for i:=1 to c do
    write(g,sir[i],' ');


 close(f);
 close(g);
end.