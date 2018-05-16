#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX 6

int FindMatch(char [MAX][MAX],char *,int [MAX][MAX],int ,int ,int ,int ,int );
int FindMatch_wrapper(char [MAX][MAX],char *,int,int);
int FindMatch_wrapper(char mat[MAX][MAX],char *pat,int nrow,int ncol){
	if(strlen(pat)>nrow*ncol)return 0;
	int used[MAX][MAX]={{0,},};
	return FindMatch(mat,pat,used,0,0,nrow,ncol,0);	
}
int FindMatch(char mat[MAX][MAX],char *pat,int used[MAX][MAX],int x,int y,int nrow,int ncol,int level){
	if(level==strlen(pat))
		return 1;
	if(used[x][y]) 
		return 0;
	if(mat[x][y]!=pat[level]&&level==0){
		if(x<nrow-1)
			return FindMatch(mat,pat,used,x+1,y,nrow,ncol,level);
		else if(y<ncol-1)
			return FindMatch(mat,pat,used,0,y+1,nrow,ncol,level);
		return 0;
	}
	else if(mat[x][y]==pat[level])
	{	int res=0;
		used[x][y]=1;
		res=(x>0?FindMatch(mat,pat,used,x-1,y,nrow,ncol,level+1):0)||
		(res=x<(nrow-1)?FindMatch(mat,pat,used,x+1,y,nrow,ncol,level+1):0)||
		(res=y>0?FindMatch(mat,pat,used,x,y-1,nrow,ncol,level+1):0)||
		(res=y<(ncol-1)?FindMatch(mat,pat,used,x,y+1,nrow,ncol,level+1):0)||
		(res=x<(nrow-1)&&(y<ncol-1)?FindMatch(mat,pat,used,x+1,y+1,nrow,ncol,level+1):0)||
		(res=x<(nrow-1)&&y>0?FindMatch(mat,pat,used,x+1,y-1,nrow,ncol,level+1):0)||
		(res=x>0&&y<(ncol-1)?FindMatch(mat,pat,used,x-1,y+1,nrow,ncol,level+1):0)||
		(res=x>0&&y>0?FindMatch(mat,pat,used,x-1,y-1,nrow,ncol,level+1):0);
	used[x][y]=0;
	return res;
	
	}
	return 0;
	
}
int main(){
	
	char mat[MAX][MAX]={
					{'#','.','.','.','#','.'},
					{'.','#','.','#','.','#'},
					{'#','#','.','.','#','.'},
					{'.','.','.','.','.','.'},
					{'.','#','.','#','.','#'},
					{'#','.','.','.','#','.'},
				};
	char pat[]="###";
	if(FindMatch_wrapper(mat,pat,6,6)){
		printf("true");
	}else{printf("false");}
	return 0;}
