#include <stdio.h>
#include <stdlib.h>
int h[101] = {0,99,5,36,7,22,17,46,12,2,19,25,28,1,92};
int n =14;    // numbers in the heap
int num =14;

void swap (int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}

void siftdown(int i)
{
	int t, flag = 0;  				// using flag to track whether to move down 
	while (i*2 <=n && flag ==0)
	{
		if (h[i] > h[i*2]) {t = i*2;}
		else {t = i;}
	
		if (i*2+1 <= n)
		{
			if (h[t] > h[i*2+1]){ t= i*2+1;}	
		}
		if (t != i){swap(t,i);i=t;}
		else {flag =1;}
	}
}

void siftup(int i)
{
	int flag =0;
	if(i==1) {return;}
	while (i != 1 && flag ==0)
	{
		if (h[i]<h[i/2]){swap(i,i/2);}
		else {flag =1;}
		i = i/2;
	}
}

void creat()
{
	int i;
	for (i = n/2 ; i>=1; i--){
		siftdown(i);
	}
}

int deletemax()
{
	int t;
	t = h[1];
	h[1]=h[n];
	n--;
	siftdown(1);
	return t;
}

int main()
{
	int i;
	n=num;
	for (i=1;i<=num;i++){
		printf("%d ",h[i]);
	}
	printf("\n");
	
	creat();
	for (i=1;i<=num;i++){
		printf("%d ",h[i]);
	}
	printf("\n");

	for (i=1;i<=num;i++){
		printf("%d ",deletemax());
	}
	getchar();
	getchar();
	return 0;
}