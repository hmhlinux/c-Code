#include "game1.h"

void InitBoard(char board[ROW][COL],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            board[i][j] = ' ';
        }
    }
}

void DisplayBoard(char board[ROW][COL],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf(" %c ",board[i][j]);//打印数据:空格空格空格,数据只是3个空格，重点是格式
            if(j<col-1){
                printf("|");//最后一列不需要|
            }
        }
        printf("\n");//printf("   |   |   \n");
        if (i < row - 1)
        //打印非数据，固定的，最后一行下面只需要数据不需要这个固定格式
        {
            for(int j=0;j<col;j++){
                printf("---");
                if(j<col-1){
                    printf("|");//控制最后一列只输出---
                }
            }
            printf("\n");//printf("---|---|---\n")
        }
    }
}

void PlayerMove(char board[ROW][COL],int row,int col){
    int x,y=0;
    printf("玩家走:>\n");
    
    while(1){
        printf("请输入下棋的坐标:>");
        scanf("%d %d",&x,&y);
        //判断坐标合法性
        if(x>=1 && x<=row && y>=1 && y<=col){
            //下棋
            //坐标是否被占用
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }
            else{
                printf("坐标被占用,请重新输入\n");
            }
        }
        else{
            printf("坐标非法，请重新输入\n");
        }
    }
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
    printf("电脑走:>\n");

    while(1){
        int x = rand()%row;//模，范围是1 ~ row-1
        int y = rand()%col;
        if(board[x][y] == ' ')
        {
            board[x][y]= '#';
            break;
        }
    }
}

char IsWin(char board[ROW][COL],int row,int col)
{
    for(int i=0;i<row;i++)//判断三行，返回值*/#
    {
        if(board[i][0]== board[i][1]&& board[i][1]== board[i][2] && board[i][1]!= ' '){
            return board[i][0];
        }
    }

    for(int i=0;i<col;i++)//判断三列
    {
        if(board[0][i]== board[1][i]&& board[0][i]== board[2][i] && board[0][i]!= ' '){
            return board[1][i];
        }
    }

    //对角线
    if(board[0][0]== board[1][1]&& board[1][1]==board[2][2]&& board[1][1]!= ' '){
        return board[1][1];
    }
    if(board[0][2]== board[1][1]&& board[1][1]==board[2][0]&& board[1][1]!= ' '){
        return board[1][1];
    }
    //判断平局
    int ret = IsFull(board,row,col);//满了返回1，不满返回0
    if(ret ==1){
        return 'E';
    }
    //继续
    return 'O';
}

int IsFull(char board[ROW][COL],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]== ' '){
                return 0;//棋盘没满
            }
        }
    }
    return 1;
}