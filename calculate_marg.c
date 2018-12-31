
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int calculateMgc(position * record){
	
for(int i=0; i<SIZE ; i++){
	record[i].marg =( (record[i].prvCp - record[i].clPrc ) * record[i].nbr);
}
	
return 0;
	
}
