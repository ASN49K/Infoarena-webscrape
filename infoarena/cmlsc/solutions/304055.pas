var m,n,i,j,bst:word;
d:array[0..1024,0..1024] of 0..1023;
a,b,sir:array[0..1024] of 1..256;
f,g:text;
begin
    assign(f,'cmlsc.in');reset(f);
    assign(g,'cmlsc.out');rewrite(g);
      readln(f,m,n);
      for i:=1 to m do
      read(f,a[i]);
      readln(f);
      for i:=1 to n do
      read(f,b[i]);
      bst:=0;
      for i:=1 to m do
        for j:=1 to n do
        if a[i]=b[j] then
        d[i,j]:=1+d[i-1,j-1] else
        begin



           if d[i-1,j]>d[i,j-1] then d[i,j]:=d[i-1,j] else
           d[i,j]:=d[i,j-1];


        end;


      i:=m;j:=n;
      while (i>=1) and (j>=1) do begin
         if a[i]=b[j] then begin
             inc(bst);
             sir[bst]:=a[i];
             dec(i);
             dec(j);

         end else
         if d[i-1,j]<d[i,j-1] then dec(j)
         else dec(i);

     end;

      writeln(g,bst);
      for i:=bst downto 1 do
      write(g,sir[i],' ');




      {
      for i:=1 to m do begin
          for j:=1 to n do
          write(g,d[i,j]);
          writeln(g);
      end;  }

      {
      for i:=1 to m do
      write(g,a[i]);
      writeln(g);
      for i:=1 to n do
      write(g,b[i]);}

    close(f);
    close(g);

end.