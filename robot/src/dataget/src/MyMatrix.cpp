#include "dataget/MyMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Init_Matrix(Matrix mat)
{
	int i, j;
	for (i = 0; i < mat->row; i++){
		for (j = 0; j < mat->column; j++){
			mat->data[i][j] = 0;
		}
	}
}

Matrix Create_Matrix(int row, int col)
{
	Matrix mat;
	mat = (Matrix)malloc(sizeof(struct MNode));
	if (row <= 0 || col <= 0){
		printf("ERROR, in creat_Matrix the row or col <= 0\n");
		exit(1);
	}
	if (row > 0 && col >0){
		mat->row = row;
		mat->column = col;
		mat->data = (float **)malloc(row*sizeof(float *));
		if (mat->data == NULL){
			printf("ERROR, in creat_Matrix the mat->data == NULL\n");
			exit(1);
		}
		int i;
		for (i = 0; i < row; i++ ){
			*(mat->data + i) = (float *)malloc(col*sizeof(float));
			if (mat->data[i] == NULL){
				printf("ERROR, in create_Matrix the mat->data[i] == NULL\n");
				exit(1);
			}
		}
		Init_Matrix(mat);
	}
	return mat;
}

void Show_Matrix(Matrix mat)
{
	int i, j;
	for (i = 0; i < mat->row; i++){
		for (j = 0; j < mat->column; j++)
			printf("%.6f\t", mat->data[i][j]);
		printf("\n");
	}
}

void SetData_Matrix(Matrix mat, float data[])
{
	int i, j;
	for (i = 0; i < mat->row; i++){
		for (j = 0; j < mat->column; j++){
			mat->data[i][j] = data[i*mat->column + j];
		}
	}
}

//flag = 0, add; flag = 1, sub
Matrix AddorSub_Matrix(Matrix mat_1, Matrix mat_2, int flag)
{
	Matrix rst_mat;
	if (mat_1->column != mat_2->column){
		printf("ERROR in AddorSub, column !=\n");
		exit(1);
	}
	if (mat_1->row != mat_2->row){
		printf("ERROR in AddorSub, row !=\n");
		exit(1);
	}
	int i, j;
	rst_mat = Create_Matrix(mat_1->row, mat_1->column);
	for (i = 0; i < mat_1->row; i++){
		for (j = 0; j < mat_1->column; j++)
			rst_mat->data[i][j] = mat_1->data[i][j] + pow(-1, flag)*mat_2->data[i][j];
	}
	return rst_mat;
}

//轉置
Matrix Trans_Matrix(Matrix mat)
{
	Matrix mat_;
	int i, j;
	mat_ = Create_Matrix(mat->row, mat->column);
	for (i = 0; i < mat->row; i ++){
		for (j = 0; j < mat->column; j++)
			mat_->data[i][j] = mat->data[i][j];
	}
	return mat_;
}

Matrix Mult_Matrix(Matrix mat_1, Matrix mat_2)
{
	Matrix rst_mat;
	int i, j, m;
	if (mat_1->column != mat_2->row){
		printf("ERROR in Mult_Matrix, column != row\n");
		exit(1);
	}else{
		rst_mat = Create_Matrix(mat_1->row, mat_2->column);
		for (i = 0; i < mat_1->row; i++){
			for (j = 0; j < mat_2->column; j++){
				for (m = 0; m < mat_1->column; m++)
					rst_mat->data[i][j] += mat_1->data[i][m] * mat_2->data[m][j];
			}
		}
	}
	return rst_mat;
}

Matrix eye(int n)
{
	Matrix E;
	int i, j;
	if (n <= 0){
		printf("ERROR in eye\n");
		exit(1);
	}
	E = Create_Matrix(n, n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i == j)
				E->data[i][j] = 1;
			else
				E->data[i][j] = 0;
		}
	}
	return E;
}

float PickInMat(Matrix mat, int r, int c)
{
	float rst;
	rst = mat->data[r - 1][c - 1];
	return rst;
}

Matrix inverse_mat(Matrix mat)
{
	float E_Matrix[4][4];
	float mik;
	Matrix mat_in;
	mat_in = Create_Matrix(mat->row,mat->column);
	/*for (int i = 0; i < mat->row; i++){
                for (int j = 0; j < mat->column; j++){
                        mat_in->data[i][j] = mat->data[i][j];
                }
        }*/

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(i == j)
				E_Matrix[i][j] = 1.00;
			else
				E_Matrix[i][j] = 0.00;
		}
	}
	float CalcuMatrix[4][8];
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			CalcuMatrix[i][j] = mat->data[i][j];
		}
		for(int k = 4; k < 8; k++)
		{
			CalcuMatrix[i][k] = E_Matrix[i][k-4];
		}
	}

	for(int i = 1; i <= 4-1; i++)
	{
		for(int j = i+1; j <= 4; j++)
		{
			mik = CalcuMatrix[j-1][i-1]/CalcuMatrix[i-1][i-1];
			for(int k = i+1;k <= 8; k++)
			{
				CalcuMatrix[j-1][k-1] -= mik*CalcuMatrix[i-1][k-1];
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		float temp = CalcuMatrix[i-1][i-1];
		for(int j=1;j<=8;j++)
		{
			CalcuMatrix[i-1][j-1] = CalcuMatrix[i-1][j-1]/temp;
		}
	}
	for(int k=4-1;k>=1;k--)
	{
		for(int i=k;i>=1;i--)
		{
			mik = CalcuMatrix[i-1][k];
			for(int j=k+1;j<=8;j++)
			{
				CalcuMatrix[i-1][j-1] -= mik*CalcuMatrix[k][j-1];
			}
		}
	}
	float InverseMatrix[4][4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			InverseMatrix[i][j] = CalcuMatrix[i][j+4];
		}
	}

	Matrix Result;
	Result = Create_Matrix(mat->row,mat->column);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(fabs(InverseMatrix[i][j]) < 0.0000001)
				InverseMatrix[i][j] = 0.00;
			Result->data[i][j] = InverseMatrix[i][j];
		}
	}
	return Result;
}
