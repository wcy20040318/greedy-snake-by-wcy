#include"score.h"
int maxscore(int score){
	FILE *fp;
	int max=0;
	if((fp=fopen("score.txt","r"))==NULL){
	fp = fopen("score.txt","w+");
	fprintf(fp,"%d",score);
	}
	else{
	rewind(fp);
	fscanf(fp,"%d",&max);
		if(max<score)
	{
		fp = fopen("score.txt","w+");
		fprintf(fp,"%d",score);
	}
	fclose(fp);
	}
	return max>score?max:score;
}
