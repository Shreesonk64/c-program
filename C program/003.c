#include<stdio.h>
float ctof(float c){
 float f=(c-32)/1.8;
 return f;
};
int main(){
    float c,f;
    printf("Enter Celsius:");
    scanf("%f",&c);
    f=ctof(c);
    printf("fahrenheit value:%f",f);
    return 0;

}
