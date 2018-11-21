#include <stdio.h>
#include <math.h>
#define MAX 1000
double d[MAX];

void quick_sort(int le, int ri){
	int i, j, k;
	double pivot, tmp;
	if(le==ri){
		return;
	}
	k = (le + ri)/2;
	pivot = d[k];
	i = le;
	j = ri;
	while(i <= j){
		while(d[i] < pivot){
			i++;
		}
		while(d[j] > pivot){
			j--;
		}
		if(i>=j){
			break;
		}
		tmp = d[i];
		d[i] = d[j];
		d[j] = tmp;
		i++;
		j--;
	}
	if(le < i-1){
		quick_sort(le, i-1);
	}
	if(ri > j+1){
		quick_sort(j+1, ri);
	}
}
int main(void){
	int i;
	double rika[20]={65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70};
	double eng[20]={44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};
	int n = sizeof(rika)/sizeof(double);
	int m = sizeof(eng)/sizeof(double);
	int count = 0;
	double avg, avg2, dev, dev2, sum, sum2, sum3, sum4, max, min, max2, min2;
	double hensar[20] = {0.0};
	double hensae[20] = {0.0};
	sum = 0.0;
	sum2 = 0.0;
	sum3 = 0.0;
	sum4 = 0.0;
	avg = 0.0;
	avg2 = 0.0;
	dev = 0.0;
	dev2 = 0.0;
	
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
	printf("理科合計 = %f 英語合計 = %f\n", sum, sum2);
	printf("理科平均 = %f 英語平均 = %f\n", avg, avg2);
	printf("理科偏差 = %f 英語偏差 = %f\n", dev, dev2);
	for(i=0;i<n;i++){
		hensar[i] = (10.0*(rika[i] - avg)/dev) + 50.0;
		hensae[i] = (10.0*(eng[i] - avg2)/dev2) + 50.0;
	}
	for(i=0;i<n;i++){
		printf("理科偏差値[%d人目]: %f\n", i+1, hensar[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("英語偏差値[%d人目]: %f\n", i+1, hensae[i]);
	}
	
	printf("理科点数(降順): ");
	for(i = 0;i<n;i++){
		d[i]=rika[i];
	}
	quick_sort(0, 20);
	for(i=n;i>1;i--){
		printf("%f, ", d[i]);
	}
	printf("%f \n\n", d[1]);

	printf("英語点数(降順): ");
	for(i = 0;i<n;i++){
		d[i]=eng[i];
	}
	quick_sort(0, 20);
	for(i=n;i>1;i--){
		printf("%f, ", d[i]);
	}
	printf("%f \n\n", d[1]);
	return 0;
}
