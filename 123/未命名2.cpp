#include<stdio.h>
#include<stdlib.h>
int main () {
	
	FILE *fp,*fp1;
	if(!(fp=fopen("123.txt","r"))){
		 printf("error\n");
		 exit(0);
	}
	if(!(fp1=fopen("tmp.txt","a"))){
		 printf("error\n");
		 exit(0);
	}
	char ch;
	while(!feof(fp)){
		ch=fgetc(fp);
		if(ch!=EOF) fputc(ch,fp1);
	}
	if(fclose(fp)) {
		printf("asf\n");
		exit(0);
	}if(fclose(fp1)) {
		printf("asf\n");
		exit(0);
	}
	return 0;
	
} 
