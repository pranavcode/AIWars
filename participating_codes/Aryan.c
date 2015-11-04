#include "stdio.h"

int Aryan(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
	int i=0,j=0,l=0,a=0,b=0,cnt=0;
	int index[10]={0};

if(player==1)
{
	if(array[0][3]-array[0][1]>=2||array[0][1]-array[0][3]>=2)
                return 0;
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(boardCheckers[i][j]==1||boardCheckers[i][j]==3)
			{
				if((boardCheckers[i+1][j+1]==2&&boardCheckers[i-1][j-1]==0)||(boardCheckers[i+1][j-1]==2&&boardCheckers[i-1][j+1]==0))
				{
					for(l=0;l<k;l++)
					{
						if(array[l][1]-49==i&&array[l][0]-65==j)
						{
							index[cnt++]=l;
						}
					}
			
				}
				else if((boardCheckers[i+1][j+1]==4&&boardCheckers[i-1][j-1]==0)||(boardCheckers[i+1][j-1]==4&&boardCheckers[i-1][j+1]==0)||(boardCheckers[i-1][j+1]==4&&boardCheckers[i+1][j-1]==0)||(boardCheckers[i-1][j-1]==4&&boardCheckers[i+1][j+1]==0))
				{
					for(l=0;l<k;l++)
					{
						if(array[l][1]-49==i&&array[l][0]-65==j)
						{
							index[cnt++]=l;
						}
					}
				}
			}
		}
	}

	if(cnt>0)
	{
		for(i=0;i<cnt;i++)
		{
			a=array[index[i]][3]-49;
			b=array[index[i]][2]-65;
			if((boardCheckers[a+1][b+1]==2)||(boardCheckers[a+1][b-1]==2))
			{
				i++;
			}
			else if((boardCheckers[a+1][b+1]==4)||(boardCheckers[a+1][b-1]==4)||(boardCheckers[a-1][b+1]==4)||(boardCheckers[a-1][b-1]==4))
			{
				i++;
			}
			else 
				return index[i];
		}
	}


	for(i=0;i<k;i++)
	{
		a=array[i][3]-49;
		b=array[i][2]-65;
		if(a>0&&a<7&&b>0&&b<7)
		{
			if((boardCheckers[a+1][b+1]==2)||(boardCheckers[a+1][b-1]==2))
			{
				;
			}
			else if((boardCheckers[a+1][b+1]==4)||(boardCheckers[a+1][b-1]==4)||(boardCheckers[a-1][b+1]==4)||(boardCheckers[a-1][b-1]==4))
			{
				;
			}
			else 
			{
				if(array[i][3]<array[i][1]&&boardCheckers[array[i][1]-49][array[i][0]-65]==3)
				{
					if(boardCheckers[array[i][3]-49-1][array[i][2]-65+1]==2||boardCheckers[array[i][3]-49-1][array[i][2]-65-1]==2)
						return i;
					else
						return i; 
					
				}
				else if(boardCheckers[array[i][1]-49][array[i][0]-65]!=3)
					return i;
			}
		}
	}
	
	//printf("\treturn 0");
	for(i=0;i<k;i++)
	{
		if(array[i][3]-49==7||array[i][3]-49==0||array[i][2]-65==7||array[i][2]-65==0)
		return i;
	}
	return 0;	
}
	
else
{
	if(array[0][3]-array[0][1]>=2||array[0][1]-array[0][3]>=2)
                return 0;
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(boardCheckers[i][j]==2||boardCheckers[i][j]==4)
			{
				if((boardCheckers[i-1][j-1]==1&&boardCheckers[i+1][j+1]==0)||(boardCheckers[i-1][j+1]==1&&boardCheckers[i+1][j-1]==0))
				{
					for(l=0;l<k;l++)
					{
						if(array[l][1]-49==i&&array[l][0]-65==j)
						{
							index[cnt++]=l;
							//printf("\n%d,%d die",i,j);
						}
					}
			
				}
				else if((boardCheckers[i-1][j-1]==3&&boardCheckers[i+1][j+1]==0)||(boardCheckers[i-1][j+1]==3&&boardCheckers[i+1][j-1]==0)||(boardCheckers[i+1][j-1]==3&&boardCheckers[i-1][j+1]==0)||(boardCheckers[i+1][j+1]==3&&boardCheckers[i-1][j-1]==0))
				{
					for(l=0;l<k;l++)
					{
						if(array[l][1]-49==i&&array[l][0]-65==j)
						{
							index[cnt++]=l;
							//printf("\n%d,%d die",i,j);
						}
					}
				}
			}
		}
	}

	if(cnt>0)
	{
		for(i=0;i<cnt;i++)
		{
			a=array[index[i]][3]-49;
			b=array[index[i]][2]-65;
			if((boardCheckers[a-1][b-1]==1)||(boardCheckers[a-1][b+1]==1))
			{
				i++;
			}
			else if((boardCheckers[a-1][b-1]==3)||(boardCheckers[a-1][b+1]==3)||(boardCheckers[a+1][b-1]==3)||(boardCheckers[a+1][b+1]==3))
			{
				i++;
			}
			else 
				return index[i];
		}
	}
	/*else
	{ 
		printf("\tNo one is to die");	
	}*/

	for(i=0;i<k;i++)
	{
		a=array[i][3]-49;
		b=array[i][2]-65;
		if(a>0&&a<7&&b>0&&b<7)
		{
			if((boardCheckers[a-1][b-1]==1)||(boardCheckers[a-1][b+1]==1))
			{
				;
			}
			else if((boardCheckers[a-1][b-1]==3)||(boardCheckers[a-1][b+1]==3)||(boardCheckers[a+1][b-1]==3)||(boardCheckers[a+1][b+1]==3))
			{
				;
			}
			else 
			{
				if(array[i][3]>array[i][1]&&boardCheckers[array[i][1]-49][array[i][0]-65]==4)
				{
					if(boardCheckers[array[i][3]-49+1][array[i][2]-65-1]==1||boardCheckers[array[i][3]-49+1][array[i][2]-65+1]==1)
						return i;
					else
						return i;
				}
				else if(boardCheckers[array[i][1]-49][array[i][0]-65]!=4)
					return i;
			}
		}
	}
	
	//printf("\tNo safe move");
	for(i=0;i<k;i++)
	{
		if(array[i][3]-49==7||array[i][3]-49==0||array[i][2]-65==7||array[i][2]-65==0)
		return i;
	}
	return 0;
}

}

