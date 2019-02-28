#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>

void add();
void choice();
void search();
void del();
void searchst();
void modify();
void list();
void modifyst();
void listst();

struct student
{
    int rollno;
    float avg;
    char name[50];
    char fname[50];
    char add[100];
}s1;

int main()
{
    int i,x;
    printf("\t\t\tSTUDENT MANGEMENT SYSTEM");
    printf("\n\n\n");
    printf("Who are you???\n\n");
    printf("1.Admin\n2.student");
    printf("\n\nEnter your choice:::");
    scanf("%d",&x);
    choice(x);
}
void choice(int x)
{
    int n,ch;
    switch(x)
    {
    case 1:
    {
        printf("\nEnter the password : ");
        scanf("%d",&n);
        if(n==456123)
        {
            system("cls");
            do
            {	
                printf("\n1.Add details \n2.Search details\n3.Modify detail\n4.Delete detail\n5.View  the student detail as list\n6.Close the application\n");
                printf("\nEnter choice : ");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    add();
                    break;
                case 2:
                    search();
                    break;
                case 3:
                    modify();
                    break;
                case 4:
                    del();
                    break;
                case 5:
                    list();
                    break;
                case 6:
                    exit(0);
                    break;
                default :
                    printf("\nWrong choice");
                }
            }
            while(1);
        }
        else
        {
            printf("\nWrong password");
        }
        break;
    }
    case 2 :
        system("cls");
        do
        {
            printf("\n1.View the list\n2.View your detail\n3.Modify your details\n4.Close the application");
            printf("\nEnter you choice : ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
                listst();
                break;
            case 2:
                searchst();
                break;
            case 3:
                modifyst();
                break;
            case 4:
                exit(0);
                break;
            default :
                printf("\nWrong choice");
            }
        }
        while(1);

    }

}

void add()
{
    system("cls");
    char ch;
    FILE *fp;
    int x;
    printf("Enter student details\n\n");
    printf("Enter student roll number : ");
    scanf("%d",&s1.rollno);
    printf("Enter name : ");
    fflush(stdin);
    gets(s1.name);
    printf("Enter percentage : ");
    scanf("%f",&s1.avg);
    printf("Enter father name : ");
    fflush(stdin);
    gets(s1.fname);
    printf("Enter address : ");
    gets(s1.add);
    fp=fopen("student.dat","a+");
    fwrite(&s1,sizeof(s1),1,fp);
    printf("\nStudent details saved in file\n");
    rewind(fp);
    printf("\nDo you want to see the detail you added y/n : ");
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    {
        printf("\nName : %s\nRollno : %d\nPercentage : %f\n Father name : %s\nAddress : %s\n",s1.name,s1.rollno,s1.avg,s1.fname,s1.add);
    }
    fclose(fp);
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
        choice(x);
    }
    else
    {
        exit(0);
    }

}

void search()
{
    system("cls");
    char s[20];
    int x,n,flag=0,y;
    FILE *fp;
    fp=fopen("student.dat","r");
    printf("The mode by which u wanted to search");
    printf("\n1.Roll no\n2.Name\n");
    printf("Enter your choice : ");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
    {
        printf("\nEnter roll number : ");
        scanf("%d",&n);
        while( (fread(&s1,sizeof(s1),1,fp))==1)
        {
            if(n==s1.rollno)
            {
                flag=1;
                printf("\nName : %s\nRollno : %d\nPercentage : %f\n Father name : %s\nAddress : %s\n",s1.name,s1.rollno,s1.avg,s1.fname,s1.add);
                break;
            }
        }
        if(flag=0)
        {
            printf("\nRoll number is not found\n");
            system("pause");
        }

        break;
    }

    case 2:
    {

    char sid[30];
    int flag = 0;
    printf("Enter Name to Search: ");fflush(stdin);
    gets(sid);
    FILE *fp;
    fp = fopen("student.dat","rb");
    while(fread(&s1,sizeof(s1),1,fp) == 1){
        if(strcmp(sid,s1.name) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("\nName : %s\nRollno : %d\nPercentage : %f\n Father name : %s\nAddress : %s\n",s1.name,s1.rollno,s1.avg,s1.fname,s1.add);
        
    }else{
        printf("Sory, No record found in the database");
    }
    break;
    }
    default :
        printf("You enterd wrong choice!!!");
    }
    
    fclose(fp);
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
        choice(x);
    }
    else
    {
        exit(0);
    }
}


void modify()
{
    system("cls");
    int roll;
    int x, flag = 0;
    printf("Enter Roll no of student to Modify: ");
    scanf("%d",&roll);
    FILE *fp;
    fp = fopen("student.dat","rb+");
    while(fread(&s1,sizeof(s1),1,fp)==1){
        if(roll == s1.rollno){
            printf("Enter student details\n\n");
    		printf("Enter student roll number : ");
    		scanf("%d",&s1.rollno);
    		printf("Enter name : ");
    		fflush(stdin);
    		gets(s1.name);
    		printf("Enter percentage : ");
    		scanf("%f",&s1.avg);
    		printf("Enter father name : ");
    		fflush(stdin);
    		gets(s1.fname);
    		printf("Enter address : ");
    		gets(s1.add);
            fseek(fp, -sizeof(s1), SEEK_CUR);
            fwrite(&s1,sizeof(s1), 1, fp);
            flag = 1;
            printf("\nStudent record has been modified!!!\n");
            break;
        }
    }
    if(!flag){
        printf("No Record Found");
    }
    fclose(fp);
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
        choice(x);
    }
    else
    {
        exit(0);
    }
}

