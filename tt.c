#include<stdio.h>
typedef struct
{
    long int ID;
    double height;
    double weight;
    double BMI;
}data;
int main()
{
    data student[10];
    int x,i,c=0,ii,iii,t;
    printf("Enter X ");
    scanf("%d",&x);
    x=x-1;
    for(i=0;i<=x;i++)
    {
    printf("\nenter NO.%d student's ID ",i+1);
    scanf(" %ld",&student[i].ID);
    printf("\nenter NO.%d student's height<cm> ",i+1);
    scanf(" %lf",&student[i].height);
    printf("\nenter NO.%d student's weight<kg> ",i+1);
    scanf(" %lf",&student[i].weight);
    }
    for(i=0;i<=x;i++)
    {
        student[i].BMI=student[i].weight/((student[i].height/100)*(student[i].height/100));
    }
    for(i=0;i<=x;i++)
    {
        printf("\n NO.%d student's ID is %ld",i+1,student[i].ID);
        printf("\n NO.%d student's height is %.2lf",i+1,student[i].height);
        printf("\n NO.%d student's weight is %.2lf",i+1,student[i].weight);
        printf("\n NO.%d student's BMI is %.2lf",i+1,student[i].BMI);
    }
    iii=x;
    for(i=0;i<=x;i++)
    {
        for(ii=0;ii<=iii;ii++)
        {
            if(student[c].BMI<student[ii].BMI)
                student[c].BMI=student[ii].BMI;
        }
        printf("\n NO.%d student's ID is %ld",c+1,student[c].ID);
        printf("\n NO.%d student's height is %.2lf",c+1,student[c].height);
        printf("\n NO.%d student's weight is %.2lf",c+1,student[c].weight);
        printf("\n NO.%d student's BMI is %.2lf",c+1,student[c].BMI);
        student[c].BMI=0;
        iii=iii-1;
    }
    return 0;
}