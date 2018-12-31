
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


int print_report(position * record){

FILE  * report; 
report = fopen(REPORT_NAME, "w");	
fprintf(report, "-------------------------------------------------------------------------\n");
fprintf(report, "---------------------------------MARGIN REPORT---------------------------\n");
fprintf(report, "EX   FC   CP   PrvCP   NBR   Margin Amount\n");

for(int i=0; i<SIZE ; i++){
        
fprintf(report,  "%s  %s   %.2f  %.2f    %d    %.3f\n", record[i].ex , record[i].fc, record[i].clPrc, record[i].prvCp, record[i].nbr, record[i].marg);
}

fclose(report);	
return 0;
	
}
