#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dataget/five_dof_kinematic.h"
#include "dataget/MyMatrix.h"
#include "ros/ros.h"
//d1=4
/*               theta,   d,     a,    alpha                     */
float DH[6][4] = {{0,     4,     5,     -PI/2},
	 	  {0,     0,     13, 0},
		  {0,     0,     2, -PI/2},
		  {0,     13,     0,     PI/2},
		  {0,  0,     0,    -PI/2},
		  {0,     10,     0,     0}};

void Init_DH(Input_data DH_para)
{
	DH_para->th1 = DH[0][0];
	DH_para->th2 = DH[1][0];
	DH_para->th3 = DH[2][0];
	DH_para->th4 = DH[3][0];
	DH_para->th5 = DH[4][0];
	DH_para->th6 = DH[5][0];
	//DH_para->th7 = DH[6][0];
	DH_para->d1 = DH[0][1];
	DH_para->d2 = DH[1][1];
	DH_para->d3 = DH[2][1];
	DH_para->d4 = DH[3][1];
	DH_para->d5 = DH[4][1];
	DH_para->d6 = DH[5][1];
	//DH_para->d7 = DH[6][1];
	DH_para->a1 = DH[0][2];
	DH_para->a2 = DH[1][2];
	DH_para->a3 = DH[2][2];
	DH_para->a4 = DH[3][2];
	DH_para->a5 = DH[4][2];
	DH_para->a6 = DH[5][2];
	//DH_para->a7 = DH[6][2];
	DH_para->alp1 = DH[0][3];
	DH_para->alp2 = DH[1][3];
	DH_para->alp3 = DH[2][3];
	DH_para->alp4 = DH[3][3];
	DH_para->alp5 = DH[4][3];
	DH_para->alp6 = DH[5][3];
	//DH_para->alp7 = DH[6][3];
}

// 正運動學推導
Matrix five_dof_fkine(Input_data DH_para, float theta[])
{
	Matrix rst, T1;
	rst = eye(4);
	T1 = Create_Matrix(4, 4);
	float a[7] = {DH_para->a1, DH_para->a2, DH_para->a3, DH_para->a4, DH_para->a5, DH_para->a6, DH_para->a7};
	float d[7] = {DH_para->d1, DH_para->d2, DH_para->d3, DH_para->d4, DH_para->d5, DH_para->d6, DH_para->d7};
	float alp[7] = {DH_para->alp1, DH_para->alp2, DH_para->alp3, DH_para->alp4, DH_para->alp5, DH_para->alp6, DH_para->alp7};
	float th[7] = {theta[0], theta[1], theta[2], theta[3], DH_para->th5, theta[4], DH_para->th7};
	//A1
	T1->data[0][0] = cos(th[0]);
	T1->data[0][1] = 0;
	T1->data[0][2] = -sin(th[0]);
	T1->data[0][3] = a[0] * cos(th[0]);
	T1->data[1][0] = sin(th[0]);
	T1->data[1][1] = 0;
	T1->data[1][2] = cos(th[0]);
	T1->data[1][3] = a[0] * sin(th[0]);
	T1->data[2][0] = 0;
	T1->data[2][1] = -1;
	T1->data[2][2] = 0;
	T1->data[2][3] = d[0];
	T1->data[3][0] = 0;
	T1->data[3][1] = 0;
	T1->data[3][2] = 0;
	T1->data[3][3] = 1;

		//Show_Matrix(Ti);
		//printf("\n");
		// Matrix Mult_Matrix(Matrix mat_1, Matrix mat_2);
	rst = Mult_Matrix(rst, T1);
	//A2
	T1->data[0][0] = cos(th[1]);
        T1->data[0][1] = -sin(th[1]);
        T1->data[0][2] = 0;
        T1->data[0][3] = a[1] * cos(th[1]);
        T1->data[1][0] = sin(th[1]);
        T1->data[1][1] = cos(th[1]);
        T1->data[1][2] = 0;
        T1->data[1][3] = a[1] * sin(th[0]);
        T1->data[2][0] = 0;
        T1->data[2][1] = 0;
        T1->data[2][2] = 1;
        T1->data[2][3] = d[0];
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
	rst = Mult_Matrix(rst,T1);
	//A3
	T1->data[0][0] = cos(th[2]);
        T1->data[0][1] = 0;
        T1->data[0][2] = -sin(th[2]);
        T1->data[0][3] = a[2] * cos(th[2]);
        T1->data[1][0] = sin(th[2]);
        T1->data[1][1] = 0;
        T1->data[1][2] = -cos(th[2]);
        T1->data[1][3] = a[2] * sin(th[2]);
        T1->data[2][0] = 0;
        T1->data[2][1] = -1;
        T1->data[2][2] = 0;
        T1->data[2][3] = 0;
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
	rst = Mult_Matrix(rst,T1);

	//A4
	T1->data[0][0] = cos(th[3]);
        T1->data[0][1] = 0;
        T1->data[0][2] = sin(th[3]);
        T1->data[0][3] = 0;
        T1->data[1][0] = sin(th[3]);
        T1->data[1][1] = 0;
        T1->data[1][2] = -cos(th[3]);
        T1->data[1][3] = a[0] * sin(th[0]);
        T1->data[2][0] = 0;
        T1->data[2][1] = 1;
        T1->data[2][2] = 0;
        T1->data[2][3] = d[3];
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
	rst = Mult_Matrix(rst,T1);

	//A5
	T1->data[0][0] = cos(th[4]);
        T1->data[0][1] = 0;
        T1->data[0][2] = -sin(th[4]);
        T1->data[0][3] = 0;
        T1->data[1][0] = sin(th[4]);
        T1->data[1][1] = 0;
        T1->data[1][2] = cos(th[4]);
        T1->data[1][3] = 0;
        T1->data[2][0] = 0;
        T1->data[2][1] = -1;
        T1->data[2][2] = 0;
        T1->data[2][3] = 0;
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
	rst = Mult_Matrix(rst,T1);

	//A6
	T1->data[0][0] = cos(th[5]);
        T1->data[0][1] = -sin(th[5]);
        T1->data[0][2] = 0;
        T1->data[0][3] = 0;
        T1->data[1][0] = sin(th[5]);
        T1->data[1][1] = cos(th[5]);
        T1->data[1][2] = 0;
        T1->data[1][3] = 0;
        T1->data[2][0] = 0;
        T1->data[2][1] = 0;
        T1->data[2][2] = 1;
        T1->data[2][3] = d[5];
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
        rst = Mult_Matrix(rst,T1);


	return rst;
		//Show_Matrix(rst);
}

