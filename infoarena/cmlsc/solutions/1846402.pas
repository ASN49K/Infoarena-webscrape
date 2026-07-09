program nuem;
var x,v,z:array of longint;
    f,g:text;
    n,m,c,i,j:longint;
begin
    assign(f,'cmlsc.in');
    reset(f);
    assign(g,'cmlsc.out');
    rewrite(g);
    readln(f,n,m);
    setlength(x,n+1);
    setlength(v,m+1);
    if n>=m then
            setlength(z,n+1)
            else
            setlength(z,m+1);
    for i:=1 to n do
       read(f,x[i]);
       readln(f);
    for i:=1 to m do
        read(f,v[i]) ;
    for i:=1 to m do
      begin
          for j:=1 to n do
            begin
                if v[i]=x[j] then
                             z[j]:=z[j]+1
                             else
                if z[j]<z[j-1] then
                               z[j]:=z[j-1];
            end;
      end;
      writeln(g,z[n]);
      c:=1;
      for i:=1 to n do
        begin
           if z[i]=c then
             begin
                 write(g,x[i],' ');
                 c:=c+1;
             end;
        end;

close(f);
close(g);
end.
