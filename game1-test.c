#include "game1.h"
//三子棋
//1.game1-test.c 测试游戏的逻辑
//2.game1-game.h 关于游戏相关的函数声明，符号声明，包含的头文件
//3.game1-sanziqi.c 游戏相关函数的实现
void menu(){
    printf("*****************************\n");
    printf("***********1. play***********\n");
    printf("***********0. exit***********\n");
    printf("*****************************\n");
}
void game(){
    //实现游戏内容，棋盘9个格子，玩家用*和#区分，3x3，二维数组存储数据存储字符
    char board[ROW][COL];
    //初始化期盼--初始化为空格
    InitBoard(board,ROW,COL);
    // //打印一下棋盘--打印数组内容
    DisplayBoard(board,ROW,COL);
    char ret = 0;//接收游戏状态,*玩家赢，#电脑赢，E平，O继续
    while (1)
    {
        //玩家下棋
        PlayerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        //判断玩家是否赢得游戏
        ret = IsWin(board,ROW,COL);
        if (ret != 'O')//非继续跳出循环
            break;
        //电脑下棋
        ComputerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        //判断电脑是否赢得游戏
        ret = IsWin(board,ROW,COL);
        if (ret!= 'O')
            break;
    }
    if(ret == '*'){
        printf("玩家赢了\n");
    }else if(ret == '#'){
        printf("电脑赢了\n");
    }else{
        printf("平局\n");
    }
    DisplayBoard(board,ROW,COL);
}

int main(){
    int input = 0;   
    srand((unsigned int) time(NULL));

    do
    {
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            //printf("三子棋游戏\n");
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误，请重新选择\n");
            break;
        }
    } while (input);//while(0)是false,会退出循环
    return 0 ;
}