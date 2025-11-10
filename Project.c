#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
char name[100];
int id;
char branch[50];
char section;
int marks;
};
void addstudent();
void deletestudent();
void displaystudent();
void sortstudent();
void searchstudent();
void exitprogram();
int main(){
int n;
while(1){
printf("==Student Management System==\n");
printf("1.Add Student Details\n");
printf("2.Delete Student\n");
printf("3.Display Student Details\n");
printf("4.Sort Student\n");
printf("5.Search Student\n");
printf("6.Exit Program\n");
printf("enter Choice:");
scanf("%d",&n);
if(n==1){
    addstudent();
}
else if(n==2){
    deletestudent();
}
else if(n==3){
    displaystudent();
}
else if(n==4){
    sortstudent();
}
else if(n==5){
    searchstudent();
}
else if(n==6){
    exitprogram();
}
}
}
void addstudent(){
struct student s;
    FILE *fp = fopen("student.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
    }
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter branch: ");
    scanf("%s", s.branch);
    printf("Enter section: ");
    scanf(" %c", &s.section);
    printf("Enter Marks: ");
    scanf("%d",&s.marks);
    fprintf(fp, "%s %d %s %c %d\n", s.name, s.id, s.branch,s.section,s.marks);
    fclose(fp);
    printf(" Student added successfully!\n");
}
void deletestudent(){
    struct student s;
FILE *fp=fopen("student.txt","r");
FILE *temp=fopen("temp.txt","w");
if(fp==NULL){
    printf("Error");
}
char removename[100];
int found=0;
printf("enter the Student Name to delete: ");
scanf("%s",&removename);
while(fscanf(fp,"%s %d %s %c %d\n",s.name,&s.id,s.branch,&s.section,&s.marks)==5){
    if(strcmp(removename,s.name)==0){
        found=1;
        continue;
    }
    fprintf(temp,"%s %d %s %c %d\n",s.name,s.id,s.branch,s.section,s.marks);

}
fclose(fp);
fclose(temp);
remove("student.txt");
rename("temp.txt","student.txt");
if(found==1){
    printf("deleted successfully");
}
else{
    printf("not found");
}
}
void displaystudent(){
    struct student s;
FILE *fp=fopen("student.txt","r");
while(fscanf(fp,"%s %d %s %c %d",s.name,&s.id,&s.branch,&s.section,&s.marks)!=EOF){
    printf("Name :%s\n",s.name);
    printf("Id :%d\n",s.id);
    printf("BRANCH :%s\n",s.branch);
    printf("Section :%c\n",s.section);
    printf("Marks :%d\n",s.marks);
}
fclose(fp);
}
void sortstudent(){
struct student s[100],temp;
FILE *fp=fopen("student.txt","r");
if(fp==NULL){
    printf("ERROR");
}
int count=0;
while(fscanf(fp,"%s %d %s %c %d",s[count].name,&s[count].id,s[count].branch,&s[count].section,&s[count].marks)==5){
    count++;
}
if(count==0){
    printf("Name not found");
}
for(int i=0;i<count-1;i++){
 for(int j=i+1;j<count;j++){
    if(strcmp(s[i].name,s[j].name)>0){
       temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
 }
}
for(int i=0;i<count;i++){
    printf("Name :%s\n",s[i].name);
    printf("ID :%d\n",s[i].id);
    printf("Branch :%s\n",s[i].branch);
    printf("Section :%c\n",s[i].section);
    printf("Marks :%d\n",s[i].marks);
}
fclose(fp);
}
void searchstudent(){
struct student s;
FILE *fp=fopen("student.txt","r");
if(fp==NULL){
    printf("error");
}
int found=0;
char bolo[100];
printf("enter name to search: ");
scanf("%s",bolo);
while(fscanf(fp,"%s %d %s %c %d",s.name,&s.id,s.branch,&s.section,&s.marks)==5){
    if(strcmp(bolo,s.name)==0){
            found=1;
        printf("The entered name is found in Text File:\n");
        printf("Name :%s\n",s.name);
        printf("Id :%d \n",s.id);
        printf("Branch :%s\n",s.branch);
        printf("Section :%c\n",s.section);
        printf("Marks :%d\n",s.marks);
    }
}
if(found==0){
    printf("Not found");
}
fclose(fp);
}
void exitprogram(){
exit(0);
}
