program submaxcom;
var     f,g:text;
        s1,s2:array[1..1024] of byte;
        a,b:array[0..1025,0..1025] of byte;
        m,n,i,j:byte;

procedure scrie(i,j:byte);
begin
  if (i>0) and (j>0)   then
   if (s1[i]=s2[j]) then
     begin
        scrie(i-1,j-1);
        write(g,s2[j],' ');
     end
    else
      if a[i-1,j]>a[i,j-1] then  scrie(i-1,j)
         else scrie(i,j-1);

end;
begin
  assign(f,'cmls.in');
  reset(f);
  assign(g,'cmls.out');
  rewrite(g);
  readln(f,n,m);
  for i:=1 to n do
     read(f,s1[i]);
  readln(f);
  for j:=1 to m do
    read(f,s2[j]);
  for i:=1 to n do
     for j:=1 to m do
       begin
          if (s1[i]=s2[j]) then a[i,j]:=a[i-1,j-1]+1
            else
              if a[i-1,j]>a[i,j-1] then
                 a[i,j]:=a[i-1,j]
              else a[i,j]:=a[i,j-1];

       end;
       i:=n; j:=m;
  writeln(g,a[i,j]);
  scrie(i,j);
 { while (i>=1) and (j>=1) do
     begin
       if s1[i]=s2[j] then
          begin
            writeln(s1[i]);
            dec(i); dec(j);
          end
        else
          begin
             if  a[i-1,j]>a[i,j-1] then dec(i)
               else dec(j);
          end;
     end;}

  {for j:=m downto 1 do
     if a[n,j]>a[n,j-1] then writeln(s2[j]);  }
  {for i:=1 to n do
    begin
      for j:=1 to m do
         write(g,a[i,j],' ');
      writeln(g);
    end;}
  close(f); close (g);
end.