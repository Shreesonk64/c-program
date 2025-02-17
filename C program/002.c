#include<stdio.h>
int main(){
    int v[4]={5,4,3,2};
    int *p=&v;

    for(int i=0;i<=3;i++){
    printf("%d\n",*(p+i));
    printf("%d\n",&p+i);
    }
    printf("\n\n\n");

    for(int i=0;i<=3;i++){
    printf("%d\n",v[i]);
    printf("%d\n",&v[i]);
    }

    return 0;
}
