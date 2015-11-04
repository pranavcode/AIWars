
int jayesh_vb(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
    int i,j,x1,x2,y1,y2,p2,pk2,pk1;
    int priority[32],xr[32][4];
    int flag1,flag2;
    
    if(player==1)
    {
         flag1=1;
         flag2=2;
         p2=2;
         pk2=4;
         pk1=3;
         
    }
    else
    {
        flag1=-1;
        flag2=-2;
        p2=1;
        pk2=3;
        pk1=4;
    }
    for(i=0;i<k;i++)
    {
      xr[i][0]=array[i][0]-'A';
      xr[i][1]=array[i][1]-'0'-1;
      xr[i][2]=array[i][2]-'A';
      xr[i][3]=array[i][3]-'0'-1;
    }
    for(i=0;i<k;i++)
    {
               x1=xr[i][0];
               x2=xr[i][2];
               y1=xr[i][1];
               y2=xr[i][3];
               if( y1-y2 == 2 || y1-y2 == -2)
               {
                      if( boardCheckers[x2+1][y2+flag1] == p2 || boardCheckers[x2-1][y2+flag1] == p2 || boardCheckers[x2+1][y2+flag1] == pk2 || boardCheckers[x2-1][y2+flag1] == pk2)
                      {
                          priority[i]=3;
                          if( boardCheckers[x1][y1-flag2] == player) 
                          {
                              array[i][0]=x1+'A';
                              array[i][1]=y1+'0'+1;
                              array[i][2]=x2+'A';
                              array[i][3]=y2+'A'+1;
                              priority[i]=2;
                          }    
                          else if( boardCheckers[x1][y1-flag2] == pk1) 
                          {
                              array[i][0]=x1+'A';
                              array[i][1]=y1+'0'+1;
                              array[i][2]=x2+'A';
                              array[i][3]=y2+'A'+1;
                              priority[i]=2;
                          }
                          else if( boardCheckers[x1-flag2][y1-flag2] == player) 
                          {
                              array[i][0]=x1+'A';
                              array[i][1]=y1+'0'+1;
                              array[i][2]=x2+'A';
                              array[i][3]=y2+'A'+1;
                              priority[i]=2;
                          }
                          else if( boardCheckers[x1-flag2][y1-flag2] == player) 
                          {
                              array[i][0]=x1+'A';
                              array[i][1]=y1+'0'+1;
                              array[i][2]=x2+'A';
                              array[i][3]=y2+'A'+1;
                              priority[i]=2;
                          }
                    
                      }
                      else
                      {
                              priority[i]=1;
                      }
               }
               else
               {
                   if( boardCheckers[x2-1][y2+flag1] == p2 || boardCheckers[x2-1][y2+flag1] == pk2 || boardCheckers[x2+1][y2+flag1] == p2 || boardCheckers[x2+1][y2+flag1] == pk2 )
                       priority[i]=5;
                   else
                       priority[i]=4;    
               }          
    }
    for(j=1;j<=5;j++)
        for(i=k-1;i>=0;i--)
             if(priority[i]==j)
                 return i;            
}
