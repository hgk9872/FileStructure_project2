#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
//필요하면 header file 추가 가능

#define SUFFLE_NUM	10000	// 이 값은 마음대로 수정할 수 있음.

void GenRecordSequence(int *list, int n);
void swap(int *a, int *b);
// 필요한 함수가 있으면 더 추가할 수 있음.

int main(int argc, char **argv)
{
	int *read_order_list;
	int num_of_records, i; // 레코드 파일에 저장되어 있는 전체 레코드의 수
	char filename[50];
	char buf[250];
	long fpos, elapsed;
	struct timeval start, end;
	FILE *fp;

	scanf("%s", filename);
	fp = fopen(filename, "rb");
	fread(&num_of_records, sizeof(int), 1, fp);
	fpos=ftell(fp);

	read_order_list = (int*)malloc(sizeof(int) * num_of_records);
	// 이 함수를 실행하면 'read_order_list' 배열에는 읽어야 할 레코드 번호들이 나열되어 저장됨
	GenRecordSequence(read_order_list, num_of_records);

	//
	// 'read_order_list'를 이용하여 random 하게 read 할 때 걸리는 전체 시간을 측정하는 코드 구현
	//
	gettimeofday(&start, NULL);
	for (i=0; i<num_of_records; i++){
		fseek(fp, read_order_list[i]*250, SEEK_CUR);
		fread(buf, sizeof(buf), 1, fp);
		fseek(fp, fpos, SEEK_SET);
	}
	gettimeofday(&end, NULL);

	elapsed = end.tv_usec - start.tv_usec;
	printf("#records: %d elapsed_time: %ld us\n", num_of_records, elapsed);

	fclose(fp);

	return 0;
}

void GenRecordSequence(int *list, int n)
{
	int i, j, k;

	srand((unsigned int)time(0));

	for(i=0; i<n; i++)
	{
		list[i] = i;
	}
	
	for(i=0; i<SUFFLE_NUM; i++)
	{
		j = rand() % n;
		k = rand() % n;
		swap(&list[j], &list[k]);
	}
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
