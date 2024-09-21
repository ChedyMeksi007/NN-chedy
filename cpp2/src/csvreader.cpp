#include "../include/main.hpp"
#include "../include/csvreader.hpp"

readCsv(const char* filepath,vector<double> input,vector<double> target){
	FILE* fp;
	char row[MAX_CHAR+1];
	char* ptr;
	fp = fopen(filepath,"r");

	if(fp == NULL){
		fprintf(stderr,"Could not open file %s \n",filepath);
		exit(-1);
	}
	int j = 0;
	while(fgets(row,MAX_CHAR,fp) != NULL){
		int i = 0;
		char* token = strtok(row,",");
		while(token != NULL){
			long tmp = (double)strtol(token,&ptr,10);

			if(i == 0){
				labels[j] =(double)tmp;
			}else{
				images[j][i-1] = ((double)tmp) / 255; //flatten 0->255 to 0->1
			}
			token= strtok(NULL,",");
			i++;

		}
		j++;
	}

	fclose(fp);
}
