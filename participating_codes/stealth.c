#include "stdio.h"


int stealth_priority[32];
puck stealth_testboard[8][8];
char stealth_moves_avl[32][5];
int stealth_khiladi=0;

void stealth_initialize(puck boardCheckers[8][8])
{
	int i=0,j=0;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			stealth_testboard[i][j]=boardCheckers[i][j];
}

void stealth_initialize_pre(puck boardCheckers[8][8],char array[32][4],int k)
{
	int i=0,j=0;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			stealth_testboard[i][j]=boardCheckers[i][j];
	for(i=0;i<k;i++)
	{
		for(j=0;j<4;j++)
			stealth_moves_avl[i][j]=array[i][j];
		stealth_moves_avl[i][j]='\0';
	}
		
}

int stealth_is_multiple(puck boardCheckers[8][8], char move[5])
{
	int value=0,xi=0,yi=0,xf=0,yf=0;

	stealth_initialize(boardCheckers);

	xi=8+'0'-move[1];
	yi=move[0]-'A';


	xf=8+'0'-move[3];
	yf=move[2]-'A';


	value=stealth_testboard[xi][yi];
	stealth_testboard[xi][yi]=0;

	stealth_testboard[(xi+xf)/2][(yi+yf)/2]=0;

	if((value%2)!=0)								//for player 1
	{
		if(value==1)							//normal checker
		{
			stealth_testboard[xf][yf]=1;
			if(xf>1 && yf<6)
				if(!((stealth_testboard[(xf+xf-2)/2][(yf+yf+2)/2])%2))
					if(stealth_testboard[xf-2][yf+2]==0)
						return 1;
			if(xf>1 && yf>1)
				if(!((stealth_testboard[(xf+xf-2)/2][(yf+yf-2)/2])%2))
					if(stealth_testboard[xf-2][yf-2]==0)
						return 1;
			return 0;		
		}
		else								//king checker
		{
			stealth_testboard[xf][yf]=3;

			if(xf>1 && yf<6)
				if(!((stealth_testboard[(xf+xf-2)/2][(yf+yf+2)/2])%2))
					if(stealth_testboard[xf-2][yf+2]==0)
						return 1;
			if(xf>1 && yf>1)
				if(!((stealth_testboard[(xf+xf-2)/2][(yf+yf-2)/2])%2))
					if(stealth_testboard[xf-2][yf-2]==0)
						return 1;

			if(xf<5 && yf<6)
				if(!((stealth_testboard[(xf+xf+2)/2][(yf+yf+2)/2])%2))
					if(stealth_testboard[xf+2][yf+2]==0)
						return 1;
			if(xf<5 && yf>1)
				if(!((stealth_testboard[(xf+xf+2)/2][(yf+yf-2)/2])%2))
					if(stealth_testboard[xf+2][yf-2]==0)
						return 1;
			return 0;
		}
	}
	else									//for player 2
	{
		if(value==2)							//normal checker
		{
			stealth_testboard[xf][yf]=2;

			if(xf<5 && yf<6)
				if((stealth_testboard[(xf+xf+2)/2][(yf+yf+2)/2])%2)
					if(stealth_testboard[xf+2][yf+2]==0)
						return 1;
			if(xf<5 && yf>1)
				if((stealth_testboard[(xf+xf+2)/2][(yf+yf-2)/2])%2)
					if(stealth_testboard[xf+2][yf-2]==0)
						return 1;
			return 0;
		}
		else								//king checker
		{
			stealth_testboard[xf][yf]=4;

			if(xf>1 && yf<6)
				if((stealth_testboard[(xf+xf-2)/2][(yf+yf+2)/2])%2)
					if(stealth_testboard[xf-2][yf+2]==0)
						return 1;
			if(xf>1 && yf>1)
				if((stealth_testboard[(xf+xf-2)/2][(yf+yf-2)/2])%2)
					if(stealth_testboard[xf-2][yf-2]==0)
						return 1;

			if(xf<5 && yf<6)
				if((stealth_testboard[(xf+xf+2)/2][(yf+yf+2)/2])%2)
					if(stealth_testboard[xf+2][yf+2]==0)
						return 1;
			if(xf<5 && yf>1)
				if((stealth_testboard[(xf+xf+2)/2][(yf+yf-2)/2])%2)
					if(stealth_testboard[xf+2][yf-2]==0)
						return 1;
			return 0;
		}
	}
	
}

