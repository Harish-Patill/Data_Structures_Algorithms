#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_MARKER "<!-- QUESTIONS_START -->"
#define END_MARKER "<!-- QUESTIONS_END -->"

char *read_file(const char *path, long *out_len){
    FILE *f=fopen(path,"rb");
    if(!f){fprintf(stderr,"Could not open %s\n",path);exit(1);}
    fseek(f,0,SEEK_END);
    long len=ftell(f);
    fseek(f,0,SEEK_SET);
    char *buf=malloc(len+1);
    fread(buf,1,len,f);
    buf[len]='\0';
    fclose(f);
    if(out_len) *out_len=len;
    return buf;
}

int main(){
    long q_len, r_len;
    char *questions=read_file("Contents.txt",&q_len);
    char *readme=read_file("README.md",&r_len);

    // trim trailing whitespace/newlines from questions content
    while(q_len>0 && (questions[q_len-1]=='\n' || questions[q_len-1]=='\r' || questions[q_len-1]==' ')){
        questions[--q_len]='\0';
    }

    char *start=strstr(readme,START_MARKER);
    char *end=strstr(readme,END_MARKER);

    if(!start || !end || end<start){
        fprintf(stderr,"Markers not found in README.md\n");
        free(questions);free(readme);
        return 1;
    }

    long before_len=start-readme;
    char *after=end+strlen(END_MARKER);

    FILE *out=fopen("README.md","w");
    if(!out){fprintf(stderr,"Could not open README.md for writing\n");return 1;}

    fwrite(readme,1,before_len,out);
    fprintf(out,"%s\n```\n%s\n```\n%s",START_MARKER,questions,END_MARKER);
    fprintf(out,"%s",after);

    fclose(out);
    free(questions);
    free(readme);

    printf("README updated successfully!\n");
    return 0;
}