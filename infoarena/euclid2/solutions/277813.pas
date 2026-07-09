type sir=array[1..100] of integer;
const fin='euclid2.in';
      fout='euclid2.out';

var f,g:text;
    a,b:sir;
    r,n,i:integer;

begin
  assign(f,fin);reset(f);
  assign(g,fout);rewrite(g);
  read(f,n);
  for i:=1 to n do read(f,a[i],b[i]);
  for i:=1 to n do begin
    while b[i]<>0 do begin
     r:=a[i] mod b[i];
     a[i]:=b[i];
     b[i]:=r;
    end;
    writeln(g,a[i])
  end;
  close(g);
end.