int stealth_s_prevent(puck boardCheckers[8][8],char array[32][4],int k)
{
	int x=0,y=0,i=0;
	char position[3];
	stealth_initialize_pre(boardCheckers,array,k);
	for(x=0;x<8;x++)
	{
		for(y=0;y<8;y++)
		{
			if(stealth_testboard[x][y]==2 || stealth_testboard[x][y]==4)
			{
				if(x>0 && x<7 && y>0 && y<7)
				{
					if(stealth_testboard[x+1][y+1]==1 || stealth_testboard[x+1][y+1]==3)
					{
						if(stealth_testboard[x-1][y-1]==0)
						{
							position[0]=y-1+'A';
							position[1]=8-x-1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;	
						}
					}
					if(stealth_testboard[x+1][y-1]==1 || stealth_testboard[x+1][y-1]==3)
					{
						if(stealth_testboard[x-1][y+1]==0)
						{
							position[0]=y+1+'A';
							position[1]=8-x-1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;
						}
					}
					if(stealth_testboard[x-1][y-1]==3)
					{
						if(stealth_testboard[x+1][y+1]==0)
						{
							position[0]=y+1+'A';
							position[1]=8-x+1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;
						}
					}
					if(stealth_testboard[x-1][y+1]==3)
					{
						if(stealth_testboard[x+1][y-1]==0)
						{
							position[0]=y-1+'A';
							position[1]=8-x+1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;
						}
					}
				}
			}
		}
	}
	return 0;
}

int stealth_prevent(puck boardCheckers[8][8],char array[32][4],int k)
{
	int x=0,y=0,i=0;
	char position[3];
	stealth_initialize_pre(boardCheckers,array,k);
	for(x=7;x>=0;x--)
	{
		for(y=0;y<8;y++)
		{
			if(stealth_testboard[x][y]==1 || stealth_testboard[x][y]==3)
			{
				if(x>0 && x<7 && y>0 && y<7)
				{
					if(stealth_testboard[x-1][y-1]==2 || stealth_testboard[x-1][y-1]==4)
					{
						if(stealth_testboard[x+1][y+1]==0)
						{
							position[0]=y+1+'A';
							position[1]=8-x+1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;	
						}
					}
					if(stealth_testboard[x-1][y+1]==2 || stealth_testboard[x-1][y+1]==4)
					{
						if(stealth_testboard[x+1][y-1]==0)
						{
							position[0]=y-1+'A';
							position[1]=8-x+1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;
						}
					}
					if(stealth_testboard[x+1][y-1]==4)
					{
						if(stealth_testboard[x-1][y+1]==0)
						{
							position[0]=y+1+'A';
							position[1]=8-x-1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;
						}
					}
					if(stealth_testboard[x+1][y+1]==4)
					{
						if(stealth_testboard[x-1][y-1]==0)
						{
							position[0]=y-1+'A';
							position[1]=8-x-1;
							position[2]='\0';
							for(i=0;i<k;i++)
								if(strstr(stealth_moves_avl[i],position))
									return i;
						}
					}
				}
			}
		}
	}
	return 0;
}


