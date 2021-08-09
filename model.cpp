/*
 * model.cpp
 *
 *  Created on: Aug 8, 2021
 *      Author: ahmed
 */


#include <iostream>
#include <cmath>

using namespace std;

float beta = 0;
float theta_dot = 0;
float theta = 0;
float theta_dot_prev = 0;
float lr = 0.5;
float l = 1;
float sample_time = 0.5;
float count = 0;
float input[3]={5,5,3.14/30};
float output[3];
float x_cg_dot = 0;
float y_cg_dot = 0;


void model(void)
{
	for (int i =0 ; i<201 ; i++)
	{

		beta=atan(   (  lr*(tan(input[2])/l)  )  );
		x_cg_dot=input[0]*cos(theta+beta);
		y_cg_dot=input[0]*sin(theta+beta);
		theta_dot=input[0]*cos(beta)*tan(input[2])/l;
		output[0]+=x_cg_dot*sample_time;
		output[1]+=y_cg_dot*sample_time;
		theta+=theta_dot*sample_time;
		output[2]=theta;
	    output[2]=remainder(theta,2*3.14);
		cout<<"(x = "<<output[0]<<"\t"<< ", y = " <<output[1]<<"\t"<< ", theta= "<<output[2]<<")"<<endl;
	}
}

int main(void)
{
	model();

}

