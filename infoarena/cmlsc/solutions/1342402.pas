var n,m,i,j,k,p,t,r,f:longint;
    a,b,c,d:array[1..1025] of longint;
    
procedure subsir(s1:string);
var i,p:longint;
begin
  if length(s1)=k then begin
    t:=1;
    r:=0;
    for i:=1 to k do begin
      if s1[i]='0' then
        for p:=t to k do begin
          if a[i]=b[p] then begin
            inc(r);
            t:=p+1;
            c[r]:=a[i];
            break;
          end;
        end;
    end;
    if r=j then begin
      if r>f then begin
        f:=r;
        for i:=1 to r do 
          d[i]:=c[i];
      end;
    end;
  end else begin
    inc(j);
    subsir(s1+'0');
    dec(j);
    subsir(s1+'1');
  end;
end;
    
begin
  assign(input,'cmlsc.in');
  assign(output,'cmlsc.out');
  reset(input);
  rewrite(output);
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  if n>m then k:=m else k:=n;
  subsir('');
  writeln(f);
  for i:=1 to f do write(d[i],' ');
end.