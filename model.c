/*
 * 
 * Hüseyin Yılmaz
 * 
 * 18120205020
 * 
 * model.c
 * provides the grid (model) 
 * and functions to handle the grid for the game of life
 */

#include "gameoflife.h"
int grid[M][N] = {0}; 	/*M and N are constants defined in gameOfLife.h*/

/**
 * initializes the grid with the chosen initial state
 */
int initGrid(int initialState){

	
	if(initialState == 1){
		int x = 4;
		int y = 4;
		
		while(y<50){
			
			grid[x][y] = 1;
			grid[x+1][y] = 1;
			grid[x+2][y] = 1;
			
			x = x+10;
			y = y+10;
		}	
	} 
		
	else if(initialState == 2){
		
		int x = 5;
		int y = 7;
		
		while(y<50){
		
			grid[x][y] = 1;
			grid[x+1][y] = 1;
			grid[x+2][y] = 1;
			grid[x+2][y-1] = 1;
			grid[x+1][y-2] = 1;
			
			x = x+10;
			y = y+10;
		}
	}
		return 0;
}	

/**
 * returns the number of live neighbors of the cell
 * at position (x, y) on the grid
 */
int getNumberOfLiveNeighbors(int x, int y){
	
	int neighbors = 0;
    for (int i = x-1; i <= x+1; i++){
        for(int j = y-1; j <= y+1; j++){
                          
            if(!(i == x && j == y) && (i<= M) && (j<=N) && (i>=0) && (j>=0)){
                if (grid[i][j] == 1){
                    neighbors++;    
                }
            }
        }
    }
	return neighbors;
} 


/**
 * updates each cell by following the update rules of the game of life
 */
int updateGrid(){
	
	int neighbor[M][N] = {0};
		
	for(int x=0;x<M;x++){
		for(int y=0;y<N;y++){
			neighbor[x][y] = getNumberOfLiveNeighbors(x,y);
		}
	}

	for(int a=0; a<M; a++){
		for(int b = 0; b<N; b++){
		
	if(grid[a][b] == 1){
		
		if(neighbor[a][b] == 1 || neighbor[a][b] == 0 || neighbor[a][b] > 3){ 
			
			grid[a][b] = 0;
		}
		
		else if(neighbor[a][b] == 2 || neighbor[a][b] == 3){
			
			grid[a][b] = 1;
		}		
	}
	
	else if(grid[a][b] == 0){
		
		if(neighbor[a][b] == 3){
			
			grid[a][b] = 1;			

				}
			}				
		}	
	}
	return 0;
} 
