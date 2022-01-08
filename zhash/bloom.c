#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Malloc(p,n) \
	if(!((p) = malloc(sizeof(*(p))*(n)))){\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

/*
By differentiating P(u) with respect to h, show that is minimized when h = ln(2)m/u.
( Write a program to validate the result shown in the problem by investigating P(u) with various h's. )
*/


// fixed integer const
double u = 10.0, m = 10.0 , n = 10.0;

double P(double u, double h){
 double a = pow((1.0 - 1.0/n),u);
 double b = 1.0 - pow( (1.0 - 1.0/m),u * h) ;
 return a * pow(b,h); 
}

double diff_P(double u, double h){
  double a = P(u,h);
  double b = 1.0 - pow( (1.0 - 1.0/h),u * h) ;
  double c = 1.0 ; //- pow( (1.0 - 1.0/m),u * h);
  double d = u * log(1.0 - 1.0/m);
  printf("\n%lf %lf %lf %lf \n",a,log(b),c,d);
  return a * log(b) * c * d;
}

// explicit form not needed ?

int main(void){
 
  // variable h
  // double hs[] = {3.0, 4.0 , 6.0, 8.0, 9.0};
  double hs[] = {0.5, 0.6 ,0.7, 0.8, 0.9};
  int len = 5;
  // differentiation
  double step = 0.000001;

  int i;

  double P_u;
  for(i = 0 ; i < len; i++){
    P_u = P(u,hs[i]); 
    printf("h = %lf\nP(u) = %lf\nuse finite difference: P'(u) = %lf\n",hs[i], P_u, (P(u+step,hs[i]) - P_u)/step);  
    //printf("use explicit form: %lf\n", diff_P(u, hs[i]));
    //printf("\n");
  }

  return 0;
}

