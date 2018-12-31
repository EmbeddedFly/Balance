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

	while(fgets(positionRecord, 120, positionFile)) {


		item = strtok(positionRecord, s);
		strlcpy(record[reCount].ex, item, 3);
 		
		item = strtok(NULL, s);
 		
		strlcpy(record[reCount].fc, item, 3);
 
		item = strtok(NULL, s);

		record[reCount].nbr = atoi(item);

		record[reCount].prvCp= prvCp_get(record[reCount].ex, record[reCount].fc);

                record[reCount].clPrc = clPrc_get(record[reCount].ex, record[reCount].fc);
		calculateMgc(record);

		printf( "EX: %s FC: %s  Nbr: %d  CP: %0.2f PrvCP: %.2f marg: %.3f  \n" , record[reCount].ex ,record[reCount].fc , record[reCount].nbr, record[reCount].clPrc, record[reCount].prvCp, record[reCount].marg);
		reCount++;
	}
	fclose(positionFile);
	
	print_report(record);

	return 0;
}


