#ifndef HEADER_MYMATRIX_H_
#define HEADER_MYMATRIX_H_
#include <ros/ros.h>
typedef struct MNode *PtrToMNode;
struct MNode
{
	int row;
	int column;
	float **data;
};
typedef PtrToMNode Matrix;
// 創建一個矩陣
Matrix Create_Matrix(int row, int column);
// 初始化矩陣
void Init_Matrix(Matrix mat);
// 給矩陣每個元素賦值
void SetData_Matrix(Matrix mat, float data[]);
// 打印矩陣
void Show_Matrix(Matrix mat);
// 矩陣加減法
Matrix AddorSub_Matrix(Matrix mat_1, Matrix mat_2, int flag);
// 轉置
Matrix Trans_Matrix(Matrix mat);
// 矩陣乘法
Matrix Mult_Matrix(Matrix mat_1, Matrix mat_2);
// 單位矩陣
Matrix eye(int n);
// 取出矩陣某行某列的元素
float PickInMat(Matrix mat, int r, int c);
// inverse matrix
Matrix inverse_mat(Matrix mat);

#endif /* HEADER_MYMATRIX_H_ */

