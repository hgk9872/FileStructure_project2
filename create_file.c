#include <stdio.h>
#include <stdlib.h>
// 필요하면 hearder file을 추가할 수 있음

int main(int argc, char **argv)
{
	int num;
	char student[250] = "student record";
	char filename[50];
	FILE *fp;
	//
	// 사용자로부터 입력 받은 레코드 수만큼의 레코드를 레코드 파일에 저장하는 코드를 구현
	//
	
	scanf("%d %s", &num, filename);

	fp = fopen(filename, "wb");
	fwrite(&num,sizeof(int),1,fp);
	for (int i=0 ; i<num ; i++){
		fwrite(student, sizeof(student),1,fp);
	}
	fclose(fp);

	
	return 0;
}
