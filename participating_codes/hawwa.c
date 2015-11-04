#include <stdio.h>
#include <string.h>


int hawwa(puck boardCheckers[8][8],int player,char array[32][4],int k)
{
    int i,flag = 0;
    int temp_row,temp_col;

	if(player == 1)
	{
	// for forced moves
	for(i = 0; i < k; i++)
	{
			if(array[i][3] - array[i][1] == 2 || array[i][1] - array[i][3] == 2) 
			{
				temp_row = array[i][3] - '1';
				temp_col = array[i][2] - 'A';
				
				if(boardCheckers[temp_row + 1][temp_col + 1] == 2 )
				{
					if(boardCheckers[temp_row + 2][temp_col + 2] == 0)
					{
						if(boardCheckers[temp_row - 1][temp_col - 1] != 0)
							return i;
					}
				}
				if(boardCheckers[temp_row + 1][temp_col - 1] == 2)
				{
					if (boardCheckers[temp_row + 2][temp_col - 2] == 0)
					{
						if(boardCheckers[temp_row - 1][temp_col + 1] != 0)
							return i;
					}
				}
			}
	}	
	
	// side positions
	for(i = 0; i < k; i++)
	{
		temp_row = array[i][1] - '1';
		temp_col = array[i][0] - 'A';
		//if(boardCheckers[temp_row][temp_col] == 1)
		{
			if(array[i][3] == '8')
							return i;
			if((array[i][1] != '1') && (array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;
		}							
	}
	
	for(i = 0;i < k; i++)
	{
          if(array[i][1] !=  '1' && (array[i][0] != 'A' && array[i][0] != 'H'))
          { 
          		/*if((array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;*/
                printf("%d",i);
                temp_row = array[i][3] - '1';
                temp_col = array[i][2] - 'A';
				
                if(array[i][0] < array[i][2])
                       flag = 1;
                if(flag == 1)
                {
					//	printf("%d\t",boardCheckers[temp_row - 1][temp_col + 1]);
						if((boardCheckers[temp_row + 1][temp_col - 1] == 2) && (boardCheckers[temp_row + 1][temp_col + 1] != 2) )
						{
								if(boardCheckers[temp_row - 1][temp_col + 1] != 0)
								{
										return i;
								}
						}
																						
                        if((boardCheckers[temp_row + 1][temp_col + 1] == 0 || boardCheckers[temp_row + 1][temp_col + 1] == 1) &&(boardCheckers[temp_row + 1][temp_col - 1] == 1 || boardCheckers[temp_row + 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        }             
                }
                else 
                {
						if((boardCheckers[temp_row + 1][temp_col + 1] == 2) && (boardCheckers[temp_row + 1][temp_col - 1] != 2))
							{
								if(boardCheckers[temp_row - 1][temp_col - 1] != 0)
								{
										return i;
								}
							}
                        if((boardCheckers[temp_row + 1][temp_col + 1] == 0 || boardCheckers[temp_row + 1][temp_col + 1] == 1) &&(boardCheckers[temp_row + 1][temp_col - 1] == 1 || boardCheckers[temp_row + 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        } 
                }
         }                              
	}
	
	for(i = 0;i < k; i++)
	{
          if(array[i][1] !=  '1' && (array[i][0] == 'A' || array[i][0] == 'H'))
          { 
          		/*if((array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;*/
               // printf("%d",i);
                temp_row = array[i][3] - '1';
                temp_col = array[i][2] - 'A';
				
                if(array[i][0] < array[i][2])
                       flag = 1;
                if(flag == 1)
                {
					//	printf("%d\t",boardCheckers[temp_row - 1][temp_col + 1]);
						if((boardCheckers[temp_row + 1][temp_col - 1] == 2) && (boardCheckers[temp_row + 1][temp_col + 1] != 2) )
						{
								if(boardCheckers[temp_row - 1][temp_col + 1] != 0)
								{
										return i;
								}
						}
																						
                        if((boardCheckers[temp_row + 1][temp_col + 1] == 0 || boardCheckers[temp_row + 1][temp_col + 1] == 1) &&(boardCheckers[temp_row + 1][temp_col - 1] == 1 || boardCheckers[temp_row + 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        }             
                }
                else 
                {
						if((boardCheckers[temp_row + 1][temp_col + 1] == 2) && (boardCheckers[temp_row + 1][temp_col - 1] != 2))
							{
								if(boardCheckers[temp_row - 1][temp_col - 1] != 0)
								{
										return i;
								}
							}
                        if((boardCheckers[temp_row + 1][temp_col + 1] == 0 || boardCheckers[temp_row + 1][temp_col + 1] == 1) &&(boardCheckers[temp_row + 1][temp_col - 1] == 1 || boardCheckers[temp_row + 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        } 
                }
         }                              
	}
	
	flag = 0;
	for(i = 0; i < k; i++)
	{						
			temp_row = array[i][3] - '1';
            temp_col = array[i][2] - 'A';
			if((array[i][2] - array[i][0] > 0) && (boardCheckers[temp_row + 1][temp_col + 1] == 2))
			{
					if(boardCheckers[temp_row - 2][temp_col] == 1 )
					{
							if(boardCheckers[temp_row][temp_col - 2] == 0)
										return i;
					}
					
					if(boardCheckers[temp_row - 2][temp_col - 2] == 1 )
					{
							return i;
					}
			}
			
			if((array[i][2] - array[i][0] < 0) && (boardCheckers[temp_row + 1][temp_col - 1] == 2))
			{
					if(boardCheckers[temp_row - 2][temp_col] == 1 )
					{
							if(boardCheckers[temp_row][temp_col + 2] == 0)
										return i;
					}
					if(boardCheckers[temp_row - 2][temp_col - 2] == 1)
					{
								return i;
					}
			}
	}
	
	for(i = 0; i<k; i++)
	{
			if((array[i][1] == '1') && (array[i][2] == 'A')  || (array[i][2] == 'H'))
                           			return i;
	}

	
	for(i=0;i<k;i++)
    {
          if(array[i][1] == '1')
          { 
          		/*if((array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;*/
                printf("%d",i);
                temp_row = array[i][3] - '1';
                temp_col = array[i][2] - 'A';
				
                if(array[i][0] < array[i][2])
                       flag = 1;
                if(flag == 1)
                {
						//printf("%d\t",boardCheckers[temp_row - 1][temp_col + 1]);
						if((boardCheckers[temp_row + 1][temp_col + 1] == 1 || boardCheckers[temp_row + 1][temp_col + 1] == 0) && ( boardCheckers[temp_row - 1][temp_col + 1] == 1 || boardCheckers[temp_row + 1][temp_col - 1] != 2))                        
                        {
                                                  return i;
                        }             
                }
                else 
                {
                        if((boardCheckers[temp_row + 1][temp_col - 1] == 1 || boardCheckers[temp_row + 1][temp_col - 1] == 0) && ( boardCheckers[temp_row - 1][temp_col - 1] == 1 || boardCheckers[temp_row + 1][temp_col + 1] != 2))
                        {
                                                  return i;
                        } 
                }
         }
    }
	}
	
	if(player == 2)
	{
		// forced move
		for(i = 0; i < k; i++)
		{
			if(array[i][3] - array[i][1] == 2 || array[i][1] - array[i][3] == 2) 
			{
				temp_row = array[i][3] - '1';
				temp_col = array[i][2] - 'A';
				
				if(boardCheckers[temp_row - 1][temp_col + 1] == 1 )
				{
					if(boardCheckers[temp_row - 2][temp_col + 2] == 0)
					{
						//if(boardCheckers[temp_row - 1][temp_col - 1] != 0)
							return i;
					}
				}
				if(boardCheckers[temp_row - 1][temp_col - 1] == 1)
				{
					if (boardCheckers[temp_row - 2][temp_col - 2] == 0)
					{
						//if(boardCheckers[temp_row - 1][temp_col + 1] != 0)
							return i;
					}
				}
			}
		}
			// side positions
		for(i = 0; i < k; i++)
		{
			temp_row = array[i][1] - '1';
			temp_col = array[i][0] - 'A';
			//if(boardCheckers[temp_row][temp_col] == 2)
			{
				if(array[i][3] == '1')
								return i;
				if((array[i][1] != '8') && (array[i][2] == 'A')  || (array[i][2] == 'H') )
				{
								//printf("Hello");
                       			return i;
				}				
			}							
		}

		for(i = 0;i < k; i++)
		{
          if(array[i][1] !=  '8' && (array[i][0] != 'A' && array[i][0] != 'H'))
			{ 
          		/*if((array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;*/
               // printf("%d",i);
                temp_row = array[i][3] - '1';
                temp_col = array[i][2] - 'A';
				
                if(array[i][0] < array[i][2])
                       flag = 1;
                if(flag == 1)
                {
					//	printf("%d\t",boardCheckers[temp_row - 1][temp_col + 1]);
						if(boardCheckers[temp_row - 1][temp_col - 1] == 1 && boardCheckers[temp_row - 1][temp_col + 1] != 1)
						{
								if(boardCheckers[temp_row + 1][temp_col + 1] != 0)
								{
										return i;
								}
						}
																						
                        if((boardCheckers[temp_row - 1][temp_col + 1] == 0 || boardCheckers[temp_row - 1][temp_col + 1] == 2) &&(boardCheckers[temp_row - 1][temp_col - 1] == 2 || boardCheckers[temp_row - 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        }             
                }
                else 
                {
						if(boardCheckers[temp_row - 1][temp_col + 1] == 1 && boardCheckers[temp_row - 1][temp_col - 1] != 1)
							{
								if(boardCheckers[temp_row + 1][temp_col - 1] != 0)
								{
										return i;
								}
							}
                        if((boardCheckers[temp_row - 1][temp_col + 1] == 0 || boardCheckers[temp_row - 1][temp_col + 1] == 2) &&(boardCheckers[temp_row - 1][temp_col - 1] == 2 || boardCheckers[temp_row - 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        } 
                }
			}                              
		}
		
		for(i = 0;i < k; i++)
		{
          if(array[i][1] !=  '8' && (array[i][0] == 'A' || array[i][0] == 'H'))
			{ 
          		/*if((array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;*/
               // printf("%d",i);
                temp_row = array[i][3] - '1';
                temp_col = array[i][2] - 'A';
				
                if(array[i][0] < array[i][2])
                       flag = 1;
                if(flag == 1)
                {
					//	printf("%d\t",boardCheckers[temp_row - 1][temp_col + 1]);
						if(boardCheckers[temp_row - 1][temp_col - 1] == 1 && boardCheckers[temp_row - 1][temp_col + 1] != 1)
						{
								if(boardCheckers[temp_row + 1][temp_col + 1] != 0)
								{
										return i;
								}
						}
																						
                        if((boardCheckers[temp_row - 1][temp_col + 1] == 0 || boardCheckers[temp_row - 1][temp_col + 1] == 2) &&(boardCheckers[temp_row - 1][temp_col - 1] == 2 || boardCheckers[temp_row - 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        }             
                }
                else 
                {
						if(boardCheckers[temp_row - 1][temp_col + 1] == 1 && boardCheckers[temp_row - 1][temp_col - 1] != 1)
							{
								if(boardCheckers[temp_row + 1][temp_col - 1] != 0)
								{
										return i;
								}
							}
                        if((boardCheckers[temp_row - 1][temp_col + 1] == 0 || boardCheckers[temp_row - 1][temp_col + 1] == 2) &&(boardCheckers[temp_row - 1][temp_col - 1] == 2 || boardCheckers[temp_row - 1][temp_col - 1] == 0))
                        {
                                                  return i;
                        } 
                }
			}                              
		}
		
		flag = 0;
		for(i = 0; i < k; i++)
		{						
			if((array[i][2] - array[i][0] > 0) && (boardCheckers[temp_row - 1][temp_col + 1] == 1))
			{
					if(boardCheckers[temp_row + 2][temp_col] == 2)
					{
							if(boardCheckers[temp_row][temp_col - 2] == 0)
										return i;
					}
					if(boardCheckers[temp_row + 2][temp_col-2] == 2)
					{
							return i;
					}
			}
			
			if((array[i][2] - array[i][0] < 0) && (boardCheckers[temp_row - 1][temp_col - 1] == 1))
			{
					if(boardCheckers[temp_row + 2][temp_col] == 2)
					{
							if(boardCheckers[temp_row][temp_col - 2] == 0)
										return i;
					}
					if(boardCheckers[temp_row + 2][temp_col - 2] == 2)
					{
							return i;
					}
			}
		}
		
		for(i = 0; i<k; i++)
		{
			if((array[i][1] == '8') && (array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;
		}
		
		for(i=0;i<k;i++)
		{
			if(array[i][1] == '8')
			{ 
          		/*if((array[i][2] == 'A')  || (array[i][2] == 'H') )
                           			return i;*/
              //  printf("%d",i);
                temp_row = array[i][3] - '1';
                temp_col = array[i][2] - 'A';
				
                if(array[i][0] < array[i][2])
                       flag = 1;
                if(flag == 1)
                {
					//	printf("%d\t",boardCheckers[temp_row - 1][temp_col + 1]);
						if((boardCheckers[temp_row - 1][temp_col + 1] == 2 || boardCheckers[temp_row - 1][temp_col + 1] == 0) && ( boardCheckers[temp_row + 1][temp_col + 1] == 2 || boardCheckers[temp_row - 1][temp_col - 1] != 1))                        
                        {
                                                  return i;
                        }             
                }
                else 
                {
                        if((boardCheckers[temp_row - 1][temp_col - 1] == 2 || boardCheckers[temp_row - 1][temp_col - 1] == 0) && ( boardCheckers[temp_row + 1][temp_col - 1] == 2 || boardCheckers[temp_row - 1][temp_col + 1] != 1))
                        {
                                                  return i;
                        } 
                }
			}							
		}
	}
               return 0;
}

    
