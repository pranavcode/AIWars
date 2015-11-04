/*
	Name:-		Nikhil Devshatwar
	Team:- 		unbeaten
	Contact:-	9028904309
*/
#include<stdio.h>
#include<stdlib.h>

/*************************************************** Unordered Tree **************************************************/
#define SIZE 64
typedef struct unode {
	int val;
	int adv;
	int nchild;
	struct unode *children[SIZE];
	struct unode *parent;
}unode;

typedef struct unode *utree;

void init(utree *ut) {
	*ut = (unode *)malloc(sizeof(unode));
	(*ut)->val = 0;
	(*ut)->adv = 0;
	(*ut)->nchild = 0;
	(*ut)->parent = NULL;
}

utree addNewNode(utree *ut,int *index,int ilen,int newval,int adv) {
	int i;
	unode *current = ut;
	unode *newnode = (unode *)malloc(sizeof(unode));
	newnode->val = newval;
	newnode->adv = adv;
	newnode->nchild = 0;
	current = *ut;
	for(i=0;i<ilen;i++) {
		if(current==NULL || index[i] >= current->nchild) {
			return NULL;
		}
		current = current->children[index[i]];
	}
	current->children[current->nchild++] = newnode;
	newnode->parent = current;
	return newnode;
}

void traverse(utree n,int level) {
	int i;
	for(i=0;i<level;i++) {
		printf("-");
	}
	//printf(">%d %d\n",n->val,n->adv);
	for(i=0;i<n->nchild;i++) {
		traverse(n->children[i],level+1);
	}
}

void destroy(utree ut) {
	int i;
	if(ut == NULL)
		return;
	for(i=0;i<ut->nchild;i++) {
		destroy(ut->children[i]);
	}
}

/*************************************************** Main **************************************************/
int dummymain() {
	int idcs[64]={0,1};
	int arp[] = {2};
	int nik[] = {3};
	utree x;
	init(&x);
	addNewNode(&x,idcs,0,15,0);
	addNewNode(&x,idcs,0,23,0);
	addNewNode(&x,idcs,0,53,0);
	addNewNode(&x,idcs,0,6823,0);
	addNewNode(&x,idcs,1,99,0);
	addNewNode(&x,idcs,1,88,0);
	addNewNode(&x,idcs,2,55,0);
	addNewNode(&x,arp,1,67,0);
	addNewNode(&x,nik,1,53,0);
	traverse(x,0);
	destroy(x);
	return 0;
}

/*************************************************** AI **************************************************/
int unbeaten_player;
int unbeaten_orig;
int unbeaten_jump;
int unbeaten_path[16];
int unbeaten_movedone = 0;
int unbeaten_ans;
			//Count number of pucks of player present on the board  -- constraint for decision
int unbeaten_count(puck brd[8][8]) {
	int i,j,count=0;
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			if(brd[i][j] == unbeaten_player || brd[i][j] == unbeaten_player + 2) {
				count++;
			}
		}
	}
//	printf("count=%d\n",count);
	return count;
}

int unbeaten_advtg_old(puck brd[8][8]) {
	int i,j,adv=0;
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			if(brd[i][j] == unbeaten_orig || brd[i][j] == unbeaten_orig + 2) {
				adv++;
			} else if(brd[i][j] != 0) {
				adv--;
			}
		}
	}
//	printf("advantage=%d\n",adv);
	return adv;	
}
int unbeaten_advtg(puck brd[8][8]) {
	int i,j,adv=0;
	int opp = unbeaten_orig % 2 + 1;
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			if(brd[i][j] == unbeaten_orig) {
				adv+=3;
			} else if(brd[i][j] == unbeaten_orig + 2) {
				adv+=4;
			} else if(brd[i][j] == opp) {
				adv-=3;
			} else if(brd[i][j] == opp + 2) {
				adv-=4;
			}
		}
	}
	return adv;	
}
			//Display the intermediate board situation  -- while trying moves
