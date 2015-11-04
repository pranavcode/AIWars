#include "stdio.h"
int akl_move=1;
int akl(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
    puck copy[8][8];
    int i,j,l,p,y,z;
    int a,b;
    char c,d;
      for(i=0;i<8;i++)      //copy of game board
      for(j=0;j<8;j++)
      copy[i][j]=boardCheckers[i][j];
   
       if(k==1)                      // single valid move
        {
                return 0;
        }
     //decide move to be taken   
    for(l=0;l<k;l++)
    {
    if(player==1)
    {
          if(akl_move==1)                   //first move
               {
                 for(i=0;i<k;i++)
                       if(array[i][0]=='A' && array[i][1]=='3' && array[i][2]=='B' && array[i][3]=='4')
                       {
                               akl_move=0;
                               return i;           
                       }
               }
          for(p=0;p<k;p++)            //corner moves
          {
          if(array[p][2]=='A' || array[p][2]=='H' || array[p][3]=='1' || array[p][3]=='8')
               return p;
          }             //remaining other moves including king
             c = array[l][0];
             d = array[l][1];
             y=c-65;
             z=d-49;
             copy[y][z]=0;                //set move to be taken to 0
             c = array[l][2];
             d = array[l][3];
             if((c-1)>='A' && (d+1)<'8' && (c+1)<'I' && (d-1)>='0')      //set boundary
             {
             a=c-65;
             b=d-49;
             if((copy[b+1][a-1] != 2 || copy[b+1][a-1] !=4) && (copy[b+1][a+1] != 2 || copy[b+1][a+1] != 4))
                return l;
             if((copy[b+1][a-1] == 2 || copy[b+1][a-1] ==4) && (copy[b-1][a+1] == 2  || copy[b-1][a+1] == 1 || copy[b-1][a+1] == 3 || copy[b-1][a+1] ==4))
                 return l;
             if((copy[b+1][a+1] == 2 || copy[b+1][a+1] == 4) && (copy[b-1][a-1] == 2 || copy[b-1][a-1] == 1 || copy[b-1][a-1] == 3 || copy[b-1][a-1] == 4))
                 return l;
            }            
      }
    if(player==2)
    {
         if(akl_move==1)    //first move
               {
                 for(i=0;i<k;i++)
                       if(array[i][0]=='H' && array[i][1]=='6' && array[i][2]=='G' && array[i][3]=='5')
                       {
                               akl_move=0;
                               return i;           
                       }
               } 
         for(p=0;p<k;p++)                          //corner move
          if(array[p][2]=='A' || array[p][2]=='H' || array[p][3]=='1' || array[p][3]=='8')
               return p;                  //remaining other move
             c = array[l][0];
             d = array[l][1];
             y=c-65;
             z=d-49;
             copy[y][z]=0;
             c = array[l][2];
             d = array[l][3];
             if((c-1)>='A' && (d+1)<'8' && (c+1)<'I' && (d-1)>='0')      //check boundary
             {
              a=c-65;
              b=d-49;
             if((copy[b-1][a-1] != 1 || copy[b-1][a-1] != 3) && (copy[b-1][a+1] != 1 || copy[b-1][a+1] != 3))
                return l;
             if((copy[b-1][a-1] == 1 || copy[b-1][a-1] == 3) && (copy[b+1][a+1] == 1  || copy[b+1][a+1] == 2 || copy[b+1][a+1] == 3  || copy[b+1][a+1] == 4 ))
                 return l;
             if((copy[b-1][a+1] == 1 || copy[b-1][a+1] == 3) && (copy[b+1][a-1] == 1 || copy[b+1][a-1] == 2 || copy[b+1][a-1] == 3 || copy[b+1][a-1] == 4))
                 return l;
         }
         } 
    }
    return 0;
}
