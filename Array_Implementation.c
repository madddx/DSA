#include<stdio.h>
#include<stdlib.h>
#define Maxsize 50

int arr[Maxsize];
int size;


void display(){
    if(size==0){
        printf("The array is empty");
    }

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void insertatposition(int pos,int val){
    for( int i=size-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=val;
    size++;
}



void deletefromposition(int pos){
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}




int main(){
    int n,val,pos;
    while(1){
        printf("\nChoose the operation\n");
        printf("1.Insert at end\n");
        printf("2.Insert at any pos\n");
        printf("3.delete at any pos\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("6.Enter the element to be searched:\n");
        printf("Enter between(1-6): ");
        scanf("%d",&n);

        switch(n){
            case 1:

                if (size==Maxsize){
                    printf("The array is Full");
                }

                printf("Enter The Value to be added at the end: ");
                scanf("%d",&val);
                arr[size]=val;
                size++;
                break;

            case 2:

                if (size==Maxsize){
                    printf("The array is Full");
                }

                printf("Enter The Postion to be added(Position starts from 0):");
                scanf("%d",&pos);
                if(pos<0 || pos>size){
                    printf("Enter Valid Position\n");
                    break;
                }

                printf("Enter The Value to be added: ");
                scanf("%d",&val);
                insertatposition(pos,val);
                break;
            
            case 3:

                if (size==0){
                    printf("The array is empty");
                }

                printf("enter the position to be deleted");
                scanf("%d",&pos);
                if (pos<0 || pos>=size){
                    printf("Enter Valid Position\n");
                }

                deletefromposition(pos);
                break;

            case 4:

                display();
                break;
            
            case 5:
                exit(0);

            case 6:
                printf("Enter the value to be searched: ");
                scanf("%d",&val);
                for(int i=0;i<=size;i++){
                    if(val==arr[i]){
                        printf("The value is present\n");
                        break;
                    }
                    else{
                        printf("Value is nt found");
                        break;
                    }

                }
                break;
                
            
            default:
                printf("Enter Valid operation");
                break;

        }
    }
}