void stealth_bettermove(puck boardCheckers[8][8],char move[5], int loop,int pri)
{
	int xi=0,yi=0,xf=0,yf=0,retval=0,i=0,j=0,value=0;
	char demo_move[5];
	puck test[8][8];

	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			test[i][j]=boardCheckers[i][j];
	
	xi=8+'0'-move[1];
	yi=move[0]-'A';

	xf=8+'0'-move[3];
	yi=move[2]-'A';
	
	value=test[xi][yi];
	test[xi][yi]=0;
	test[xf][yf]=value;

	if(xf-xi==2 || xi-xf==2)
		test[(xi+xf)/2][(yi+yf)/2]=0;

	if((value%2)!=0)
	{
		if(pri==1)
			stealth_priority[loop]=5;
		else if(pri==2)
			stealth_priority[loop]=10;
		else if(pri==3)
			stealth_priority[loop]=15;
		else if(pri==4)
			stealth_priority[loop]=21;
		else if(pri==5)
			stealth_priority[loop]=27;
		if(test[xf-1][yf-1]==2 || test[xf-1][yf-1]==4)
		{
			if(test[xf+1][yf+1]==0)
			{
				if(pri==1)
				{
					if((yf+1)==7)
						stealth_priority[loop]=6;
					else if((xf+1)==7)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf+1)==7)
						stealth_priority[loop]=11;
					else if((xf+1)==7)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf+1)==7)
						stealth_priority[loop]=16;
					else if((xf+1)==7)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf+1)==7)
						stealth_priority[loop]=22;
					else if((xf+1)==7)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf+1)==7)
						stealth_priority[loop]=28;
					else if((xf+1)==7)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf-1+'A';
				demo_move[1]=8-xf-1;
				demo_move[2]=yf+1+'A';
				demo_move[3]=8-xf+1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
			}
		}
		if(test[xf-1][yf+1]==2 || test[xf-1][yf+1]==4)
		{
			if(test[xf+1][yf-1]==0)
			{
				//stealth_priority[loop]=;
				if(pri==1)
				{
					if((yf-1)==0)
						stealth_priority[loop]=6;
					else if((xf+1)==7)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf-1)==0)
						stealth_priority[loop]=11;
					else if((xf+1)==7)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf-1)==0)
						stealth_priority[loop]=16;
					else if((xf+1)==7)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf-1)==0)
						stealth_priority[loop]=22;
					else if((xf+1)==7)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf-1)==0)
						stealth_priority[loop]=28;
					else if((xf+1)==7)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf+1+'A';
				demo_move[1]=8-xf-1;
				demo_move[2]=yf-1+'A';
				demo_move[3]=8-xf+1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
			}
		}
		if(test[xf+1][yf-1]==4)
		{
			if(test[xf-1][yf+1]==0)
			{
				//stealth_priority[loop]=;
				if(pri==1)
				{
					if((yf+1)==7)
						stealth_priority[loop]=6;
					else if((xf-1)==7)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf+1)==7)
						stealth_priority[loop]=11;
					else if((xf-1)==7)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf+1)==7)
						stealth_priority[loop]=16;
					else if((xf-1)==7)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf+1)==7)
						stealth_priority[loop]=22;
					else if((xf-1)==7)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf+1)==7)
						stealth_priority[loop]=28;
					else if((xf-1)==7)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf-1+'A';
				demo_move[1]=8-xf+1;
				demo_move[2]=yf+1+'A';
				demo_move[3]=8-xf-1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
					//stealth_priority[loop]=;
			}
		}
		if(test[xf+1][yf+1]==4)
		{
			if(test[xf-1][yf-1]==0)
			{
				//stealth_priority[loop]=;
				if(pri==1)
				{
					if((yf-1)==0)
						stealth_priority[loop]=6;
					else if((xf-1)==7)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf-1)==0)
						stealth_priority[loop]=11;
					else if((xf-1)==7)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf-1)==7)
						stealth_priority[loop]=16;
					else if((xf-1)==7)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf-1)==0)
						stealth_priority[loop]=22;
					else if((xf-1)==7)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf-1)==0)
						stealth_priority[loop]=28;
					else if((xf-1)==7)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf+1+'A';
				demo_move[1]=8-xf+1;
				demo_move[2]=yf-1+'A';
				demo_move[3]=8-xf-1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
					//stealth_priority[loop]=;
			}
		}
	}
	else
	{
		//stealth_priority[loop]=;
		if(pri==1)
			stealth_priority[loop]=5;
		else if(pri==2)
			stealth_priority[loop]=10;
		else if(pri==3)
			stealth_priority[loop]=15;
		else if(pri==4)
			stealth_priority[loop]=21;
		else if(pri==5)
			stealth_priority[loop]=27;
		if(test[xf+1][yf+1]==1 || test[xf+1][yf+1]==3)
		{
			if(test[xf-1][yf-1]==0)
			{
				//stealth_priority[loop]=;
				if(pri==1)
				{
					if((yf-1)==0)
						stealth_priority[loop]=6;
					else if((xf-1)==0)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf-1)==0)
						stealth_priority[loop]=11;
					else if((xf-1)==0)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf-1)==0)
						stealth_priority[loop]=16;
					else if((xf-1)==0)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf-1)==0)
						stealth_priority[loop]=22;
					else if((xf-1)==0)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf-1)==0)
						stealth_priority[loop]=28;
					else if((xf-1)==0)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf+1+'A';
				demo_move[1]=8-xf+1;
				demo_move[2]=yf-1+'A';
				demo_move[3]=8-xf-1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
					//stealth_priority[loop]=;
			}
		}
		if(test[xf+1][yf-1]==1 || test[xf+1][yf-1]==3)
		{
			if(test[xf-1][yf+1]==0)
			{
				//stealth_priority[loop]=;
				if(pri==1)
				{
					if((yf+1)==7)
						stealth_priority[loop]=6;
					else if((xf-1)==0)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf+1)==7)
						stealth_priority[loop]=11;
					else if((xf-1)==0)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf+1)==7)
						stealth_priority[loop]=16;
					else if((xf-1)==0)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf+1)==7)
						stealth_priority[loop]=22;
					else if((xf-1)==0)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf+1)==7)
						stealth_priority[loop]=28;
					else if((xf-1)==0)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf+1+'A';
				demo_move[1]=8-xf-1;
				demo_move[2]=yf-1+'A';
				demo_move[3]=8-xf+1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
					//stealth_priority[loop]=;
			}
		}
		if(test[xf-1][yf-1]==3)
		{
			if(test[xf+1][yf+1]==0)
			{
				//stealth_priority[loop]=;
				if(pri==1)
				{
					if((yf+1)==7)
						stealth_priority[loop]=6;
					else if((xf+1)==0)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf+1)==7)
						stealth_priority[loop]=11;
					else if((xf+1)==0)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf+1)==7)
						stealth_priority[loop]=16;
					else if((xf+1)==0)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf+1)==7)
						stealth_priority[loop]=22;
					else if((xf+1)==0)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf+1)==7)
						stealth_priority[loop]=28;
					else if((xf+1)==0)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf-1+'A';
				demo_move[1]=8-xf-1;
				demo_move[2]=yf+1+'A';
				demo_move[3]=8-xf+1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
					//stealth_priority[loop]=;
			}
		}
		if(test[xf-1][yf+1]==3)
		{
			if(test[xf+1][yf-1]==0)
			{
				//stealth_priority[loop]=;
				if(pri==1)
				{
					if((yf-1)==0)
						stealth_priority[loop]=6;
					else if((xf+1)==0)
						stealth_priority[loop]=7;
				}
				else if(pri==2)
				{
					if((yf-1)==0)
						stealth_priority[loop]=11;
					else if((xf+1)==0)
						stealth_priority[loop]=12;
				}
				else if(pri==3)
				{
					if((yf-1)==0)
						stealth_priority[loop]=16;
					else if((xf+1)==0)
						stealth_priority[loop]=17;
				}
				else if(pri==4)
				{
					if((yf-1)==0)
						stealth_priority[loop]=22;
					else if((xf+1)==0)
						stealth_priority[loop]=23;
				}
				else if(pri==5)
				{
					if((yf-1)==0)
						stealth_priority[loop]=28;
					else if((xf+1)==0)
						stealth_priority[loop]=29;
				}
				demo_move[0]=yf+1+'A';
				demo_move[1]=8-xf+1;
				demo_move[2]=yf-1+'A';
				demo_move[3]=8-xf-1;
				if(stealth_is_multiple(boardCheckers,demo_move))
				{
					if(pri==1)
						stealth_priority[loop]=8;
					else if(pri==2)
						stealth_priority[loop]=13;
					else if(pri==3)
						stealth_priority[loop]=18;
					else if(pri==4)
						stealth_priority[loop]=24;
					else if(pri==5)
						stealth_priority[loop]=30;
				}
					//stealth_priority[loop]=;
			}
		}
	}
}

