#include <stdio.h>

#define w 80
#define h 25

int l = 12, k = 12;

int  ballheight = 0, balldirection = 0, mi = 0, mj = 39, score1 = 0, score2 = 0;

void map();
void ball();

int main() {
    char q;
    q = '.';
    while (q != 'Q') {
        ball();
        map();
        scanf("%c", &q);
        switch (q)
        { case 'A':
            l--;
            if (l < 0) {
            l = 0;
            }
            break;
        case 'Z':
        l++;
        if (l > 22) {
            l = 22;
        }
            break;
        case 'K':
        k--;
        if (k < 0) {
            k = 0;
            }
        break;
        case 'M':
        k++;
        if (k > 22) {
            k = 22;
            }
        break;
        case ' ':
        break;
        }
        if (score1 == 21) {
            q = 'Q';
            printf("Win PLAYER 1!");
        }
        if (score2 == 21) {
            q = 'Q';
            printf("Win PLAYER 2!");
        }
    }
}

void map() {   // прорисовка карты
    char x;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (i > 0 && i < 24 && j > 0 && j < 79 )
            x = ' ';
            else
            x = 'x';
            if ((i == l || i == l + 1 || i == l + 2) && j == 1)
            x = '|';
            if ((i == k || i == k + 1 || i == k + 2) && j == 78)
            x = '|';
            if (j == 39)
            x = '+';
            if (i == mi && j == mj)
            x = '@';
            printf("%c", x);
        }
    printf("\n");
    }
    printf("PLAYER 1: %d                                                     PLAYER 2: %d\n", score1, score2);
}

void ball() {   // отскок мяча
    while (balldirection == 0) {   // движение вправо
        mj++;
        if (ballheight == 0) {
            mi++;
        } else {
            mi--;
        }
        if (mi == 0) {
            ballheight = 0;
         }
        if (mi == 25) {
             ballheight = 1;
         }
        if (mj == 78 && (mi == k || mi == k+1 || mi == k+2)) {
                if (ballheight == 0) {
                 ballheight = 0;
                 balldirection = 1;
             }
             if (ballheight == 1) {
                 ballheight = 1;
                 balldirection = 1;
             }
        }
        break;
    }
    while (balldirection == 1) {   // движение влево
        mj--;
        if (ballheight == 0) {
            mi++;
        } else {
            mi--;
        }
        if (mi == 0) {
            ballheight = 0;
         }
         if (mi == 25) {
             ballheight = 1;
         }
         if (mj == 1 && (mi == l || mi == l+1 || mi == l+2)) {
             if (ballheight == 0) {
                 ballheight = 0;
                 balldirection = 0;
             }
             if (ballheight == 1) {
                 ballheight = 1;
                 balldirection = 0;
             }
        }
         break;
    }
  if (mj > 78) {
            score1+=1;
            mi = 0;
            mj = 39;
            balldirection = 0;
            ballheight = 0;
        }
    if (mj < 1) {
            score2+=1;
            mi = 0;
            mj = 39;
            balldirection = 1;
            ballheight = 0;
    }
}




