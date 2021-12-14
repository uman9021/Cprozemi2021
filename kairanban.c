#include <stdio.h>

typedef struct
{
    int number;
    int days;
    char person[];
}kairanban;

void Kairanban(kairanban *k)
{
    printf("N: %d\n", (*k).number);
    int number;
    scanf("%d", &number);
    if(3 <= number && number <= 10)
    {
        for (int n = 0; n < number; n++)
        {
            printf("A[n]の在宅日: %d\n", (*k).days);
        }    
    }
    else
    {
        return 0;
    }

    
    return 0;
}

void Search(int 日付、int 場所){
  //回覧板が動ける場所を探す
  if(動ける場所がある){
    移動
  }
  日付++;
  Search(日付、場所)  //再帰
}

int main(void)
{
    static int d[] = {0, 1, 2, 3, 4, 5, 6};
    int i, j, num1, num2, tmp;
    int n = (*k).number;
    int number;
    while(1)
    {
        printf("N:");
        scanf("%d", &number);
        if(3 <= number && number <= 10)
        {
            break;
        }
        else
        {
            printf("ERROR nは3以上10以下で入力してください。\n");
        }
    }

    int **house;
    house = malloc(number * sizeof(int*));
    
        for (int n = 0; n < number; n++)
        {
            printf("A[n]の在宅日: %d\n", (*k).days);
        }    
    }
    else
    {
        return 0;
    }

        for (i = 0; i < n; i++)
        {
            num1 = rand() % 7;
            if(num1 == 6)
            {
                num1 = 5;
            }
            num2 = num1 + 1;
            tmp = d[num1];
            d[num1] = d[num2];
            d[num2] = tmp;
        }
        for (j = 0; j < 9; j++)
        {
            printf("%d\n", d[j]);
        }
}
