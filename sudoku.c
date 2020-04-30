#include <stdio.h>
//made by Rushabh Gandhi, Pathik Ghugare and Aakash Saroop 
// Sample input is there at the end 

void header();
int repeat_row(int a[9][9], int row, int num);
int repeat_col(int a[9][9], int col, int num);
int repeat_box(int a[9][9], int startRow, int startCol, int num);
int is_safe_num(int a[9][9], int row, int col, int num);
int find_empty(int a[9][9], int *row, int *col);
int sudokusol(int a[9][9]);
void print_sudoku(int a[9][9]);
int main() {

    int a[9][9];
    int i,j;
    header();
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            scanf("%d",&a[i][j]);

    if (sudokusol(a))
    {
    	printf("SOLVED SUDOKU : \n");
        print_sudoku(a);
    } else
    {
        printf("no solution");
    }

    return 0;
}
int repeat_row(int a[9][9], int row, int num){
    for (int col = 0; col < 9; col++) {
        if (a[row][col] == num) {
            return 1;
        }
    }
    return 0;
}
int repeat_col(int a[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (a[row][col] == num) {
            return 1;
        }
    }
    return 0;
}
int repeat_box(int a[9][9], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (a[row + startRow][col + startCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}
int is_safe_num(int a[9][9], int row, int col, int num) {
    return !repeat_row(a, row, num)
            && !repeat_col(a, col, num)
            && !repeat_box(a, row - (row % 3), col - (col %3), num);
}
int find_empty(int a[9][9], int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (a[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}
int sudokusol(int a[9][9]) {

    int row = 0;
    int col = 0;

    if (!find_empty(a, &row, &col)){
        return 1;
    }

    for (int num = 1; num <= 9; num++ ) {

        if (is_safe_num(a, row, col, num)) {
            a[row][col] = num;

            if (sudokusol(a)) {
                return 1;
            }

            a[row][col] =0;
        }
    }

    return 0;
}
void print_sudoku(int a[9][9]) {
    for (int row = 0; row < 9; row++) {
        if(row%3==0)
                   printf("-----------------------\n");
        for (int col = 0; col < 9; col++) {
            if(col%3==0)
                printf("|");
            printf("%2d", a[row][col]);
            if(col==8)
                printf("|");
        }
        if(row==8)
        {
            printf("\n-----------------------");
        }
        printf("\n");
    }
}

void header(){
    int i, j, k, n=6;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i + j <= n - 1)
                printf("*");
            else
                printf(" ");
            if((i + n) <= j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("WELCOME TO SUDOKU SOLVER\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i >= j)
                printf("*");
            else
                printf(" ");
            if(i >= (2 * n - 1) - j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("************************************\n");
    printf("INSTRUCTIONS : \n************************************\nYOUR SUDOKU GRID IS TO BE ENTERED ROWWISE\nPUT SPACE BETWEEN TWO CONSECUTIVE NUMBERS\nSUBSTITUTE 0 AT UNSIGNED PLACES\nONCE ROW IS ENTERED PRESS ENTER TO GO TO NEXT ROW \n");
    printf("************************************\n");
    printf("ENTER SUDOKU : \n");
}
/**
SAMPLE INPUT
3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0**/
