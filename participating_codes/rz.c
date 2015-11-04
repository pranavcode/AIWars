#include "stdio.h"

int rz_index(char c);
int rz(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
             int i,row_pos,col_pos;
             if(player==1)
             {
                for(i=0;i<k;i++)
             {
                  if(array[i][2]=='H')
                    return i;
              }
              
              for(i=k-1;i>=0;i--)
             {
                  
              
                    if((col_pos=rz_index(array[i][2]))== -1)
                    {
                            return k-1;
                    }
                    row_pos=(int)array[i][3];
                    if(array[i][2]-array[i][0]==1)
                    {
                         if(boardCheckers[row_pos+1][col_pos+1]==1 && boardCheckers[row_pos-1][col_pos+1]==1)
                             return i;
                         else if((boardCheckers[row_pos+1][col_pos-1]==2 || boardCheckers[row_pos+1][col_pos+1]==2) && 
                                  (boardCheckers[row_pos-1][col_pos+1]!=1 || boardCheckers[row_pos-1][col_pos+1] != 3));
                         else if(boardCheckers[row_pos-1][col_pos+1]==1 && boardCheckers[row_pos+1][col_pos+1] != 2)
                             return i;
                    }
                    else
                    {
                        if(boardCheckers[row_pos+1][col_pos-1]==2);
                        else if(boardCheckers[row_pos-1][col_pos-1]==1||boardCheckers[row_pos+1][col_pos+1]==3)
                            return i;
                    }
                   
              }   
                   return k-1;              
          }
              
              else
              {
                   for(i=0;i<k;i++)
                  {
                    if(array[i][2]=='A')
                       return i;
                  }
                  for(i=0;i<k;i++)
                  {
                  
              
                     if((col_pos=rz_index(array[i][2]))== -1)
                    {
                    
                            return k-1;
                    }
                    row_pos=(int)array[i][3];
                    if(array[i][2]-array[i][0]== -1)
                    {
                         if(boardCheckers[row_pos-1][col_pos-1]==2 && boardCheckers[row_pos+1][col_pos-1]==1)
                             return i;
                         else if((boardCheckers[row_pos-1][col_pos+1]==1 || boardCheckers[row_pos-1][col_pos-1]==1) && 
                                  (boardCheckers[row_pos+1][col_pos-1]!=2 || boardCheckers[row_pos+1][col_pos-1] != 4));
                         else if(boardCheckers[row_pos+1][col_pos-1]==2 && boardCheckers[row_pos-1][col_pos-1] != 1)
                             return i;
                    }
                    else
                    {
                        if(boardCheckers[row_pos-1][col_pos+1]==1);
                        else if(boardCheckers[row_pos+1][col_pos+1]==2||boardCheckers[row_pos-1][col_pos-1]==4)
                            return i;
                    }
                                  
                   
                }
                return 0;
              }
}
int rz_index(char c)
{
    switch(c)
    {
      case 'A':
         return 0;
      case 'B':
         return 1;
      case 'C':
         return 2;
      case 'D':
         return 3;
      case 'E':
         return 4;
      case 'F':
          return 5;
      case 'G':
          return 6;
      default:
          return -1;
    }
}
