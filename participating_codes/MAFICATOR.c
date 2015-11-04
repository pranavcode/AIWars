#include "stdio.h"

/*  MAFICATOR (alias MrMaficator, version 9.9)
 *  AUTHOR:  PRANAV KULKARNI
 *  COLLEGE: WCE, SANGLI
 */
 
int MAFICATOR(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
 int _i,_j=0,_k=0,x_old,y_old,x_new,y_new,pos[32]={0},k_pos[32]={0}; static char rep[4] = "    "; 
 if(k==1) return 0;  for(_i=0;_i<k;_i++) {  x_old=array[_i][1]-49; y_old=array[_i][0]-65; x_new =
 array[_i][3]-49; y_new=array[_i][2]-65;if(player==1){if( boardCheckers[x_new+1][y_new+1] != 2 && 
 boardCheckers[x_new+1][y_new+1]!=4&&boardCheckers[x_new+1][y_new-1] !=2 && boardCheckers[x_new+1]
 [y_new-1] != 4 && boardCheckers[x_new-1][y_new+1] != 4 &&	boardCheckers[x_new-1][y_new-1] != 4 )
 {if(boardCheckers[x_old][y_old]==3)k_pos[_k++]=_i;else pos[_j++]=_i;} } else { if ( boardCheckers
 [x_new-1][y_new-1]!=1&&boardCheckers[x_new-1][y_new-1]!=3 && boardCheckers[x_new-1][y_new+1] != 1
 && boardCheckers[x_new-1][y_new+1] != 3 &&	 boardCheckers[x_new+1][y_new-1] != 3 && boardCheckers
 [x_new+1][y_new+1] != 3){ if(boardCheckers[x_old][y_old]==4) k_pos[_k++]=_i; else pos[_j++]=_i;}}
 }if(_k!=0){if(k>2) _i=k_pos[_k-1];else	_i=k_pos[0];if(rep[0]==array[_i][2]&&rep[1]==array[_i][3])
 _i=pos[_j/2];if(rep[2]==array[_i][2] && rep[3]==array[_i][3])if(_j>2) _i=pos[_j-1];else _i=pos[0];
 }else{if(_j==3 && rep[0]==' ') _i=0;else _i=pos[_j/2];}if(rep[0]!=' '&&rep[1]!=' '){rep[2]=rep[0];
 rep[3]=rep[1];}rep[0]=array[_i][0];rep[1]=array[_i][1];return _i;
}
