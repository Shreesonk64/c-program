#include<stdio.h>
int sum(int a){
if(a==0)
    return 0;
return a + sum(a-1);
}
int main (){
int a;
printf("Enter a number:");
scanf ("%d",&a);
if(a>=0)
    printf("The sum oof its natural num is %d",sum(a));
else
    printf("Invalid natural number");
return 0;
}
