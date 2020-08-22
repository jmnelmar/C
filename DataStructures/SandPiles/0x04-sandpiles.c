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
    int i,j;
    
    for ( i = 0; i<3; i++){
        printf("\tIteration:%i\n",i);
        for( j=0; j<3; j++){
            if( grid[i][j] > 3 ){
                grid[i][j] = grid[i][j] - 4;
                printf("\t\tgrid[%i][%i]:%i\n",i,j,grid[i][j]);
                /*Actualizar top, right, down, left*/

                /*top*/
                if( i > 0){
                    //printf("\t\tgrid[%i-1][%i]:%i\n",i,j,grid[i-1][j]);
                    grid[i-1][j] = grid[i-1][j] + 1;
                    printf("\t\tgrid[%i-1][%i]:%i\n",i,j,grid[i-1][j]);
                }
                    

                /*right*/
                if( j < 2  ){
                    //printf("\t\tgrid[%i][%i+1]:%i\n",i,j,grid[i][j+1]);
                    grid[i][j+1] = grid[i][j+1] + 1;
                    printf("\t\tgrid[%i][%i+1]:%i\n",i,j,grid[i][j+1]);
                }
                    

                /*down*/
                if( i < 2 ){
                    //printf("\t\tgrid[%i+1][%i]:%i\n",i,j,grid[i+1][j]);
                    grid[i+1][j] = grid[i+1][j] + 1;
                    printf("\t\tgrid[%i+1][%i]:%i\n",i,j,grid[i+1][j]);
                }
                    

                /*left*/
                if( j > 0 ){
                    //printf("\t\tgrid[%i][%i-1]:%i\n",i,j,grid[i][j-1]);
                    grid[i][j-1] = grid[i][j-1] + 1;
                    printf("\t\tgrid[%i][%i-1]:%i\n",i,j,grid[i][j-1]);
                }
                
                //toppling(grid);
                //printf("----,position grid[%i][%i]:%i, target grid[1,0]: %i\n",i,j,grid[i][j],grid[1][0]);
            }
        }
        //print_grid(grid);
    }

    /*print_grid ( grid );*/
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

