#include "stdio.h"
#include<string.h>
typedef struct kill
{
	int index;
	int cnt;
	int mul;

}kill;
int coep_it(puck boardCheckers[8][8],int player,char array[32][4],int k1)
{
	static int first;
	kill k[12],sm;
	int i,j,u,kk,v=0,flag=0,cnt1=0,cnt2=0,loss0,loss1,loss2,loss1f,loss2f,loss0f;
	char l[4];
	if(player==1){
		printf("%d",player);
//first condn
	if(!first++)
		return search(array,"E3F4");
	//if(first==1)
	//	return search(array,"D2E3");	
	else
	{

		//See from opposite if any is getting killed..
		if(strlen(array)==4)
			return 0;
		if((array[0][0]-array[0][2])==-2 || (array[0][0]-array[0][2])==2 )
		{
			printf("True");
			for(u=0;u<k1;u++){
				int j=array[u][0]-65;
				int i=array[u][1]-48-1;
				cnt1=0;cnt2=0;
				//determine no of losses
				if((array[u][0]-array[u][2])==-2)
				{
					sprintf(l,"%c%c%c%c",array[u][0],array[u][1],array[u][2],array[u][3]);
					k[v].cnt=0;
					printf("%d",j);
					k[v].index=search(array,l);
					k[v].cnt=0;
					if((i+3)<8 && (j+3)<8 && boardCheckers[i+3][j+3]==2)
					{
						cnt1++;	
						if(j+3<8 && i>0 && boardCheckers[i][j+2]==1 && boardCheckers[i-1][j+3]==0 ){
							cnt1++;
						}			

					}

					 if((i+3)<8 && (j+3)<8 && boardCheckers[i+3][j+1]==2 && boardCheckers[i+1][j+3]==0)
					{	
							
							cnt2++;
							
						
						if(j+2<8 && i>0 && k[v].cnt==1 && boardCheckers[i][j+2]==1 && boardCheckers[i-1][j+1]==0){
							cnt2++;
							
						}		
						else if(j+5<8 && i>0 && k[v].cnt==1 &&boardCheckers[i][j+4]==1 && boardCheckers[i-1][j+5]==0){
							cnt2++;
						}	
					}

									
				}

				if((array[u][0]-array[u][2])==2 )
				{
					sprintf(l,"%c%c%c%c",array[u][0],array[u][1],array[u][2],array[u][3]);
					k[v].cnt=0;
					k[v].index=search(array,l);
					
					if((i+3)<8 && (j-1)>=0 && boardCheckers[i+3][j-3]==2)
					{
						cnt1++;
						
						if(j-3>=0 && i>0 && boardCheckers[i][j-2]==1 && boardCheckers[i-1][j-3]==0){
							cnt1++;
						}			

					}
					 if((i+3)<8 && (j-3)>0 && boardCheckers[i+3][j-1]==2 && boardCheckers[i+1][j-3]==0)
					{	
							
							cnt2++;
							
						if(j-1>=0 &&i>0 && k[v].cnt==1 &&boardCheckers[i][j-2]==1 && boardCheckers[i-1][j-1]==0){							
							cnt2++;
						}		
						else if(j-5>=0&& i>0 && k[v].cnt==1 &&boardCheckers[i][j-4]==1 && boardCheckers[i-1][j-5]==0){						
							cnt2++;
						}	
					}

					
				}

				if(cnt1<=cnt2)
				{

					k[v].cnt=cnt2;
				
				}
				else
					k[v].cnt=cnt1;	
				v++;

			}
			sm=k[0];
			
			for(u=1;u<k1;u++)
			{
				if(k[u].cnt < sm.cnt)
				{
					sm=k[u];
				}
	
			}
			printf("\n %d",k[0].cnt);
			return sm.index;
		}
		//give protection n prevent losses
		for(i=0;i<8;i++){
			for(j=0;j<8;j++)
			{
				loss0=0,loss1=0,loss2=0,loss0f=0,loss1f=0,loss2f=0;
				if(8>i && i>0 && 8>j && j>0 && boardCheckers[i][j]==1 && boardCheckers[i+1][j+1] == 2 && boardCheckers[i-1][j-1]==0)
				{	
					//conditions for protection
					if(j>0 && i+1<8 && boardCheckers[i+1][j-1]==0 )
					{
						loss0f=1;
						if(i+2<8 && j-2>=0 &&  boardCheckers[i+2][j-2]==2)
						{

							loss0++;
						}
					}

					if(i>1 && j>1 && boardCheckers[i-2][j-2]==1 &&boardCheckers[i-1][j-1]==0)
					{
						loss1f=1;
						if(boardCheckers[i][j-2] == 2 && boardCheckers[i-2][j]==0)
						
						{
							loss1++;
				
						}

					}
					if(i>1 && j>1 && boardCheckers[i-2][j]==1 && boardCheckers[i-1][j-1]==0 )
					{
						loss2f=1;
						if(boardCheckers[i][j-2] == 2)
						
						{
							loss2++;
				
						}

					}
					if(loss1==0 && loss1f)
					{

						sprintf(l,"%c%d%c%d",j-2+65,i-1,j-1+65,i);
						return search(array,l);
					}
					if(loss2==0 &&  loss2f)
					{

						sprintf(l,"%c%d%c%d",j+65,i-1,j-1+65,i);
						return search(array,l);
					}
					if(loss0==0 && loss0f){
						sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i+2);
						return search(array,l);				
					}
					
				}
			if(8>i && i>0 && 8>j+1&& j-1>=0 && boardCheckers[i][j]==1 && boardCheckers[i+1][j-1] == 2 && boardCheckers[i-1][j+1]==0)
				{	
					//conditions for protection
					if(j+1<8 && i+1<8 && boardCheckers[i+1][j+1]==0 )
					{
						loss0f=1;
						if(i+2<8 && j+2<8 &&  boardCheckers[i+2][j+2]==2)
						{

							loss0++;
						}
					}

					if(i>1 && j+2<8 && boardCheckers[i-2][j+2]==1 && boardCheckers[i-1][j+1]==0)
					{
						
						loss1f=1;
						if(j+2<8 && boardCheckers[i][j+2] == 2 && boardCheckers[i-2][j]==0)
						
						{
							loss1++;
							//if(i-3>=0 && j-3>0 && boardCheckers[i-3][j-3]==0);
							//loss1--;
				
						}

					}
					if(i>1 && j>1 && boardCheckers[i-2][j]==1 && boardCheckers[i-1][j+1]==0)
					{
						loss2f=1;
						if(boardCheckers[i][j+2] == 2)
						
						{
							loss2++;
				
						}

					}
					if(loss1==0 && loss1f)
					{

						sprintf(l,"%c%d%c%d",j+2+65,i-1,j+1+65,i);
						printf("%s",l);
						return search(array,l);
					}
					if(loss2==0 && loss2f)
					{

						sprintf(l,"%c%d%c%d",j+65,i-2+1,j+1+65,i);
						printf("%s",l);
						return search(array,l);
					}
					if(loss0==0 && loss0f){
						sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i+2);
						return search(array,l);				
					}
					else if(loss1 &&loss1f){
						sprintf(l,"%c%d%c%d",j+2+65,i-1,j+1+65,i);
						printf("%s",l);
						return search(array,l);
					}
					else if(loss2 && loss2f){
						sprintf(l,"%c%d%c%d",j+65,i-2+1,j+1+65,i);
						printf("%s",l);
						return search(array,l);
					}
					else if(loss0 && loss0f){
						sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i+2);
						return search(array,l);	
					}
				}
			}
		}
		//code for smple moves
		for(i=7;i>=0;i--){
			for(j=7;j>=0;j--){//for ist row
			
				if(j<6 && i+2<8 && boardCheckers[i-1][j+1]==0 && boardCheckers[i][j]==3 && boardCheckers[i-2][j+2]!=2  ){	
					 if(boardCheckers[i-2][j]==2){	
						if( boardCheckers[i][j+2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i);
					printf("%s  %d",l,j);
					return search(array,l);	
					}
					}
					else{
						sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i);
					printf("%s  %d",l,j);
					return search(array,l);
					}
				}
				if(j-2>=0 && boardCheckers[i-1][j-1]==0 && boardCheckers[i][j]==3  && boardCheckers[i-2][j-2]!=2 ){	if(boardCheckers[i-2][j]==2){	
						if( boardCheckers[i][j-2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i);
					printf("%s",l);
					return search(array,l);	
				}}
				else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i);
					printf("%s",l);
					return search(array,l);	
				}
				}
			}
			
		}

		for(i=0;i<8;i++){
			for(j=0;j<8;j++){//for ist row
				if(j<6 && j>1 && i+2<8 && boardCheckers[i+1][j+1]==0 && boardCheckers[i][j]==1 && boardCheckers[i+2][j+2]!=2 ){	
					if(boardCheckers[i+2][j]==2){	
						if( boardCheckers[i][j+2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i+2);
					printf("%s  %d",l,j);
					return search(array,l);	
				}}
				}
				if(j-1>=0 && boardCheckers[i+1][j-1]==0 && boardCheckers[i][j]==1  && boardCheckers[i+2][j-2]!=2  ){	
		if(boardCheckers[i+2][j]==2){	
						if( boardCheckers[i][j-2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i+2);
					printf("%s",l);
					return search(array,l);	
				}}}
			}
			
		}
		
	}
	return 0;
	}
	else{
		printf("     %s        ",array);
		if(!first++)
			return search(array,"B6A5");	
		else{
			if(k==1)
			return 0;
			else{
				if((array[0][0]-array[0][2])==-2 || (array[0][0]-array[0][2])==2 )
				{
				printf("True");
				for(u=0;u<k1;u++)
				{	int j=array[u][0]-65;
					int i=array[u][1]-48-1;
					cnt1=0;cnt2=0;
					//determine no of losses
						if((array[u][0]-array[u][2])==-2)
						{
							sprintf(l,"%c%c%c%c",array[u][0],array[u][1],array[u][2],array[u][3]);
							k[v].cnt=0;
							printf("%d",j);
							k[v].index=search(array,l);
							k[v].cnt=0;
							if((i-3)>=0 && (j+3)<8 && boardCheckers[i-3][j+3]==1)
							{
								cnt1++;	
								printf("yesss");
								if(j+3<8 && i+1<8 && boardCheckers[i][j+2]==2 && boardCheckers[i+1][j+3]==0 )						{
									cnt1++;
							}
							}
							if((i-1)>=0 && (j+3)<8 && boardCheckers[i-3][j+1]==1 && boardCheckers[i-1][j+3]==0)
						{	
							
							cnt2++;
							
						
						if(j+2<8 && i>0 && k[v].cnt==1 && boardCheckers[i][j+2]==2 && boardCheckers[i+1][j+1]==0)						{
							cnt2++;
							
						}		
						else if(j+5<8 && i>0 && k[v].cnt==1 &&boardCheckers[i][j+4]==2 && boardCheckers[i+1][j+5]==0)					{
							cnt2++;
						}	
						}
					}
						if((array[u][0]-array[u][2])==2 )
		{
			sprintf(l,"%c%c%c%c",array[u][0],array[u][1],array[u][2],array[u][3]);
			k[v].cnt=0;
			k[v].index=search(array,l);
					
			if((i-3)>=0 && (j-1)>=0 && boardCheckers[i-3][j-3]==1)
				{
					cnt1++;
						printf("enterd in it");
					if(j-3>=0 && i+1<8 && boardCheckers[i][j-2]==2 && boardCheckers[i+1][j-3]==0){
						cnt1++;
					}			

				}
				 if((i-1)>=0 && (j-3)>0 && boardCheckers[i-3][j-1]==1 && boardCheckers[i-1][j-3]==0)
				{				
					cnt2++;
							
						if(j-1>=0 &&i+1<8 && k[v].cnt==1 &&boardCheckers[i][j-2]==2 && boardCheckers[i+1][j-1]==0){							
							cnt2++;
						}		
						else if(j-5>=0&& i+1>8 && k[v].cnt==1 &&boardCheckers[i][j-4]==2 && boardCheckers[i+1][j-5]==0){						
							cnt2++;
						}	
					}
	}
					if(cnt1<=cnt2)
				{

					k[v].cnt=cnt2;
				
				}
				else
					k[v].cnt=cnt1;	
					
				v++;
						
						}
				sm=k[0];
			
			for(u=1;u<k1;u++)
			{
				if(k[u].cnt < sm.cnt)
				{
					sm=k[u];
				}
	
			}
			return sm.index;	
			
				}


			for(i=7;i>=0;i--){
			for(j=7;j>=0;j--)
			{
				loss0=0,loss1=0,loss2=0,loss0f=0,loss1f=0,loss2f=0;
				if(8>i && i>0 && 8>j && j>0 && boardCheckers[i][j]==2 && boardCheckers[i-1][j+1] == 2 && boardCheckers[i+1][j-1]==0)
				{	
					//conditions for protection
					if(j>0 && i-1>=0 && boardCheckers[i-1][j-1]==0 )
					{
						loss0f=1;
						if(i-2>=0 && j-2>=0 &&  boardCheckers[i-2][j-2]==2)
						{

							loss0++;
						}
					}

					if(i+1<8 && j>1 && boardCheckers[i+2][j-2]==2&&boardCheckers[i+1][j-1]==0)
					{
						loss1f=1;
						if(boardCheckers[i][j-2] == 1 && boardCheckers[i+2][j]==0)
						
						{
							loss1++;
				
						}

					}
					if(i+2<8 && j>1 && boardCheckers[i+2][j]==2 && boardCheckers[i+1][j-1]==0 )
					{
						loss2f=1;
						if(boardCheckers[i][j-2] == 1)
						
						{
							loss2++;
				
						}

					}
					if(loss1==0 && loss1f)
					{

						sprintf(l,"%c%d%c%d",j-2+65,i+3,j-1+65,i+2);
						return search(array,l);
					}
					if(loss2==0 &&  loss2f)
					{

						sprintf(l,"%c%d%c%d",j+65,i+3,j-1+65,i+2);
						return search(array,l);
					}
					if(loss0==0 && loss0f){
						sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i);
						return search(array,l);				
					}
					
				}
			if(i-1>=0 && 8>j+1&& j-1>=0 && boardCheckers[i][j]==2 && boardCheckers[i-1][j-1] == 1 && boardCheckers[i+1][j+1]==0)
				{	
					//conditions for protection
					if(j+1<8 && i-1>=0 && boardCheckers[i-1][j+1]==0 )
					{
						loss0f=1;
						if(i-2>=0 && j+2<8 &&  boardCheckers[i-2][j+2]==1)
						{

							loss0++;
						}
					}

					if(i+2<8 && j+2<8 && boardCheckers[i+2][j+2]==2 && boardCheckers[i+1][j+1]==0)
					{
						
						loss1f=1;
						if(j+2<8 && i+2<8 && boardCheckers[i][j+2] == 1 && boardCheckers[i+2][j]==0)
						
						{
							loss1++;
							//if(i-3>=0 && j-3>0 && boardCheckers[i-3][j-3]==0);
							//loss1--;
				
						}

					}
					if(i+2<8 && j>1 && boardCheckers[i+2][j]==2 && boardCheckers[i+1][j+1]==0)
					{
						loss2f=1;
						if(boardCheckers[i][j+2] == 1)
						
						{
							loss2++;
				
						}

					}
					if(loss1==0 && loss1f)
					{

						sprintf(l,"%c%d%c%d",j+2+65,i+3,j+1+65,i+2);
						printf("%s",l);
						return search(array,l);
					}
					if(loss2==0 && loss2f)
					{

						sprintf(l,"%c%d%c%d",j+65,i+2+1,j+1+65,i+2);
						printf("%s",l);
						return search(array,l);
					}
					if(loss0==0 && loss0f){
						sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i);
						return search(array,l);				
					}
					else if(loss1 &&loss1f){
						sprintf(l,"%c%d%c%d",j+2+65,i+3,j+1+65,i+2);
						printf("%s",l);
						return search(array,l);
					}
					else if(loss2 && loss2f){
						
						sprintf(l,"%c%d%c%d",j+65,i+2+1,j+1+65,i+2);
						printf("%s",l);
						return search(array,l);
					}
					else if(loss0 && loss0f){
						sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i);
						return search(array,l);		
					}
				}
			}
		}




			//code for smple moves


		for(i=0;i<8;i++){
			for(j=0;j<8;j++){//for ist row
				if(j<6 && j>1 && i+2<8 && boardCheckers[i+1][j+1]==0 && boardCheckers[i][j]==4 && boardCheckers[i+2][j+2]!=1 ){	
					if(boardCheckers[i+2][j]==1){	
						if( boardCheckers[i][j+2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i+2);
					printf("%s  %d",l,j);
					return search(array,l);	
				}}
				}
				if(j-1>=0 && boardCheckers[i+1][j-1]==0 && boardCheckers[i][j]==4  && boardCheckers[i+2][j-2]!=1  ){	
		if(boardCheckers[i+2][j]==1){	
						if( boardCheckers[i][j-2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i+2);
					printf("%s",l);
					return search(array,l);	
				}}}
			}
			
		}


		for(i=7;i>=0;i--){
			for(j=7;j>=0;j--){//for ist row
			
				if(j<6 && i+2<8 && boardCheckers[i-1][j+1]==0 && boardCheckers[i][j]==2 && boardCheckers[i-2][j+2]!=1  ){	
					 if(boardCheckers[i-2][j]==1){	
						if( boardCheckers[i][j+2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i);
					printf("%s  %d",l,j);
					return search(array,l);	
					}
					}
					else{
						sprintf(l,"%c%d%c%d",j+65,i+1,j+1+65,i);
					printf("%s  %d",l,j);
					return search(array,l);
					}
				}
				if(j-2>=0 && boardCheckers[i-1][j-1]==0 && boardCheckers[i][j]==2  && boardCheckers[i-2][j-2]!=1 ){	if(boardCheckers[i-2][j]==1){	
						if( boardCheckers[i][j-2]==0){}
					else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i);
					printf("%s",l);
					return search(array,l);	
				}}
				else{
					sprintf(l,"%c%d%c%d",j+65,i+1,j-1+65,i);
					printf("%s",l);
					return search(array,l);	
				}
				}
			}
			
		}

			}
		}
	

}
return 0;
}
int search(char array[32][4],char st[]){
	char *p=strstr(array[0],st);
	return ((p-array[0])/4);
}
