#include <stdio.h>
#include <math.h>

int main(void){
	int i;
	double rika[]={};
	double eng[]={};
	int n = sizeof(rika)/sizeof(double);
	int m = sizeof(eng)/sizeof(double);
	int count = 0;
	double avg, avg2, dev, dev2, sum, sum2, sum3, sum4, max, min, max2, min2;
	sum = 0.0;
	sum2 = 0.0;

	for(i = 0;i < n;i++){
		sum += rika[i];
		sum2 += eng[i];
		sum3 += rika[i]*rika[i];
		sum4 += eng[i]*eng[i];
	}
	avg = sum/n;
	avg2 = sum2/n;
	dev = sqrt(sum3/n-avg*avg);
	dev2 = sqrt(sum4/n-avg2*avg2);

	printf("理科合計 = %f 英語合計 = %f 理科平均 = %f 英語平均 = %f 理科偏a = %f 英語偏差 = %d", sum, sum2, avg, avg2, dev, dev2);
	return 0;
}
