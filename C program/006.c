#include<stdio.h>
int rev(int n,int rem)
{
    if(n==0)
        return rem;
   else{
    rem=rem*10+n%10;
    return rev(n/10,rem);
   }
}
int main(){
    int num;
printf("Enter num:");
scanf("%d",&num);
printf("Reverse of num :%d",rev(num,0));
return 0;
}
