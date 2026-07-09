program nuem;
var x,v,z:array of longint;
    a:array of array of longint;
    f,g:text;
    n,m,c,k,i,j:longint;
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
    setlength(a,m+1,n+1);
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
                             a[i,j]:=a[i-1,j-1]+1
                             else
                if a[i-1,j]>=a[i,j-1]then
                                     a[i,j]:=a[i-1,j]
                                     else
                                     a[i,j]:=a[i,j-1];
            end;
      end;
      writeln(g,a[m,n]);
      k:=0;
      while a[m,n]<>0 do
        begin
            if (v[m]=x[n]) then
              begin
                   k:=k+1;
                   z[k]:=x[n];
                   m:=m-1;
                   n:=n-1;
              end
              else
              if a[m-1,n]=a[m,n] then
                             m:=m-1
                             else
                             n:=n-1;
        end;
      for i:=k downto 1 do
         write(g,z[i],' ' );
close(f);
close(g);
end.
