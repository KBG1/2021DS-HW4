#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [Kim Beom Gyu]  [2019062022] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");

    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;}

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Matrix Manipulation                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Matrix   = z           Print Matrix        = p \n");
		printf(" Add Matrix          = a           Subtract Matrix     = s \n");
		printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
		printf(" Quit                = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
		    printf("Matrix Initialized\n");
			fill_data(matrix_a, row, col);
			fill_data(matrix_b, row, col);
			break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
			print_matrix(matrix_a, row, col);
			printf("matrix_b\n");
			print_matrix(matrix_b, row, col);
			break;
        case 'a': case 'A':
			printf("Add two matrices\n");
			addition_matrix(matrix_a, matrix_b, row, col);
			break;
        case 's': case 'S':
			printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
			break;
        case 't': case 'T':
			printf("Transpose matrix_a \n");
			printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
			break;
        case 'm': case 'M':
			printf("Multiply matrix_a with transposed matrix_a \n");
			
			transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
			break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{   if(row <= 0 || col <= 0){
        printf("The matrix is incorrect");  //????????? 0??? ??? ????????? ???????????? ????????? ???????????? ???????????? ??????
        return NULL;
    }

    int** matrix = (int**)malloc(sizeof(int*) * row); //?????? ?????? ????????? ??????
    for (int k = 0; k < row; k++){
        matrix[k] = (int*)malloc(sizeof(int) * col); //?????? ?????? ????????? ??????
    }

    if (matrix == NULL){
        printf("Memory allocation failure"); //????????? ???????????? ????????? ????????? ?????? ?????? ????????? ??????
        return NULL;
    }
    return matrix;
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{   if(row <= 0 || col <= 0){
        printf("The matrix is incorrect");
        return;
    }
    for(int i=0; i< row; i++){
        for(int j=0; j < col ; j++){
            printf("%3d", matrix[i][j]); //????????? ????????? ??? ??????
        }
        printf("\n");
    }
    if (matrix == NULL){
        printf("Memory allocation Failure");
    return;
    }

    return;
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    if (row <= 0 || col <= 0) {
	    printf("The matrix is incorrect");
		return -1;
	}

	for (int i = 0; i < row; i++) {
		free(matrix[i]);                 //?????? ????????? ????????? ??????/??????
	}

	free(matrix); //?????? ????????? ????????? ??????/??????
	return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{   int i,j = 0;
    if(row <= 0 || col <= 0){
        printf("The matrix is incorrect");
        return -1;
    }
    
    for(i=0; i< row; i++){
        for(j=0; j < col ; j++){
            matrix[i][j] = rand() % 20;  //0~19??? ?????? ???????????? ????????? ???????????? ?????? ??????
        }
    }

    if (matrix == NULL){
        printf("Memory allocation failure");
        return -1;
    }

    return 1;

}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{   int** matrix_sum = create_matrix(row,col);
    if(row <= 0 || col <= 0){
        printf("The matrix is incorrect");
        return -1;
    }
    
    for(int i=0; i< row; i++){
        for(int j=0; j < col ; j++){
            matrix_sum = matrix_a[i][j] + matrix_b[i][j]; //??? ???,?????? ?????? ??? ??????
        }
    }

    if (matrix_a == NULL || matrix_b == NULL || matrix_sum == NULL){
        printf("Memory allocation failure");
        return -1;
    }
    print_matrix(matrix_sum,row,col); //??? ??????
    free_matrix(matrix_sum, row, col); //????????? ??????
    return 1;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_sub = create_matrix(row,col);
    if(row <= 0 || col <= 0){
        printf("The matrix is incorrect");
        return -1;
    }
    
    for(int i=0; i< row; i++){
        for(int j=0; j < col ; j++){
            matrix_sub = matrix_a[i][j] - matrix_b[i][j];  //??? ???,?????? ?????? ????????? ???
        }
    }

    if (matrix_a == NULL || matrix_b == NULL || matrix_sub == NULL){
        printf("Memory allocation failure");
        return -1;
    }
    print_matrix(matrix_sub,row,col); //??? ??????
    free_matrix(matrix_sub, row, col); //????????? ??????
    return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    if(row <= 0 || col <= 0){
        printf("The matrix is incorrect");
        return -1;
    }
    
    for(int i=0; i< row; i++){
        for(int j=0; j < col ; j++){
            matrix_t[i][j] = matrix[j][i];    //?????? ?????? ???????????? matrix_t??? ??????
        }
    }

    if (matrix == NULL || matrix_t == NULL){
        printf("Memory allocation failure");
        return -1;
    }
    return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    int** matrix_axt = create_matrix(row, row);
	if (row <= 0 || col <= 0) {
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int i = 0; i < row; i++) {
		for (int i_t = 0; i_t < row; i_t++) {
			int temp = 0;
			for (int j = 0; j < col; j++)
				temp += matrix_a[i][j] * matrix_t[j][i_t];  //??????????????? ?????? ????????? ?????????
			matrix_axt[i][i_t] = temp;
		}
	}
	
    if (matrix_t == NULL || matrix_axt ==NULL) {
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	print_matrix(matrix_axt, row, row); //??? ??????
	free_matrix(matrix_axt, row, col); //????????? ??????
	return 1;
}
