#include<stdio.h>
struct employ {
    char nam[50],add[50];
    float sal;
};
int main(){
        int n,i,j;
        char temp[50];
        printf("Enter no. of employee:");
        scanf("%d",&n);
        struct employ emp[n];

        for(i=0;i<n;){
            printf("For %d employ.",i+1);
            printf("\nEnter name of employ:");
            scanf(" %[^\n]",emp[i].nam);
            printf("\nEnter their address name:");
            scanf(" %s",emp[i].add);
            printf("\nEnter their salary:");
            scanf("%f",&emp[i].sal);
            i++;
        }
        for(i=0;i<n-1;i++){
                for(j=i+1;j<n;j++){
            if(strcmp(emp[j].nam,emp[i].nam)<0){
                strcpy(temp,emp[j].nam);
                strcpy(emp[j].nam,emp[i].nam);
                strcpy(emp[i].nam,temp);
            }
        }
        }
        printf("\n THE details of employ:\n");
         for(i=0;i<n;i++){

            printf("\n Name of employ: %s\n",emp[i].nam);

            printf("\n Their address name: %s\m",emp[i].add);

            printf("\nTheir salary: %.2f\n",emp[i].sal);

        }
        getch();
        return 0;
}