void stealth_s_attack(puck boardCheckers[8][8],char array[32][4],int k)
{
	int loop=0,i=0,retval=0,x=0,y=0;
	char move[5];
	for(loop=0;loop<k;loop++)
	{
		for(i=0;i<4;i++)
			move[i]=array[loop][i];
		x=8+'0'-move[1];
		y=move[0]-'A';
		if(move[3]-move[1]==2 || move[1]-move[3]==2)			//jumps
		{
			if(move[1]=='8')					//lowest level
			{
				retval=stealth_is_multiple(boardCheckers,move);
				if(retval)
				{
					if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=9;
					else
						stealth_bettermove(boardCheckers,move,loop,2);
				}
				else
				{
					if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=14;
					else
						stealth_bettermove(boardCheckers,move,loop,3);
				}
			}
			else						//king and other level
			{
				retval=stealth_is_multiple(boardCheckers,move);	
				if(retval)
				{
					if(move[3]=='1' && boardCheckers[x][y]!=4)
						stealth_priority[loop]=3;
					else if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=4;
					else
						stealth_bettermove(boardCheckers,move,loop,1);
				}
				else
				{
					if(move[3]=='1' && boardCheckers[x][y]!=4)
						stealth_priority[loop]=19;
					else if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=20;
					else
						stealth_bettermove(boardCheckers,move,loop,4);
				}
			}
		}
		else										//normal moves
		{
			if(move[3]=='1' && boardCheckers[x][y]!=4)
				stealth_priority[loop]=25;
			else if(move[2]=='H' || move[2]=='A')
				stealth_priority[loop]=26;
			else
				stealth_bettermove(boardCheckers,move,loop,5);
		}		
	}
}

