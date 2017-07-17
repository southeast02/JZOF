#include <stdio.h>
#include <math.h>

#define N 256


int ABNORMAL_INPUT=0;

double pow_1(double base, int exponent);
double _compute_pow(double base, int exponent);
int almost_equals(double a, double b);


int main(){
	double base = 4;
	int exponent = 2;

	printf("%.2lf ** %d =  %.2lf\n", base, exponent,pow_1(base,exponent));
	return 0;
}



double pow_1(double base, int exponent){
	// if base==0 and exponent<0, then it's invalid input
	// if base==0 and exponent>=0, then return 1 is not a fault.
	double result;
	int abs_exponent = exponent;

	if(almost_equals(base, 0.0) && exponent<0){
		ABNORMAL_INPUT=1;
		return 0;
	}


	if(exponent < 0){
		abs_exponent = -exponent;
	}

	result = _compute_pow(base, abs_exponent);
	if(exponent < 0){
		return 1.0/result;
	}
	return result;
}

double _compute_pow(double base, int exponent){
	// exponent=0, return 0
	// exponent=1, return base

	double result = 1.0;
	for(int i=1; i<=exponent; i++){
		result *= base;
	}
	return result;
}

int almost_equals(double a, double b){
	double max_distance = 0.0000001;
	if(!isnan(a) || !isnan(b)){
		return 0;
	}
	return fabs(a-b) <= max_distance;
}

/**
 * output:
 * 4.00 ** 2 =  16.00
 *
 * */
