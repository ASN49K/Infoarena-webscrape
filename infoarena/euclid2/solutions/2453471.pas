var a,b,c,d,e,i,n:longint;
fin,fout:textfile;
begin
  assign(fin, 'euclid2.in');
  reset(fin);
  assign(fout, 'euclid2.out');
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do begin
    readln(fin,a,b);
    d:=0;
    for e := a downto 1 do begin
      if (a mod e = 0) and (b mod e = 0) then
        d := e;
        break;              
    end;    
    writeln(fout, d);
  end;
  
  
  
  close(fin);
  close(fout);
  
end.