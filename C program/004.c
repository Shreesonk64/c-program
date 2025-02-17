#include<stdio.h>
int isprime(int a){
if(a<=1)
    return 0;
for(int i=2;i<a;i++){
    if(a%i==0)
        return 0;
}
return 1;
   }
int main(){
int a;
printf("Enter a num:");
scanf("%d",&a);
if(isprime(a))
    printf("\n %d is a prime num",a);
else
    printf("\n %d is not a prime num",a);
return 0;
}
