 var  
    f:text;  
    k,n,m,i,j:byte;  
    mat:array[0..1024,0..1024] of integer;  
    a,b,c:array[1..1024] of byte;  
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
          mat[i,0]:=0;  
      for i:=1 to n do  
          mat[0,i]:=0;  
      for i:=1 to m do  
          for j:=1 to n do  
              if a[i]=b[j] then mat[i,j]:=mat[i-1,j-1]+1  
                           else  
                               if mat[i-1,j]>lcs[i,j-1] then mat[i,j]:=mat[i-1,j]  
                                                        else mat[i,j]:=mat[i,j-1];  
      assign(f,'cmlsc.out');  
      rewrite(f);  
      writeln(f,mat[m,n]);  
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
                               if mat[i,j]=mat[i-1,j] then i:=i-1  
                                                      else j:=j-1;  
      end;  
      for i:=k downto 1 do  
          write(f,c[i],' ');  
      close(f)  
 End.