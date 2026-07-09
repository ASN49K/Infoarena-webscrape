program safs;
var f,g:text;
n,m,i,j,s,s2:integer;
a,b:array[1..1025] of integer;
c:array[0..1025,0..1025] of integer;
begin
   assign(f,'cmlsc.in');
   reset(f);
   assign(g,'cmlsc.out');
   rewrite(g);
     readln(f,n,m);
       for i:=1 to n do
         read(f,a[i]);
     for j:=1 to m do
       read(f,b[j]);
     for i:=1 to n do
       for j:=1 to m do
         begin
           if a[i]=b[j] then
              c[i,j]:=c[i-1,j-1]+1;
           if a[i]<>b[j] then
               if c[i-1,j]>c[i,j-1] then
                 c[i,j]:=c[i-1,j] else
                 c[i,j]:=c[i,j-1];
         end;
       s:=c[n,m];
       writeln(g,s);
      s2:=s;
      i:=n; j:=m;
      while s>=1 do begin
           while c[i-1,j]=s do
             i:=i-1;
           while c[i,j-1]=s do
             j:=j-1;
        a[s]:=b[j]; s:=s-1; i:=i-1; j:=j-1;
      end;
      for i:=1 to s2 do
        write(g,a[i],' ');
   close(f);
   close(g);
end.