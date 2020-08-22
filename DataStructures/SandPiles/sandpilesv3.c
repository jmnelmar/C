#include "sandpiles.h"
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]){
    //int grid3[3][3];

    int i, j;
    for ( i =0; i<3; i++){
        for( j=0; j<3; j++ ){
            grid1[i][j] = grid1[i][j] + grid2[i][j];

        }
    }
    print_grid( grid1 );
    toppling( grid1 );

}


void toppling(int grid[3][3]){
    
    /*center 1*/
    if(  grid[1][1] > 3 ){
        grid[1][1] = grid[1][1] - 4;
        grid[1][0] = grid[1][0] + 1;
        grid[0][1] = grid[0][1] + 1;
        grid[1][2] = grid[1][2] + 1;
        grid[2][1] = grid[2][1] + 1;
    }
    //print_grid(grid);
    /*middle-top 1*/
    if( grid[0][1] > 3 ){
        grid[0][1] = grid[0][1] - 4;
        grid[0][0] = grid[0][0] + 1;
        grid[0][2] = grid[0][2] + 1;
        grid[1][1] = grid[1][1] + 1;
    }
    //print_grid(grid);
    /*middle-right 1*/
    if( grid[1][2] > 3 ){
        grid[1][2] = grid[1][2] - 4;
        grid[0][2] = grid[0][2] + 1;
        grid[1][1] = grid[1][1] + 1;
        grid[2][2] = grid[2][2] + 1;
    }
    //print_grid(grid);
    /*middle-bottom 1*/
    if( grid[2][1] > 3 ){
        grid[2][1] = grid[2][1] - 4;
        grid[2][2] = grid[2][2] + 1;
        grid[1][1] = grid[1][1] + 1;
        grid[2][0] = grid[2][0] + 1;
    }
    //print_grid(grid);
    /*middle-left 1*/
    if( grid[1][0] > 3 ){
        grid[1][0] = grid[1][0] - 4;
        grid[0][0] = grid[0][0] + 1;
        grid[1][1] = grid[1][1] + 1;
        grid[2][0] = grid[2][0] + 1;
    }
    //print_grid(grid);
    /*left-upper-corner 1*/
    if( grid[0][0] > 3 ){
        grid[0][0] = grid[0][0] - 4;
        grid[0][1] = grid[0][1] + 1;
        grid[1][0] = grid[1][0] + 1;
    }
    //print_grid(grid);
    /*right-upper-corner*/
    if( grid[0][2] > 3 ){
        grid[0][2] = grid[0][2] - 4;
        grid[0][1] = grid[0][1] + 1;
        grid[1][2] = grid[1][2] + 1;
    }
    //print_grid(grid);
    /*right-bottom-corner*/
    if( grid[2][2] > 3 ){
        grid[2][2] = grid[2][2] - 4;
        grid[1][2] = grid[1][2] + 1;
        grid[2][1] = grid[2][1] + 1;
    }
    //print_grid(grid);
    /*left-bottom-corner*/
    if( grid[2][0] > 3 ){
        grid[2][0] = grid[2][0] - 4;
        grid[1][0] = grid[1][0] + 1;
        grid[2][1] = grid[2][1] + 1;
    }
    //print_grid(grid);

    check_grid( grid );
}

void check_grid( int grid[3][3] ){

    int i,j;

    for ( i = 0; i < 3; i++ ){
        for ( j = 0; j < 3; j++){
            if( grid[i][j] > 3 ){
                print_grid(grid);
                toppling( grid );

            }                
        }
    }
        

}


static void print_grid(int grid[3][3])
{
    int i, j;
    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

