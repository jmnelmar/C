#include "sandpiles.h"
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]){
    int check_print = check_zero_grid( grid1, grid2 );
    //printf("%i\n",check_print);
    int i, j;
    for ( i =0; i<3; i++){
        for( j=0; j<3; j++ ){
            grid1[i][j] = grid1[i][j] + grid2[i][j];

        }
    }

    if( check_print > 0 )
        print_grid( grid1 );
    
    //copy_arr(grid1, copy); 
    
    toppling_v2( grid1 );

}

int check_zero_grid( int grid1[3][3], int grid2[3][3]){
    int sum1, sum2, i, j;
    sum1 = 0;
    sum2 = 0;

    for ( i=0; i<3; i++){
        for ( j=0; j<3; j++){
            sum1 = sum1 + grid1[i][j];
            sum2 = sum2 + grid2[i][j];
        }
    }

    //printf("%i\n",sum1);
    //printf("%i\n",sum2);

    if( sum1 == 0 || sum2 == 0 )
        return 0;

    return 1;
}

void toppling_v2( int grid[3][3]){
    
    int i,j;

    int copy[3][3] ={ {0,0,0}, {0,0,0}, {0,0,0} };

    copy_arr(grid, copy); 

    for ( i = 0; i<3; i++){
        
        for( j=0; j<3; j++){
            if( copy[i][j] > 3 ){
                grid[i][j] = grid[i][j] - 4;
                
                /*top*/
                if( i > 0){
                    grid[i-1][j] = grid[i-1][j] + 1;
                    
                }
                
                /*right*/
                if( j < 2  ){
                    grid[i][j+1] = grid[i][j+1] + 1;
                    
                }
                
                /*down*/
                if( i < 2 ){
                    grid[i+1][j] = grid[i+1][j] + 1;
                }
                
                /*left*/
                if( j > 0 ){
                    grid[i][j-1] = grid[i][j-1] + 1;
                }
            }
        }
    }

    copy_arr(grid, copy);
    check_grid( grid );

}

void copy_arr(int grid[3][3], int copy[3][3]){
    int i,j;   
    for ( i=0; i<3; i++){
        for (j=0; j<3; j++){
            copy[i][j] = grid[i][j];
        }
    }


    //return result;
}

void check_grid( int grid[3][3] ){

    int i,j;

    for ( i = 0; i < 3; i++ ){
        for ( j = 0; j < 3; j++){
            if( grid[i][j] > 3 ){
                print_grid(grid);
                toppling_v2(grid);

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