void unbeaten_display(puck board[8][8]) {
	int i,j;
	printf("\n");
	printf("\t\t      A   B   C   D   E   F   G   H  \n");
	printf("\t\t    +---+---+---+---+---+---+---+---+\n");
	for(i=7;i>=0;i--) {
		printf("\t\t  %d ",i+1);
		for(j=0;j<8;j++) {
			printf("| %d ",board[i][j]);
		}
		printf("|\n");
		printf("\t\t    +---+---+---+---+---+---+---+---+\n");
	}
}
			//Apply some move  --	TRIAL
int unbeaten_doMove(puck brd[8][8],char *move) {
	int i,j;
	unbeaten_movedone = 1;
//	printf("do %c%c%c%c\n",move[0],move[1],move[2],move[3]);
	brd[move[3] - '1'][move[2] - 'A'] = brd[move[1] - '1'][move[0] - 'A'];
	brd[move[1] - '1'][move[0] - 'A'] = 0;
	if(abs(move[1] - move[3])==2) {
		i = '1' + ((move[1] - '1') + (move[3] - '1'))/2;
		j = 'A' + ((move[0] - 'A') + (move[2] - '1'))/2;
		brd[i][j] = 0;
		if(unbeaten_movePossible(brd,move[3] - '1',move[2] - 'A') > 15) {
			unbeaten_movedone = 0;
		}
	}
	i = move[3] - '1';
	if(unbeaten_player==1 && i==7 && brd[move[3] - '1'][move[2] - 'A'] != 1) {
		brd[move[3] - '1'][move[2] - 'A'] = 3;
		unbeaten_movedone = 1;
	}
	if(unbeaten_player==2 && i==0 && brd[move[3] - '1'][move[2] - 'A'] != 2) {
		brd[move[3] - '1'][move[2] - 'A'] = 4;
		unbeaten_movedone = 1;
	}
}
			//Restore board from a move  --	ERROR
int unbeaten_undoMove(puck brd[8][8],char *move) {
	//printf("undo %c%c%c%c\n",move[0],move[1],move[2],move[3]);
}
			//Return all possible moves
int unbeaten_movePossible(puck brd[8][8],int i,int j) {
	int value = 0;
	if(unbeaten_player != 2) {
		if(i+1 <=7 && j-1 >=0 && brd[i+1][j-1] ==0) {
			value |= 1;
		}
		if(i+1 <=7 && j+1 <=7 && brd[i+1][j+1] ==0) {
			value |= 2;
		}
		if(i+2 <=7 && j-2 >=0 && brd[i+2][j-2] ==0 && brd[i+1][j-1] !=0 && brd[i+1][j-1]%2 +1 == unbeaten_player) {
			unbeaten_jump = 1;
			value |= 16;
		}
		if(i+2 <=7 && j+2 <=7 && brd[i+2][j+2] ==0 && brd[i+1][j+1] !=0 && brd[i+1][j+1]%2 +1 == unbeaten_player) {
			unbeaten_jump = 1;
			value |= 32;
		}
	}
	if(unbeaten_player != 1) {
		if(i-1 >=0 && j-1 >=0 && brd[i-1][j-1] ==0) {
			value |= 4;
		}
		if(i-1 >=0 && j+1 <=7 && brd[i-1][j+1] ==0) {
			value |= 8;
		}
		if(i-2 >=0 && j-2 >=0 && brd[i-2][j-2] ==0 && brd[i-1][j-1] !=0 && brd[i-1][j-1]%2 +1 == unbeaten_player) {
			unbeaten_jump = 1;
			value |= 64;
		}
		if(i-2 >=0 && j+2 <=7 && brd[i-2][j+2] ==0 && brd[i-1][j+1] !=0 && brd[i-1][j+1]%2 +1 == unbeaten_player) {
			unbeaten_jump = 1;
			value |= 128;
		}
	}
	return value;
}

			//Generate valid moves  -- Need to pass to the next level
