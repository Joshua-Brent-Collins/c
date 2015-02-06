#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{

int filelines = 0;
int count = 0; 
int j = 0;
typedef char f[20];
typedef char l[30]; 
f * first;
l * last;
char temp[30];

FILE *name_file;

name_file = fopen("unsortednames.txt","r");

while(name_file!=NULL){
	if(feof(name_file) != 0)
		{break;}
	fscanf(name_file, "%s %s", &temp[0], &temp[0]);
	filelines=filelines+1;
}

rewind(name_file);
first = malloc(sizeof(f)*filelines);
last =  malloc(sizeof(l)*filelines);

while(name_file!=NULL){
	if(feof(name_file) != 0)
		{break;}

	fscanf(name_file, "%s %s", &first[count][0], &last[count][0]);
	printf("\n",NULL);
	printf("%s %s",&first[count][0],&last[count][0]);
	count = count + 1;
}

for(count=0;count<filelines;count=count+1){
for(j=0;j<filelines;j=j+1){
if(strcmp(last[count],last[j])<0){
strcpy(temp , last[j]);
strcpy(last[j], last[count]);
strcpy(last[count], temp);
strcpy(temp , first[j]);
strcpy(first[j], first[count]);
strcpy(first[count], temp);
}
}
}
fclose(name_file);

name_file=fopen("sortednames.txt","w");
rewind(name_file);

for(j=0;j<filelines;j=j+1)
{
fprintf(name_file, "%-20.20s" , &first[j][0]);
fprintf(name_file, "%-30.30s\n" , &last[j][0]);
printf("%s %s\n", &first[j][0],&last[j][0]);
}

fclose(name_file);                      

free(first);
free(last);
first=NULL;
last=NULL;


}
