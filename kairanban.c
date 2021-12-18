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

int number;  //移動番号(グローバル変数)

// 最短日数を格納する変数を定義(グローバル変数)
// int minDays = 1000;

void search(kairanban kairanban, deliver now, deliver* prev, people peo, receive* rec)
{
    int youbi;
    youbi = now.when % 7;   //曜日を調べる
    
    int i, j, k, l;

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
                    // prev[movenum] = now;
                    // now.whereを更新
                    // rec.receivedornotに回覧板が通ったことを記録
                    // movenumをインクリメント
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
                    // rec.receiveornotに回覧板が届いたことを記録

                    //0軒目に回覧板が戻ってきた→ゴール判定
                    //　・・・
                }
                // break;
            }
        }
        //日付を進める
    }

    if//(1週間以上回覧板が動かなかった場合)
        // 1つ前の移動に戻る
        if //(number < 0) 
            //深さ優先探索終了

    if//(minDays以上の日数探索)
        //1つ前の移動に戻る

    if//(MaxDay日以上経過した場合)　※エスケープ処理
        //ERROR

    // Search(**);
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
        for (j = 0; j < 7; j++) 
        {
            stayin[i][j] = 0;
        }
    }

    for (i = 0; i < number; i++)
    {

        for (j = 0; j < 3; j++) 
        {
            printf("%d ", house[i][j]);
            for (k = 0; k < 7; k++)
            {
                if (house[i][j] == k)
                {
                    stayin[i][k] = 1;
                }
            }
        }
        printf("\n");
    }

    //deliver now, deliver *prev, people peo, receive *recを定義

    //prevとreceiveのメモリを確保する
    // prev = malloc(Max *sizeof(Kairanban));　　※※Maxは移動回数の最大値(とりあえず100ぐらいでいいかも)
    // rec  = 

    //now, prev, peo, recに初期値を入れる
    // now.where=0;
    // now.when=0;
    // for (i = 0; i < Max; i++) {
    //     prev[i].now = 0
    //
    
    //Search関数を呼び出し
    // Search(**);

    //結果出力
    // printf("%d\n", minDays);


}