int unbeaten_generateValid(puck brd[8][8],char valid[32][4]) {
	int i,j,len = 0,newlen = 0;
	int value,dx;
	unbeaten_jump = 0;
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			if(brd[i][j] == unbeaten_player || brd[i][j] == unbeaten_player + 2) {
				value = unbeaten_movePossible(brd,i,j);
//printf("i,j,val=%d %d %d\n",i,j,value);
				if(unbeaten_jump) {		//Jump Compulsary
					dx = 2;
					value = value >> 4;
				} else {
					dx = 1;
				}
				if(value & 1) {
					valid[len][0] = 'A'+j;
					valid[len][1] = '1'+i;
					valid[len][2] = 'A'+j-dx;
					valid[len][3] = '1'+i+dx;	
					len++;				
				}
				if(value & 2) {
					valid[len][0] = 'A'+j;
					valid[len][1] = '1'+i;
					valid[len][2] = 'A'+j+dx;
					valid[len][3] = '1'+i+dx;	
					len++;				
				}
				if(value & 4) {
					valid[len][0] = 'A'+j;
					valid[len][1] = '1'+i;
					valid[len][2] = 'A'+j-dx;
					valid[len][3] = '1'+i-dx;	
					len++;				
				}
				if(value & 8) {
					valid[len][0] = 'A'+j;
					valid[len][1] = '1'+i;
					valid[len][2] = 'A'+j+dx;
					valid[len][3] = '1'+i-dx;	
					len++;				
				}
			}
		}
	}
	if(unbeaten_jump) {
		for(i=0;i<len;i++) {
			if(abs(valid[i][1] - valid[i][3]) == 2) {
				valid[newlen][0] = valid[i][0];
				valid[newlen][1] = valid[i][1];
				valid[newlen][2] = valid[i][2];
				valid[newlen][3] = valid[i][3];
				newlen++;
			}
		}
		len = newlen;
	}
	return len;
}

int unbeaten_solve(utree *t,puck board[8][8],char valid[32][4],int len,int level) {
	int i,j,newlen,count,advtg;
	char newMoves[32][4];
	puck brd[8][8];
	if(level >6)
		return;
//getchar();
	for(i=0;i<len;i++) {
//printf("trying move %d of %d at level=%d\n",i,len,level);
		memcpy(brd,board,64*sizeof(puck));
		unbeaten_doMove(brd,valid[i]);
		if(unbeaten_movedone) {
			unbeaten_player = unbeaten_player==1?2:1;
		}
		count = unbeaten_count(brd);
		advtg = unbeaten_advtg(brd);
		addNewNode(t,unbeaten_path,level,count,advtg);
		newlen = unbeaten_generateValid(brd,newMoves);
//		printf("VALID MOVES ARE %d\n",newlen);
//		for(j=0;j<newlen;j++) {
//			printf("%c%c%c%c    ",newMoves[j][0],newMoves[j][1],newMoves[j][2],newMoves[j][3]);
//		}
//		printf("\n");
		unbeaten_path[level] = i;
		unbeaten_solve(t,brd,newMoves,newlen,level+1);
	}
	return 0;
}

int unbeaten_calc(utree t) {
	int i,max,val,maxindex;
	if(t == NULL) {
		return -500;
	}
	max = t->adv;
	maxindex = 0;
	for(i=0;i<t->nchild;i++) {
		val = unbeaten_calc(t->children[i]);
		if(val > max) {
			max = val;
			maxindex = i;
		}
	}
	unbeaten_ans = maxindex;
	return max;
}

int unbeaten(puck boardCheckers[8][8],int player,char array[32][4],int k) {
	utree tree;
	int count,max;
    int return_val;
	//printf("\nUnbeaten AI Started\n");
	unbeaten_player = player;
	unbeaten_orig = player;
	init(&tree);
	unbeaten_movedone = 0;
	count = unbeaten_count(boardCheckers);
	tree->val = count;
	traverse(tree,0);
	unbeaten_solve(&tree,boardCheckers,array,k,0);
	max = unbeaten_calc(tree);
//	traverse(tree,0);
	destroy(tree);
//	printf("\nUnbeaten AI returning ans=%d adv=%d\n",unbeaten_ans,max);
	return_val = unbeaten_ans;
	return return_val;
}
