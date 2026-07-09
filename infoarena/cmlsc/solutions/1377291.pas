uses math,crt;
var a:array[0..1025,0..1025] of byte;
    i,j,k,n,m:integer;
    f,g:text;

procedure kiir;
        var i,j:integer;
        begin
        clrscr;
          for i:=0 to n do
             begin
             for j:=0 to m do write(a[i,j]:3);
             writeln;
             end;
        delay(1000);
        end;
begin
 assign(f,'cmlsc.in'); reset(f);
 assign(g,'cmlsc.out'); rewrite(g);
 readln(f,m,n);

 for i:=1 to m do read(f,a[0,i]);
 for i:=1 to n do read(f,a[i,0]);

 k:=1;
 if a[1,0]=a[0,1] then a[1,1]:=1
                  else a[1,1]:=0;
 for i:=2 to n do if a[0,1]=a[i,0] then a[i,1]:=1
                                   else a[i,1]:=a[i-1,1];
 for i:=2 to m do if a[1,0]=a[0,i] then a[1,i]:=1
                                   else a[1,i]:=a[1,i-1];

 for i:=2 to n do
     for j:=2 to m do
         if a[i,0]=a[0,j] then a[i,j]:=a[i-1,j-1]+1
                          else a[i,j]:=max(a[i-1,j],a[i,j-1]);

  writeln(g,a[n,m]);
  for i:=1 to n do
      for j:=1 to m do
          if a[i,j]=k then begin
                            inc(k);
                            write(g,a[0,j],' ');
                           end;
  close(g);

end.
