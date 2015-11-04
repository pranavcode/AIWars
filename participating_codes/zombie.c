#include "stdio.h"


int zombie(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
	int i,j,value[20],x1[20],x2[20],y1[20],y2[20],min,min_val;

	for(i=0;i<k;i++)
	{
		x1[i] = array[i][0] - 65;
		y1[i] = array[i][1] - 49;
		x2[i] = array[i][2] - 65;
		y2[i] = array[i][3] - 49;
		if(player == 1)
			value[i] = zombie_val1(boardCheckers,x1[i],y1[i],x2[i],y2[i]);
		else
			value[i] = zombie_val2(boardCheckers,x1[i],y1[i],x2[i],y2[i]);
	}
	
	min_val = value[0];
	min = 0;
	for(i=1;i<k;i++)
	{
		if(value[i] < min_val)
		{
			min_val = value[i];
			min = i;
		}
	}
		
        return min;
}



int zombie_val1(puck boardCheckers[8][8],int a,int b,int c,int d)
{
	int x,y,dx,value=0,count=0;
	dx = c - a;
	if(dx < 0)
		dx = dx * -1;
	

	if((boardCheckers[b][a] != 3) && (d == 7))
	{
		value = 1;
		return value;
	}

	x = c + 1;
	y = d + 1;
	if(zombie_check(y,x) && (boardCheckers[y][x] == 2 || boardCheckers[y][x] == 4))
	{		
		count++;
	}

	x = c - 1;
	y = d + 1;
	if(zombie_check(y,x) && (boardCheckers[y][x] == 2 || boardCheckers[y][x] == 4))
	{
		count++;
	}

	x = c - 1;
	y = d - 1;
	if(zombie_check(y,x) && boardCheckers[y][x] == 4)
	{
		count++;
	}

	x = c + 1;
	y = d - 1;
	if(zombie_check(y,x) && boardCheckers[y][x] == 4)
	{
		count++;
	}


	if(dx > 1)
	{
		if(count==0)
			value = 0;
		else
			value = 3;
	}
	else
	{
		if(count==0)
			value = 2;
		else
			value = 4;
	}

	return value;	
	
}


int zombie_val2(puck boardCheckers[8][8],int a,int b,int c,int d)
{
	int x,y,dx,value=0,count=0;
	dx = c - a;
	if(dx < 0)
		dx = dx * -1;
	

	if((boardCheckers[b][a] != 4) && (d == 0))
	{
		value = 1;
		return value;
	}

	x = c + 1;
	y = d + 1;
	if(zombie_check(y,x) && boardCheckers[y][x] == 3)
	{
		count++;
	}

	x = c - 1;
	y = d + 1;
	if(zombie_check(y,x) && boardCheckers[y][x] == 3)
	{
		count++;
	}

	x = c - 1;
	y = d - 1;
	if(zombie_check(y,x) && (boardCheckers[y][x] == 1 || boardCheckers[y][x] == 3))
	{
		count++;
	}

	x = c + 1;
	y = d - 1;
	if(zombie_check(y,x) && (boardCheckers[y][x] == 1 || boardCheckers[y][x] == 3))
	{
		count++;
	}

	
	if(dx > 1)
	{
		if(count==0)
			value = 0;
		else
			value = 3;
	}
	else
	{
		if(count==0)
			value = 2;
		else
			value = 4;
	}

	return value;	
	
}




int zombie_check(int x,int y)
{
	if((x>=0 && x<=7) && (y>=0 && y<=7))
		return 1;
	return 0;
}
