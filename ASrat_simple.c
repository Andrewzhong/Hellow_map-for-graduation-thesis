#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
	----------------------------
	Created by 钟小蛙 on 16/10/21.
	----------------------------

	++++   A*算法的简单实现    ++++
**/
#define Height_Y  20 //地图高度
#define Weight_X  20 //地图宽度
#define FALSE   0   
#define TRUE    1  
typedef int BOOL;

//定义地图 路径==1
int map[Height_Y][Weight_X] =    
{   
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },   
    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 },   
    { 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0 },   
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1 },   
    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0 },   
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 },   
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0 },   
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },   
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0 },   
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 },   
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }   
}; //地图  


typedef struct Node   
    {   
        int f,g,h;   
        int row;    //行   
        int col;    //列   
        int direction;//parent移动的方向
        struct Node * parent;   
    }Node, *Lnode;  

typedef struct Stack   
    {//OPEN CLOSED 表结构体   
        Node * npoint;   
        struct Stack * next;   
    }Stack, *Lstack;   

    int rows = Height_Y;
    int cols = Weigjt_X;
    int G_OFFSET = 1;
    int destinationRow;
    int destinationCol;
    int canMoveIndex = 0;
    int tileSize = 1;

    Lstack Open = NULL;
    Lstack Closed = NULL;
    Node * getNodeFromOpen()
    {
    	Lstack temp = Open->next,min = Open->next,minp = Open;
    	Node * minx;
    	if(temp == NULL)
    	{
    		return NULL;
    	}
    	while(temp->next != NULL)
    	{
    		if((temp->next ->npoint->f) < (min->npoint->f))
    		{
    			min =temp->next;
    			minp = temp;
    		}
    		temp = temp->next;
    	}
    	minx = min->npoint;
    	temp = minp->next;
    	minp->next = minp->next->next;
    	free(temp);
    	return minx;	
    }//选取Open表中的值

    









