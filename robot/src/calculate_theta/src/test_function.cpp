#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dataget/five_dof_kinematic.h"
#include "dataget/MyMatrix.h"
#include <ros/ros.h>

int main()
{
	Matrix fk_T, r_t , Ry , Rz , Rx, T,ik_T ;

        T = Create_Matrix(3,1);
        fk_T = Create_Matrix(3,3);
        r_t = Create_Matrix(4,4);
        //Rx * Ry *Rz
        Ry = Create_Matrix(3,3);
        Rx = Create_Matrix(3,3);
        Rz = Create_Matrix(3,3);
        float theta_x[] = {1,0,0,0,-1,0,0,0,-1};
        float theta_y[] = {-1,0,0,0,1,0,0,0,-1};
        float theta_z[] = {1,0,0,0,1,0,0,0,1};
        SetData_Matrix(Ry,theta_y);
        SetData_Matrix(Rz,theta_z);
        SetData_Matrix(Rx,theta_x);
	Show_Matrix(Ry);
	fk_T = Mult_Matrix(Ry,Rx);
        fk_T = Mult_Matrix(fk_T,Rz);
	Show_Matrix(fk_T);
	 float catch_data[16]={0};

        catch_data[0] = PickInMat(fk_T,1,1);
        /*catch_data[1] = PickInMat(fk_T,0,1);
        catch_data[2] = PickInMat(fk_T,0,2);
        catch_data[3] = PickInMat(fk_T,1,0);
        catch_data[4] = PickInMat(fk_T,1,1);
        catch_data[5] = PickInMat(fk_T,1,2);
        catch_data[6] = PickInMat(fk_T,2,0);
        catch_data[7] = PickInMat(fk_T,2,1);
        catch_data[8] = PickInMat(fk_T,2,2);
        catch_data[10] = 0;
        catch_data[11] = -15;
        catch_data[12] = 0;
        catch_data[13] = 0;
        catch_data[14] = 0;
        catch_data[15] = 1;
	catch_data[9] = 8;
	SetData_Matrix(r_t,catch_data);*/


}
