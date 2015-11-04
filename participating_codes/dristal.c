#include "stdio.h"
/*
AI for Checkers
-----------------------------------
Team Name: Dristal
By: Daksh Mehta & Abhishek Patel
-----------------------------------
*/

int dristal(puck boardCheckers[8][8],int player,char array[32][4],int max)
{
    	int index=0;
		int d[32][4];
		int score[32];
		int pt[32];
		int i,j,k,l, total;
  // Assign the score & pt to 0
  for(i=0;i<max;i++){
          score[i]=0;
          pt[i]=0;
  }
  
   
  /* Converting array into dummy for operations */
  for(i = 0;i<max;i++){
        for(j =0; j<4; j++){
              if((int) array[i][j] > 64)
                     d[i][j] = (int) (array[i][j])-65;
              else
                  d[i][j] = ((int) (array[i][j]))-49;
        }
  }
  // Player 1
  if(player == 1){
  // Check for king spawn
  for(i=0;i<max;i++)
  {
   if(d[i][3]==7 && boardCheckers[d[i][1]][d[i][0]] != 3)
                 score[i]+=150;    
         
  }
  // Check Border
  for(i=0;i<max;i++){
                         if(d[i][2] <=3){
                                    score[i] = score[i] + (7 - d[i][2]);
                         }
                         else {
                              score[i]=score[i]+(d[i][2]);    
                         }             
  }
  // Check Inner
  for(i=0;i<max;i++){
                     if(d[i][3] < 3){
                                score[i]+=25*(4 - d[i][3]);          
                     }                        
  }
  /* Check pass through! */
   for(i=0;i<max;i++)
  {
     if(boardCheckers[d[i][3]+1][d[i][2] -1] == 2){  
                                                  
                                         if(boardCheckers[d[i][3]-1][d[i][2]+1] != 0 && boardCheckers[d[i][3]-1][d[i][2]+1] != boardCheckers[d[i][1]][d[i][0]]){
                                                                                score[i]+=10;
                                                                                pt[i]=1;                                       
                                         }               
     }
     if(boardCheckers[d[i][3]+1][d[i][2] +1] == 2){  
                                        
                                         if(boardCheckers[d[i][3]-1][d[i][2]-1] != 0 && boardCheckers[d[i][3]-1][d[i][2]-1] != boardCheckers[d[i][1]][d[i][0]]) {
                                                                                 score[i]+=10;
                                                                                 pt[i]=1;
                                         }
                                                                                   
     }     
  }
  /* Check defending pieces */
   for(i=0;i<max;i++)
  {                  if(pt[i]==0)      
     if(boardCheckers[d[i][3]+1][d[i][2] -1] == 2) 
                        
                score[i] = 0;    
                
          if(pt[i]==0)  
     if(boardCheckers[d[i][3]+1][d[i][2] +1] == 2)
                score[i] = 0; 
  }
  
  /* Lets find best move! */
  total = score[0];
  for(i=0;i<max;i++){
                     if(score[i] > total){
                                 total = score[i];
                                 index = i; }                            
  }
  return index;
  } // End player 1
  
  //Player 2
  if(player == 2){
  // Check for king spawn
      for(i=0;i<max;i++)
      {
       if(d[i][3]==0  && boardCheckers[d[i][1]][d[i][0]] != 4)
                     score[i]+=150;    
             
      }  
  // Check Border
  for(i=0;i<max;i++){
                         if(d[i][2] <= 3){
                                    score[i] = score[i] + (7 - d[i][2]);
                         }
                         else {
                              score[i]=score[i]+(d[i][2]);    
                         }             
  }
  // Check Inner
  for(i=0;i<max;i++){\
                     if(d[i][3] > 4){
                                score[i]= score[i]+ 10;        
                                               }   
  }
  /* Check pass through! */
   for(i=0;i<max;i++)
  {
     if(boardCheckers[d[i][3]-1][d[i][2]-1] == 1){         
                                         boardCheckers[d[i][1]][d[i][0]] = 0;  
                                         if(boardCheckers[d[i][3]+1][d[i][2]+1] != 0){
                                                                                score[i]+=10;
                                                                                pt[i]=1;                                       
                                         }             
                                         
                                         boardCheckers[d[i][1]][d[i][0]] = 2;  
     }
     if(boardCheckers[d[i][3]-1][d[i][2] +1] == 1){  
                                        
                                         boardCheckers[d[i][1]][d[i][0]] = 0;  
                                         if(boardCheckers[d[i][3]+1][d[i][2]-1] != 0) {
                                                                                 score[i]+=10;
                                                                                 pt[i]=1;
                                         }
                                         boardCheckers[d[i][1]][d[i][0]] = 2;  
                                                                                   
     }
  }
  /* Check defending pieces */
   for(i=0;i<max;i++)
  {                  if(pt[i]==0) {  
          if(d[i][0] != 0)       
     if(boardCheckers[d[i][3]-1][d[i][2]-1] == 1) 
                        
                score[i] = 0;    
                }
          if(pt[i]==0){  
          if(d[i][0] != 0)                         
     if(boardCheckers[d[i][3]-1][d[i][2] +1] == 1)
                score[i] = 0; 
                      }     
  }
  
  /* Lets find best move! */
  total = score[0];
  for(i=0;i<max;i++){
                     if(score[i] > total){
                                  total = score[i];
                                 index = i; }
                                 
  
  }
  return index;
} // End P2
}