Matrix five_dof_ikine(Input_data DH_para, Matrix fk_T)
{
	Matrix ik_T;
	Matrix T1, rst,mat;
	T1 = Create_Matrix(4,4);
	ik_T = Create_Matrix(1,6);
	rst = eye(4);
	//base data
	float a[6] = {DH_para->a1, DH_para->a2, DH_para->a3, DH_para->a4, DH_para->a5, DH_para->a6};
        float d[6] = {DH_para->d1, DH_para->d2, DH_para->d3, DH_para->d4, DH_para->d5, DH_para->d6};
        float alp[6] = {DH_para->alp1, DH_para->alp2, DH_para->alp3, DH_para->alp4, DH_para->alp5, DH_para->alp6};

	//take data down
	float a1 = DH_para->a1;
	float a2 = DH_para->a2;
	float a3 = DH_para->a3;
	float d1 = DH_para->d1;
	float d4 = DH_para->d4;
        float d6 = DH_para->d6;

	float nx, ny, nz;
	float ox, oy, oz;
	float ax, ay, az;
	float px, py, pz;
	//{{nx,ox,ax,px};
	// {ny,oy,ay,py};
	// {nz,oz,az.pz};
	float nx1,ny1,nz1;
	float tx1,ty1,tz1;
	float bx1,by1,bz1;
	float px1,py1,pz1;

	nx = PickInMat(fk_T, 1, 1);
	ny = PickInMat(fk_T, 2, 1);
	nz = PickInMat(fk_T, 3, 1);
	ox = PickInMat(fk_T, 1, 2);
	oy = PickInMat(fk_T, 2, 2);
	oz = PickInMat(fk_T, 3, 2);
	ax = PickInMat(fk_T, 1, 3);
	ay = PickInMat(fk_T, 2, 3);
	az = PickInMat(fk_T, 3, 3);
	px = PickInMat(fk_T, 1, 4);
	py = PickInMat(fk_T, 2, 4);
	pz = PickInMat(fk_T, 3, 4);

	// theta1
	float theta1;
	theta1 = atan2(py - d6*ay, px - d6*ax);
	// theta3;
	float theta3;
	float As;
	float Bs;
	As = px*cos(theta1)-d6*(ax*cos(theta1)+ay*sin(theta1))-a1+py*sin(theta1);
	Bs = d1-pz+d6*az;
	theta3 =acos((pow(As,2)+pow(Bs,2)-pow(a2,2)-pow(a3,2)-pow(d4,2))/(2*a2*sqrt(pow(a3,2)+pow(d4,2))))-atan2(d4,a3);
	
	float check = 0;
	check = asin((sqrt(pow(a3,2)+pow(d4,2))*sin(atan2(d4,a3)+theta3))/sqrt(pow(As,2)+pow(Bs,2)));
	/*if(check > 0){
		check = 3.14159 - check;
	}else{
		check = -(check + 3.14159);
	}*/
	float theta2;
        theta2 = atan2(Bs,As)-check;

	//second part
	float th[3] = {theta1, theta2, theta3};

        //A1
        T1->data[0][0] = cos(th[0]);
        T1->data[0][1] = 0;
        T1->data[0][2] = -sin(th[0]);
        T1->data[0][3] = a[0] * cos(th[0]);
        T1->data[1][0] = sin(th[0]);
        T1->data[1][1] = 0;
        T1->data[1][2] = cos(th[0]);
        T1->data[1][3] = a[0] * sin(th[0]);
        T1->data[2][0] = 0;
        T1->data[2][1] = -1;
        T1->data[2][2] = 0;
        T1->data[2][3] = d[0];
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
        rst = Mult_Matrix(rst, T1);
	  //A2
        T1->data[0][0] = cos(th[1]);
        T1->data[0][1] = -sin(th[1]);
        T1->data[0][2] = 0;
        T1->data[0][3] = a[1] * cos(th[1]);
        T1->data[1][0] = sin(th[1]);
        T1->data[1][1] = cos(th[1]);
        T1->data[1][2] = 0;
        T1->data[1][3] = a[1] * sin(th[0]);
        T1->data[2][0] = 0;
        T1->data[2][1] = 0;
        T1->data[2][2] = 1;
        T1->data[2][3] = 0;
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
        rst = Mult_Matrix(rst,T1);

        //A3
        T1->data[0][0] = cos(th[2]);
        T1->data[0][1] = 0;
        T1->data[0][2] = -sin(th[2]);
        T1->data[0][3] = a[2] * cos(th[2]);
        T1->data[1][0] = sin(th[2]);
        T1->data[1][1] = 0;
        T1->data[1][2] = cos(th[2]);
        T1->data[1][3] = a[2] * sin(th[2]);
        T1->data[2][0] = 0;
        T1->data[2][1] = -1;
        T1->data[2][2] = 0;
        T1->data[2][3] = 0;
        T1->data[3][0] = 0;
        T1->data[3][1] = 0;
        T1->data[3][2] = 0;
        T1->data[3][3] = 1;
        rst = Mult_Matrix(rst,T1);
	//rst = A1*A2*A3
        //inverse rst
        rst = inverse_mat(rst);
        //calculat new data Matrix mat
        mat = Mult_Matrix(rst,fk_T);

	//second ending
	nx1 = PickInMat(mat, 1, 1);
        ny1 = PickInMat(mat, 2, 1);
        nz1 = PickInMat(mat, 3, 1);
        tx1 = PickInMat(mat, 1, 2);
        ty1 = PickInMat(mat, 2, 2);
        tz1 = PickInMat(mat, 3, 2);
        bx1 = PickInMat(mat, 1, 3);
        by1 = PickInMat(mat, 2, 3);
        bz1 = PickInMat(mat, 3, 3);
        px1 = PickInMat(mat, 1, 4);
        py1 = PickInMat(mat, 2, 4);
        pz1 = PickInMat(mat, 3, 4);


	// theta4
	float theta4;
	theta4 = atan2(by1,bx1);

	// theta5
	float theta5;
	theta5 = atan2(-bx1*cos(theta4)-by1*sin(theta4),bz1);

	// theta6
	float theta6;
	theta6 = atan2(nx1*sin(theta4)-ny1*cos(theta4),tz1*sin(theta4)-ty1*cos(theta4));
	float the[6] = {theta1,theta2,theta3,theta4,theta5,theta6};
	SetData_Matrix(ik_T, the);
	return ik_T;
}