void list()
{
    system("cls");
    FILE*fp;
    int y, x;
    fp=fopen("student.dat","r");
    while(fread(&s1,sizeof(s1),1,fp)==1)
        printf("\nName : %s\nRollno : %d\nPercentage : %f\nFather name : %s\nAddress : %s\n",s1.name,s1.rollno,s1.avg,s1.fname,s1.add);
    system("pause");
    fclose(fp);
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
        choice(x);
    }
    else
    {
        exit(0);
    }
}

void del()
{
    system("cls");
    int roll;
    int x;
    int flag = 0;
    printf("Enter Roll Number of student to delete: ");
    scanf("%d",&roll);
    FILE *fp, *temp;
    fp = fopen("student.dat","rb");
    temp = fopen("temp.dat", "wb");
    while(fread(&s1, sizeof(s1),1,fp) == 1){
        if(roll != s1.rollno){
            fwrite(&s1,sizeof(s1),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("student.dat");
    rename("temp.dat","student.dat");
    printf("\nThe record is sucessfully deletedd");
    
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
        choice(x);
    }
    else
    {
        exit(0);
    }
}
void searchst()
{
    system("cls");
    char s[20];
    int x,n,flag=0,y;
    FILE *fp;
    fp=fopen("student.dat","r");
    printf("The mode by which u wanted to search");
    printf("\n1.Roll no\n2.Name\n");
    printf("Enter your choice : ");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
    {
        printf("\nEnter roll number : ");
        scanf("%d",&n);
        while( (fread(&s1,sizeof(s1),1,fp))==1)
        {
            if(n==s1.rollno)
            {
                flag=1;
                printf("\nName : %s\nRollno : %d\nPercentage : %f\n Father name : %s\nAddress : %s\n",s1.name,s1.rollno,s1.avg,s1.fname,s1.add);
            }
        }
        if(flag=0)
        {
            printf("\nRoll number is not found\n");
            system("pause");
        }

        break;
    }

    case 2:
    {

        printf("\nEnter the name : ");
        fflush(stdin);
        gets(s);
        while( (fread(&s1,sizeof(s1),1,fp))==1)
        {
            if(strcmp(s,s1.name)==0);
            {
                flag=1;
            }
        }
        if(flag)
        {
            fread(&s1,sizeof(s1),1,fp);
            printf("\nName : %s\nRollno : %d\nPercentage : %f\n Father name : %s\nAddress : %s\n",s1.name,s1.rollno,s1.avg,s1.fname,s1.add);
            system("pause");
        }
        else
        {
            printf("\nName not found");
            system("pause");
        }
        break;
    }
    default :
        printf("You entered wrong choice!!!");
    }
    fclose(fp);
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
    	x++;
        choice(x);
    }
    else
    {
        exit(0);
    }
}


void modifyst()
{
    system("cls");
    int roll;
    int x, flag = 0;
    printf("Enter Roll no of student to Modify: ");
    scanf("%d",&roll);
    FILE *fp;
    fp = fopen("student.dat","rb+");
    while(fread(&s1,sizeof(s1),1,fp)==1){
        if(roll == s1.rollno){
            printf("Enter student details\n\n");
    		printf("Enter student roll number : ");
    		scanf("%d",&s1.rollno);
    		printf("Enter name : ");
    		fflush(stdin);
    		gets(s1.name);
    		printf("Enter percentage : ");
    		scanf("%f",&s1.avg);
    		printf("Enter father name : ");
    		fflush(stdin);
    		gets(s1.fname);
    		printf("Enter address : ");
    		gets(s1.add);
            fseek(fp,-sizeof(s1), SEEK_CUR);
            fwrite(&s1,sizeof(s1), 1, fp);
            flag = 1;
            printf("\nStudent record has been modified!!!\n");
            break;
        }
    }
    if(!flag){
        printf("No Record Found");
    }
    fclose(fp);
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
    	x++;
        choice(x);
    }
    else
    {
        exit(0);
    }
}

void listst()
{
    system("cls");
    FILE*fp;
    int y, x;
    fp=fopen("student.dat","r");
    while(fread(&s1,sizeof(s1),1,fp)==1)
        printf("\nName : %s\nRollno : %d\nPercentage : %f\nFather name : %s\nAddress : %s\n",s1.name,s1.rollno,s1.avg,s1.fname,s1.add);
    system("pause");
    fclose(fp);
    printf("\n1.Main menu\n2.Close this applicaltion??");
    printf("\nEnter your choice : ");
    scanf("%d",&x);
    if(x==1)
    {
    	x++;
        choice(x);
    }
    else
    {
        exit(0);
    }
}
