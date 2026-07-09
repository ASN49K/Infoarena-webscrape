program subsirmaximal;
var     sub,x,y:array[1..1024] of byte;
        i,k,j,n,m:integer;
        f,g:text;
begin
   assign(f,'cmlsc.in'); reset(f);
   assign(g,'cmlsc.out'); rewrite(g);
   readln(f,n,m);
   for i:=1 to n do
       read(f,x[i]);
   readln(f);
   for i:=1 to m do
     read(f,y[i]);
   for i:=1 to n do
     begin
        for j:=1 to i do
          if y[j]=x[i] then
            begin
              k:=k+1;
              sub[k]:=x[i];
              break;
            end;
     end;
  writeln(g,k);
   for i:=1 to k do
      write(g,sub[i],' ');
   close(f);
   close(g);
end.
