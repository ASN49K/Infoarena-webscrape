const nmax=1024;
var
   f:text;
   k,n,m,i,j:byte;
   lcs:array[0..nmax,0..nmax] of integer;
   a,b,c:array[1..nmax] of byte;
Begin
     assign(f,'cmlsc.in');
     reset(f);
     readln(f,m,n);
     for i:=1 to m do
         read(f,a[i]);
     readln(f);
     for i:=1 to n do
         read(f,b[i]);
     close(f);
     for i:=1 to m do
         lcs[i,0]:=0;
     for i:=1 to n do
         lcs[0,i]:=0;
     for i:=1 to m do
         for j:=1 to n do
             if a[i]=b[j] then lcs[i,j]:=lcs[i-1,j-1]+1
                          else
                              if lcs[i-1,j]>lcs[i,j-1] then lcs[i,j]:=lcs[i-1,j]
                                                       else lcs[i,j]:=lcs[i,j-1];
     assign(f,'cmlsc.out');
     rewrite(f);
     writeln(f,lcs[m,n]);
     k:=0; i:=m;j:=n;
     while (i>0) And (j>0) do
     begin
          if (a[i]=b[j]) then begin
                                   k:=k+1;
                                   c[k]:=a[i];
                                   i:=i-1;
                                   j:=j-1;
                              end
                          else
                              if lcs[i,j]=lcs[i-1,j] then i:=i-1
                                                     else j:=j-1;
     end;
     for i:=k downto 1 do
         write(f,c[i],' ');
     close(f)
End.
