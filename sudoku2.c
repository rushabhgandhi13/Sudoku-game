#include <stdio.h>
void horizontal_line()
{
    int x;
    printf("|");
    for(x=0; x<29; x++)
        printf("-");
    printf("| ");
    printf("\n");
}
void grid_print(int a[9][9])
{ int i,j;// i is the row no. and j is the column no.
    for(i=0; i<9; i++)
    {if(i%3==0)
        horizontal_line();
        for(j=0; j<9; j++)
        {
            if(j%3==0)
                printf("|");
            printf(" %d ",a[i][j]);
            if(j==8)
                printf("|");

        }
        printf("\n");
        if(i==8)
            horizontal_line();
    }
}
int main()
{
    int a[9][9];
    printf("Enter the suduko grid, enter 0 for blank spaces\n");
    int i,j; // i is the row no and j is the column no
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            scanf("%d",&a[i][j]);
    printf("The grid that you have entered is:\n");
    grid_print(a);
}


