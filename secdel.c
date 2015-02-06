//Joshua B. Collins File Deletion Code 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int main(int argc, char *argv[])
{

printf("%s \n",argv[1]);

srand(time(NULL));

FILE * file_pointer;

file_pointer=fopen(argv[1],"r+");

int count =0;
int fsize =0;
int runs  =0;
long hold [1];


if(file_pointer==NULL)
{
	printf("Error opening file! \n");
	return(2);
}


if(file_pointer!=NULL)
{

rewind(file_pointer);

while(!feof(file_pointer)){
fgetc(file_pointer);
fsize=fsize++;
}

printf("File Size : %i Bytes\n",fsize);

rewind(file_pointer);


for(runs;runs<(atoi(argv[2]));runs++){

rewind(file_pointer);

for(count;count<fsize;count++)
{

hold[0]=(rand()%time(NULL));

//printf("%i \n",hold[0]);

fwrite(hold,1,sizeof(hold),file_pointer);

fflush(file_pointer);

}

printf("Run: %i \n",(runs+1));

count=0;
}


}


fclose(file_pointer);

return(0);

}

