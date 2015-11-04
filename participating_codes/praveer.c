#include "stdio.h"


int praveer(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
int i,j,l,x,y,n,g=0;
int prio[32];
k=0;
if(player==1)
	{
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
			if(boardCheckers[i][j]=='1')
			{
					if(boardCheckers[i-1][j-1]=='0')
					{
						if(i-1>=0 && i-1<=7 && j-1>=0 && j-1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i-1;
						array[k][3]=j - 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i-1][j+1]=='0')
					{
						if(i-1>=0 && i-1<=7 && j+1>=0 && j+1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i-1;
						array[k][3]=j + 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i-1][j-1]=='1'|| boardCheckers[i-1][j-1]=='3')
					{
					continue;
					}
					
					if(boardCheckers[i-1][j-1]=='2' || boardCheckers[i-1][j-1]=='4')
					{
					    if(i-2>=0 && i-2<=7 && j-2>=0 && j-2<=7)
						{
							if(boardCheckers[i-2][j-2]=='0')
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i-2;
							array[k][3]=j - 2 + 'A';
							k++;
							}
						}
					}
					
					if(boardCheckers[i-1][j+1]=='2' || boardCheckers[i-1][j+1]=='4')
					{
					    if(i-2>=0 && i-2<=7 && j+2>=0 && j+2<=7)
						{
							if(boardCheckers[i-2][j+2]=='0')
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i-2;
							array[k][3]=j + 2 + 'A';
							k++;
							}
						}
					}
				
			}
			if(boardCheckers[i][j]=='3')
			{
					if(boardCheckers[i-1][j-1]=='0')
					{
						if(i-1>=0 && i-1<=7 && j-1>=0 && j-1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i-1;
						array[k][3]=j - 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i-1][j+1]=='0')
					{
						if(i-1>=0 && i-1<=7 && j+1>=0 && j+1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i-1;
						array[k][3]=j + 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i+1][j-1]=='0')
					{
						if(i+1>=0 && i+1<=7 && j-1>=0 && j-1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i+1;
						array[k][3]=j - 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i+1][j+1]=='0')
					{
						if(i+1>=0 && i+1<=7 && j+1>=0 && j+1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i+1;
						array[k][3]=j + 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i-1][j-1]=='0')
					{
					continue;
					}
					
					if(boardCheckers[i-1][j-1]=='2' || boardCheckers[i-1][j-1]=='4')
					{
						if(boardCheckers[i-2][j-2]=='0')
						{
							if(i-2>=0 && i-2<=7 && j-2>=0 && j-2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i-2;
							array[k][3]=j - 2 + 'A';
							k++;
							}
						}
					}
					
					if(boardCheckers[i-1][j+1]=='2' || boardCheckers[i-1][j+1]=='4')
					{
						if(boardCheckers[i-2][j+2]=='0')
						{
							if(i-2>=0 && i-2<=7 && j+2>=0 && j+2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i-2;
							array[k][3]=j + 2 + 'A';
							k++;
							}
						}
					}
					
					if(boardCheckers[i+1][j-1]=='2' || boardCheckers[i+1][j-1]=='4')
					{
						if(boardCheckers[i+2][j-2]=='0')
						{
							if(i+2>=0 && i+2<=7 && j-2>=0 && j-2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i+2;
							array[k][3]=j - 2 + 'A';
							k++;
							}
						}
					}
					
					if(boardCheckers[i+1][j+1]=='2' || boardCheckers[i+1][j+1]=='4')
					{
						if(boardCheckers[i+2][j+2]=='0')
						{
							if(i+2>=0 && i+2<=7 && j+2>=0 && j+2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i+2;
							array[k][3]=j + 2 + 'A';
							k++;
							}
						}
					}
				
			}
			}
			
		}
	}
	
	//now for player two
	//player2
