#include "stdio.h"

int pc(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
	int pc_inc=1,pc_i,pc_val,pc_m=0,pc_max=-999,pc_curval,pc_nextval,pc_curvar,pc_nextvar;
	int pc_va=1,pc_va1=2,pc_va2=4,pc_va3=6;
	if (player==2)
	{
		pc_inc=-1;
		pc_va=2;
		pc_va1=1;
		pc_va2=3;
		pc_va3=1;
      }
	for(pc_i=0;pc_i<k;pc_i++)
	{
		pc_curvar=array[pc_i][0]-65;
		pc_curval=array[pc_i][1]-49;
		pc_nextvar=array[pc_i][2]-65;
		pc_nextval=array[pc_i][3]-49;
		pc_val=0;
		if(boardCheckers[pc_curval-pc_inc][(pc_curvar-1)]==pc_va)
			pc_val--;
		else pc_val++;
		if(boardCheckers[pc_curval-pc_inc][pc_curvar+1]==pc_va)
			pc_val--;
		else pc_val++;
		if(boardCheckers[pc_nextval+pc_inc][pc_nextvar-1]==pc_va)
			pc_val++;
		if(boardCheckers[pc_nextval+pc_inc][pc_nextvar+1]==pc_va)
			pc_val++;
		if((pc_curvar-pc_nextvar)>0)
		{
			if(boardCheckers[pc_curval+pc_inc][pc_curvar+1]==pc_va)
				pc_val--;
			else pc_val++;
			if(boardCheckers[pc_nextval+pc_inc][pc_nextvar-1]==pc_va1)
				pc_val--;
			if(boardCheckers[pc_nextval-pc_inc][pc_nextvar-1]==pc_va2)
				pc_val--;
		}
		else
		{
			if(boardCheckers[pc_curval+pc_inc][pc_curvar-1]==pc_va)
				pc_val--;
			else pc_val++;
			if(boardCheckers[pc_nextval+pc_inc][pc_nextvar+1]==pc_va1)
				pc_val--;
			if(boardCheckers[pc_nextval-pc_inc][pc_nextvar+1]==pc_va2)
				pc_val--;
		}
		if(pc_curval==pc_va3 && boardCheckers[pc_curval][pc_curvar]==pc_va)
		{
			pc_m=pc_i;
			break;
		}
		if(pc_max<pc_val)
		{
			pc_max=pc_val;
			pc_m=pc_i;
		}
	}
               return pc_m;
}
