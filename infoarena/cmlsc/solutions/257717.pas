   var  i,j,m1,n:integer;  
        a,b:array[1..1050] of integer;  
        m:array[0..1050,0..1050] of integer;  
        f,g:text;  
  procedure drum(i,j:integer);  
   begin  
      if (i<>0) and (j<>0) then  
        if a[i]=b[j] then begin  
           drum(i-1,j-1);  
           write(g,a[i],' ');  
        end else  
            if m[i-1,j]>m[i,j-1] then drum(i-1,j)  
             else drum(i,j-1);  
   end;  
   begin  
   assign(f,'cmlsc.in');reset(f);  
  assign(g,'cmlsc.out');rewrite(g);  
   read(f,n,m1);  
   for i:=1 to n do  
       read(f,a[i]);  
   for j:=1 to m1 do  
       read(f,b[j]);  
   for i:=1 to n do  
       for j:=1 to m1 do  
           if a[i]=b[j] then  m[i,j]:=m[i-1,j-1]+1  
              else if m[i-1,j]>m[i,j-1] then  m[i,j]:=m[i-1,j]  
                      else m[i,j]:=m[i,j-1];  
   i:=n;j:=n;  
   writeln(g,m[n,m1]);  
   drum(n,m1);  
   close(g);  
   end.  