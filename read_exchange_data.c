#include <stdio.h>
#include <string.h>
#include <stdlib.h>


FILE * exchangeFile ;
float clPrc_get(char * ex, char *fc){
	char record[4] ;
	char * item;
	char  exchangeName[120] = "exchange_data/";

	strcat(exchangeName, ex); 
	strcat(exchangeName, "/");
	strcat(exchangeName, ex);
	strcat(exchangeName, ".txt");
	exchangeFile = fopen(exchangeName, "r");

	while(fgets(record, 20, exchangeFile)) {

		item = strtok(record, " ");
		if(! (memcmp(item,fc, 2))){
			item = strtok(NULL, " ");
			return atof(item);
		}
		else item = strtok(NULL, "\n");
	
	}


}
