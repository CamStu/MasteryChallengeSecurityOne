#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Program assumes ascii ranged input through commandline
int main(int argc, char **argv){
		  char *input, *garbage, *endstr, buffer1[20], buffer2[20];	
		  int i,temp,rn;

		  if(argc < 2){
					 printf("Error, program not given data\n");
					 return 1;
		  }

		  srand(argc);	//	Setting random number seed

		  input = malloc(sizeof(char)*strlen(argv[1]));
		  endstr = malloc(sizeof(char)*strlen(argv[1]));
		  strcpy(input,argv[1]);	// Have the input data, now to do some psuedo encryption
		  garbage = malloc(sizeof(char)*strlen(argv[1])*9);	//Garbage string uses 9 characters for every one from input

		  strcpy(garbage,"\0");	//Initialize empty string
		  strcpy(endstr,"\0");	//Initialize empty string
		  strcpy(buffer1,"\0");	//Initialize empty string
		  strcpy(buffer2,"\0");	//Initialize empty string

		  printf("\n");
		  printf("Input: %s\n",input);
		  printf("\n");


		  for( i=0; i<strlen(input); i++){
					 temp = (int)input[i];
					 rn = rand() % 100;
					 sprintf(buffer1, "%d", rn);	
					 strcat(buffer2,buffer1);

					 if(temp<100 && temp>9)
								sprintf(buffer1, "0%d",temp);	//	Pad with a zero to get to three characters
					 else if(temp<10)
								sprintf(buffer1, "00%d",temp);	//	Pad with two zeros to get to three characters
					 else if(temp <0)
								return -1;	//	Error state
					 else
								sprintf(buffer1, "%d",temp);

					 strcat(buffer2,buffer1);	

					 rn = rand() % 100;
					 sprintf(buffer1, "%d", rn);
					 strcat(buffer2,buffer1);

					 strcat(garbage,buffer2);
					 strcpy(buffer2,"\0");
		  }

		  printf("\n");
		  printf("Garbage string: %s\n", garbage);
		  printf("\n");
		  printf("Starting decryption\n");

		  for(i=0;i<strlen(garbage);i+=7){
					 //7 char blocks, first two are garbage as are last two, want the middle three
					 strncpy(buffer1,garbage+i, 7);	//Pointer arithemetic to copy out subsections of garbage
					 buffer1[7]='\0';	//Needs a null added manually if source is longer than dest (it is)
					 strncpy(buffer2,buffer1+2,3);		//Same idea here, copying out the middle three characters
					 buffer2[3]='\0';
					 temp = atoi(buffer2);
					 sprintf(buffer1,"%c",temp);
					 strcat(endstr,buffer1);
		  }

		  printf("String after decryption: %s\n", endstr);
		  printf("\n");


		  return 0;
}
