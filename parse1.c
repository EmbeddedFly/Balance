#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "main.h"


float clPrc_get(char* ex, char* fc);
float prvCp_get(char* ex, char* fc);
int calculateMgc(position * record);
int print_report(position * record);



FILE * positionFile;
char  positionRecord[120];
char * item;
char s[2] = ";";
int k;
int reCount=0;

position record[SIZE];
int main() {
positionFile = fopen("position.txt", "r");

// read file line by line

	while(fgets(positionRecord, 120, positionFile)) {
	//	printf("%s \n", positionRecord);

		item = strtok(positionRecord, s);
//		printf("item  %s\n", item); 
		strlcpy(record[reCount].ex, item, 3);
 		
		item = strtok(NULL, s);
//		printf("item  %s\n", item); 		
		strlcpy(record[reCount].fc, item, 3);
//		printf("record  %s\n", record[reCount].fc); 
		item = strtok(NULL, s);
//		printf("item  %s\n", item); 
		record[reCount].nbr = atoi(item);
//		printf("%d\n",  record[reCount].nbr);

		record[reCount].prvCp= prvCp_get(record[reCount].ex, record[reCount].fc);


//		printf("%2.f\n", record[reCount].clPrc);

                record[reCount].clPrc = clPrc_get(record[reCount].ex, record[reCount].fc);
		calculateMgc(record);

		printf( "EX: %s FC: %s  Nbr: %d  CP: %0.2f PrvCP: %.2f marg: %.3f  \n" , record[reCount].ex ,record[reCount].fc , record[reCount].nbr, record[reCount].clPrc, record[reCount].prvCp, record[reCount].marg);
		reCount++;
	}
	fclose(positionFile);
print_report(record);
//        for (k=0; k<reCount; k++) {
//	char f[2];
//	strncpy(f, record[k].ex, 2);
//	printf("first EX %d\n", record[1].closingPrice);
  	     // printf( "%s  %s %d \n " , record[k].ex ,record[k].fc , record[k].closingPrice);             

        //}

	return 0;
}


