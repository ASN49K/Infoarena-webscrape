var a,b,c,d,e,i,n,f,temp,raspuns:longint;
var ofc:boolean;
fin,fout:textfile;
begin
  ofc:=true;
  assign(fin, 'euclid2.in');
  reset(fin);
  assign(fout, 'euclid2.out');
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do begin
    ofc:=true;
    readln(fin,a,b);
    d := a;
    e := b;
    if a>b then begin
      d := a;
      e := b;
    end
    else begin
      d := b;
      e:=a;
    end;
    {if d mod e = 0 then begin
          raspuns := e;
          ofc:=false;
          end;
    else begin
      temp:=e;
      e := d mod e;
      d := e;
    end; }
    
    while ofc=true do begin
      if d mod e =0 then begin
      raspuns := e;    
      break  
      end
      else begin
      temp:=e;
      e := d mod e;
      d := temp;      
      end;
      
      {while ofc=true do begin         
      temp:=e;
      write('temp=',e);
      e := d mod e;
      write('e=',d mod e);
      d := temp;
      write('d=',temp);
      if d mod e =0 then begin
      raspuns := e;
      break  
      end;  }
    end;
    writeln(fout,raspuns)
  end;     
  close(fin);
  close(fout);
  
end.