void stealth_attack(puck boardCheckers[8][8],char array[32][4],int k)
{
	int loop=0,i=0,retval=0,x=0,y=0;
	char move[5];
	for(loop=0;loop<k;loop++)
	{
		for(i=0;i<4;i++)
			move[i]=array[loop][i];
		x=8+'0'-move[1];
		y=move[0]-'A';
		if(move[3]-move[1]==2 || move[1]-move[3]==2)			//jumps
		{
			if(move[1]=='1')					//lowest level
			{
				retval=stealth_is_multiple(boardCheckers,move);
				if(retval)
				{
					if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=9;
					else
						stealth_bettermove(boardCheckers,move,loop,2);
				}
				else
				{
					if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=14;
					else
						stealth_bettermove(boardCheckers,move,loop,3);
				}
			}
			else						//king and other level
			{
				retval=stealth_is_multiple(boardCheckers,move);	
				if(retval)
				{
					if(move[3]=='8' && boardCheckers[x][y]!=3)
						stealth_priority[loop]=3;
					else if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=4;
					else
						stealth_bettermove(boardCheckers,move,loop,1);
				}
				else
				{
					if(move[3]=='8' && boardCheckers[x][y]!=3)
						stealth_priority[loop]=19;
					else if(move[2]=='H' || move[2]=='A')
						stealth_priority[loop]=20;
					else
						stealth_bettermove(boardCheckers,move,loop,4);
				}
			}
		}
		else										//normal moves
		{
			if(move[3]=='8' && boardCheckers[x][y]!=3)
				stealth_priority[loop]=25;
			else if(move[2]=='H' || move[2]=='A')
				stealth_priority[loop]=26;
			else
				stealth_bettermove(boardCheckers,move,loop,5);
		}		
	}
}


int stealth(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
	int decide;
	stealth_khiladi=player;
	int i=0,j=0;
	if(player==2)
	{
		if(decide=stealth_s_prevent(boardCheckers,array,k))
			return decide;
		stealth_s_attack(boardCheckers,array,k);
		for(i=1;i<31;i++)
			for(j=0;j<k;j++)
				if(stealth_priority[j]==i)
					return j;
	}
	else
	{
		if(decide=stealth_prevent(boardCheckers,array,k))
			return decide;
		stealth_attack(boardCheckers,array,k);
		for(i=1;i<31;i++)
			for(j=0;j<k;j++)
				if(stealth_priority[j]==i)
					return j;

	}
}
