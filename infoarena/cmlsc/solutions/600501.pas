Program Chisinau;
var fi, fo : text;
    a,b : array[0..1000] of integer;
    sir : array[0..1000] of integer;
    d : array[0..100,0..100] of integer;
    m,n,bst : integer;
    k,i,j:integer;
    Function maxim(a,b : integer):integer;
    begin
            if a>b then maxim:=a
                   else maxim:=b;
    end;

begin
      assign(fi,'cmlsc.in');
      reset(fi);
      readln(fi,n,m);
      for i:=1 to n do read(fi,a[i]);
      for i:=1 to m do read(fi,b[i]);

      for i:=1 to n do
          for j:=1 to m do d[i,j]:=0;
      for i:=1 to n do
                for j:=1 to m do
                                if a[i]=b[j] then d[i,j]:=1+d[i-1,j-1]
                                              else d[i,j]:=maxim(d[i-1,j],d[i,j-1]);

      i:=n; j:=m;   bst:=0;

      for k:=1 to maxim(m,n) do
      if a[i]=b[j] then begin
                        bst:=bst+1;
                        sir[bst]:=a[i];
                        i:=i-1;
                        j:=j-1;
                        end
                         else if d[i-1,j]<d[i,j-1] then j:=j-1
                                                   else i:=i-1;
      assign(fo,'cmlsc.out');
      rewrite(fo);
      writeln(fo,bst);
      for i:=bst downto 1 do write(fo,sir[i],' ');
      close(fo);
end.
