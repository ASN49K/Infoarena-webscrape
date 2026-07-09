var n,m,i,x,j,k,nr:integer;
    a:array[-1..1025,-1..1025] of integer;
    f,g:text;
    a1,a2,d:array[1..1025] of integer;
begin
     assign(f,'cmlsc.in'); reset(f);
     assign(g,'cmlsc.out'); rewrite(g);
     readln(f,n,m);
     for i:=1 to n do read(f,a1[i]);     readln(f);
     for i:=1 to m do read(f,a2[i]);
     for i:=1 to m do a[-1,i]:=a2[i];
     for i:=1 to n do a[i,-1]:=a1[i];
     for i:=1 to n do
     begin
          for j:=1 to m do
          begin
               if a1[i]=a2[j] then a[i,j]:=a[i-1,j-1]+1
                              else if a[i-1,j]>a[i,j-1] then a[i,j]:=a[i-1,j]
                                                        else a[i,j]:=a[i,j-1];
          end;
     end;  k:=0;
     writeln(g,a[n,m]);
     nr:=a[n,m];            i:=n; j:=m;
     while nr<>0 do
     begin
          if a1[i]<>a2[j] then
               if a[i-1,j]>a[i,j-1] then dec(i)
                                    else dec(j)
                          else
                          begin
                              inc(k); d[k]:=a1[i]; dec(i); dec(j); dec(nr);
                          end;
     end;
     for i:=k downto 1 do write(g,d[i],' ');
     writeln(g);
     close(g);
end.