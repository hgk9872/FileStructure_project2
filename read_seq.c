#include <stdio.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	char filename[50];
	struct timeval start, end;
	long elapsed;
	char buf[250];
	int num;
	FILE *fp;

	scanf("%s", filename);
	fp = fopen(filename, "rb");
	fread(&num, sizeof(int), 1, fp);

	gettimeofday(&start, NULL);
	for (int i=0; i<num ; i++)
		fread(buf, sizeof(buf), 1, fp);
	gettimeofday(&end, NULL);

	elapsed = end.tv_usec - start.tv_usec;
	printf("#records: %d elapsed_time: %ld us\n", num, elapsed);

	fclose(fp);

	return 0;
}
