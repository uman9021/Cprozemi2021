#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int number;
    int days;
    char person[];
}kairanban;

typedef struct 
{
    int** stayornot;    //家にいるかどうか
    int people;     //人が何人いるのか
}people;

typedef struct
{
    int where;  //今回覧板がどこにあるか
    int when;   //今回覧板があるまでの日数
}deliver;

typedef struct
{
    int *receiveornot;   //回覧板が届いたのか
    int ***receivedornot;    //回覧板が過去に通ったかどうか
}receive;

void search(kairanban, deliver now, deliver *prev, people peo, receive *rec)
{
    int youbi;
    youbi = now.when % 7;   //曜日を調べる
    
    int i, j, k, l;
    int number; 
    if (peo.stayornot[now.where][youbi] == 0)   //1で家にいる、0で家にいない、なので、家にいないとき
    {
        now.when++; //日付を進める
    }
    else    //家にいるとき
    {
        for (i = now.where + 1; i < peo.people; i++)    //i人目に渡す場合
        {
            if (i == now.where) //渡す先が自分の家だった場合
            {
                continue;
            }
            else
            {
                if (peo.stayornot[i][youbi] == 1)   //i人目が家にいる場合
                {
                    for (j = 0; j < peo.people; j++)
                    {
                        rec[number].receiveornot[j] = rec[number - 1].receiveornot[j]; 
                        for (k = 0; k < peo.people; k++)
                        {
                            for (l = 0; l < 7; l++)
                            {
                                rec[number].receivedornot[j][k][l] = rec[number - 1].receivedornot[j][k][l];
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(void)
{
    int number;
    while(1)
    {
        printf("N:");
        scanf("%d", &number);
        if (3 <= number && number <= 10)
        {
            break;
        }
        else
        {
            printf("ERROR nは3以上10以下で入力してください。\n");
        }
    }

    int **house;
    house = malloc(number * sizeof(int*));  //縦n個分の配列

    int *A;
    A = malloc(number * sizeof(int*));
    
    for (int n = 0; n < number; n++)
    {
        printf("A[%d]の在宅日: ", n);
        scanf("%d", &A[n]);
        house[n] = malloc(3 * sizeof(int));
        house[n][2] = A[n] % 10;
        house[n][1] = (int) ((A[n] % 100) - (A[n] % 10)) / 10;
        house[n][0] = (int) (A[n] - (A[n] % 100)) / 100; 
    }
    int i,j,k;
    int **stayin;
    stayin = malloc(number * sizeof(int*)); 
    for (i = 0; i < number; i++) 
    {
        stayin[i] = malloc(7 * sizeof(int));
        for (j = 0; j < 3; j++) 
        {
            printf("%d ", house[i][j]);
            for (k = 0; k < 7; k++)
            {
                if (house[i][j] == k)
                {
                    stayin[i][k] = 1;
                }
                else
                {
                    stayin[i][k] = 0;
                }
            }
        }
        printf("\n");
    }
}
