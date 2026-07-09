Program cmlsc;
              var m,n,rs,i,j,x:integer;
                  a,b,c:array[1..1024]of byte;
                  fi,fo:text;
begin
     assign(fi,'cmlsc.in');reset(fi);
     assign(fo,'cmlsc.out');rewrite(fo);
     read(fi,m);
     readln(fi,n);
     i:=1;
     while not eoln(fi)and(i<=m) do
                          begin
                          if i=m then readln(fi,a[i])else
                          read(fi,a[i]);
                          inc(i);end;
     i:=1;
     while not eoln(fi)do begin
                          read(fi,b[i]); inc(I);end;
     rs:=0;x:=1;
     for i:=1 to m do
                     for j:=1 to n do
                                     if a[i]=b[j] then
                                                      begin
                                                           c[x]:=a[i];
                                                           inc(rs);
                                                           inc(x);
                                                      end;
     writeln(fo,rs);
     for i:=1 to rs do
                      write(fo,c[i],' ');
     close(fo);
end.


