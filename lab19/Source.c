#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int a[1000], b[1000];
int n;
int *pa;

void main() 
{
	FILE* fout;
	FILE* fin;
	int sum = 0;
	float srAr;
	int kk, mx;

	/*fin = fopen("in1.txt", "rt");
	if (fin == NULL) 
	{
		printf("read error");
		return;
	}
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fin, "%d", &a[i]);
	}
	fclose(fin);

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	srAr = (float)sum  / n;

	kk = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > srAr)
		{
			b[kk] = a[i];
			kk++;
		}
	}
	fout = fopen("out1.txt", "wt");
	if (fout == NULL)
	{
		printf("write error");
		return;
	}
	fprintf(fout, "%d\n", kk);
	for (int i = 0; i < kk; i++)
	{
		fprintf(fout, "%d ", b[i]);
	}
	fclose(fout);*/




	/*fin = fopen("in1.txt", "rt");	     //2 задание
	if (fin == NULL)
	{
		printf("read error");
		return;
	}
	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);

	for (int i = 0; i < n; i++)
	{
		sum += pa[i];
	}

	srAr = (float)sum / n;

	kk = 0;
	for (int i = 0; i < n; i++)
	{
		if (pa[i] > srAr)
		{
			b[kk] = pa[i];
			kk++;
		}
	}
	fout = fopen("out1.txt", "wt");
	if (fout == NULL)
	{
		printf("write error");
		return;
	}
	fprintf(fout, "%d\n", kk);
	for (int i = 0; i < kk; i++)
	{
		fprintf(fout, "%d ", b[i]);
	}
	fclose(fout);
	free(pa);*/

	/*fin = fopen("in3.txt", "rt"); // задача 3
	if (fin == NULL)
	{
		printf("read error");
		return;
	}
	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);

	for (int i = 0; i < n; i++)
	{
		sum += pa[i];
	}

	srAr = (float)sum / n;

	kk = 0;
	for (int i = 0; i < n; i++)
	{
		if (pa[i] < srAr && pa[i] > 0)
		{
			kk++;
		}
	}
	fout = fopen("out3.txt", "wt");
	if (fout == NULL)
	{
		printf("write error");
		return;
	}
	fprintf(fout, "%d\n", kk);
	for (int i = 0; i < n; i++)
	{
		if (pa[i] < srAr && pa[i] > 0)
		{
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
	free(pa);*/


fin = fopen("in4.txt", "rt"); // задача 4
if (fin == NULL)
{
	printf("read error");
	return;
}
fscanf(fin, "%d", &n);

pa = (int*)malloc(sizeof(int) * n);

for (int i = 0; i < n; i++)
{
	fscanf(fin, "%d", &pa[i]);
}
fclose(fin);
mx = pa[0];
for (int i = 1; i < n; i++)
{
	if (mx < pa[i])
	{
		mx = pa[i];
	}
}

kk = 0;
for (int i = 0; i < n; i++)
{
	if (3 * pa[i] >= 2 * mx)
	{
		kk++;
	}
}
fout = fopen("out4.txt", "wt");
if (fout == NULL)
{
	printf("write error");
	return;
}
fprintf(fout, "%d\n", kk);
for (int i = 0; i < n; i++)
{
	if (3 * pa[i] >= 2 * mx)
	{
		fprintf(fout, "%d ", pa[i]);
	}
}
fclose(fout);
free(pa);
}