if(player==2)
	{
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
			if(boardCheckers[i][j]=='2')
			{
					if(boardCheckers[i+1][j-1]=='0')
					{
						if(i+1>=0 && i+1<=7 && j-1>=0 && j-1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i+1;
						array[k][3]=j - 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i+1][j+1]=='0')
					{
						if(i+1>=0 && i+1<=7 && j+1>=0 && j+1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i+1;
						array[k][3]=j + 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i+1][j-1]=='2'|| boardCheckers[i+1][j-1]=='4')
					{
					continue;
					}
					
					if(boardCheckers[i+1][j-1]=='1' || boardCheckers[i+1][j-1]=='3')
					{
						if(boardCheckers[i+2][j-2]=='0')
						{
							if(i+2>=0 && i+2<=7 && j-2>=0 && j-2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i+2;
							array[k][3]=j - 2 + 'A';
							k++;
							}	
						}
					}
					
					if(boardCheckers[i+1][j+1]=='1' || boardCheckers[i+1][j+1]=='3')
					{
						if(boardCheckers[i+2][j+2]=='0')
						{
							if(i+2>=0 && i+2<=7 && j+2>=0 && j+2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i+2;
							array[k][3]=j + 2 + 'A';
							k++;
							}
						}
					}
				
			}
			if(boardCheckers[i][j]=='4')
			{
					if(boardCheckers[i-1][j-1]=='0')
					{
						if(i-1>=0 && i-1<=7 && j-1>=0 && j-1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i-1;
						array[k][3]=j - 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i-1][j+1]=='0')
					{
						if(i-1>=0 && i-1<=7 && j+1>=0 && j+1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i-1;
						array[k][3]=j + 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i+1][j-1]=='0')
					{
						if(i+1>=0 && i+1<=7 && j-1>=0 && j-1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i+1;
						array[k][3]=j - 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i+1][j+1]=='0')
					{
						if(i+1>=0 && i+1<=7 && j+1>=0 && j+1<=7)
						{
						array[k][0]=i;
						array[k][1]=j+'A';
						array[k][2]=i+1;
						array[k][3]=j + 1 + 'A';
						k++;
						}
					}
					
					if(boardCheckers[i-1][j-1]=='0')
					{
					continue;
					}
					
					if(boardCheckers[i-1][j-1]=='1' || boardCheckers[i-1][j-1]=='3')
					{
						if(boardCheckers[i-2][j-2]=='0')
						{
							if(i-2>=0 && i-2<=7 && j-2>=0 && j-2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i-2;
							array[k][3]=j - 2 + 'A';
							k++;
							}
						}
					}
					
					if(boardCheckers[i-1][j+1]=='1' || boardCheckers[i-1][j+1]=='3')
					{
						if(boardCheckers[i-2][j+2]=='0')
						{
							if(i-2>=0 && i-2<=7 && j+2>=0 && j+2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i-2;
							array[k][3]=j + 2 + 'A';
							k++;
							}
						}
					}
					
					if(boardCheckers[i+1][j-1]=='1' || boardCheckers[i+1][j-1]=='3')
					{
						if(boardCheckers[i+2][j-2]=='0')
						{
							if(i+2>=0 && i+2<=7 && j-2>=0 && j-2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i+2;
							array[k][3]=j - 2 + 'A';
							k++;
							}
						}
					}
					
					if(boardCheckers[i+1][j+1]=='1' || boardCheckers[i+1][j+1]=='3')
					{
						if(boardCheckers[i+2][j+2]=='0')
						{
							if(i+2>=0 && i+2<=7 && j+2>=0 && j+2<=7)
							{
							array[k][0]=i;
							array[k][1]=j+'A';
							array[k][2]=i+2;
							array[k][3]=j + 2 + 'A';
							k++;
							}
						}
					}
				
			}
			
			
		}
	}
	}

// for returning index
for(l=0;l<=k;l++)
{
if(array[l][0]==array[l][2]+2 || array[l][0]==array[l][2]-2 )
return l;
else
prio[g++]=l;
}

for(n=0;n<=g;n++)
{
x=array[n][2];
y=array[n][3];
	if(player==1)
	{
	if(boardCheckers[x-1][y-1]==2 || boardCheckers[x-1][y-1]==4 || boardCheckers[x-1][y+1]==2 || boardCheckers[x-1][y+1]==4 || boardCheckers[x+1][y+1]==4 || boardCheckers[x+1][y+1]==4)
	return n;
	}
	else 
	{
	if(boardCheckers[x+1][y-1]==1 || boardCheckers[x+1][y-1]==3 || boardCheckers[x+1][y+1]==1 || boardCheckers[x+1][y+1]==3 || boardCheckers[x-1][y+1]==3 || boardCheckers[x-1][y+1]==3)
	return n;
	}

}

return 0;	

}
