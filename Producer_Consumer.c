#include<stdio.h>
int size, full=0, empty, in=0, out=0;
int buffer[100], item;
void display(){
    if(full == 0){
        printf("Queue: Empty\n");
        return;
    }
    printf("Queue: ");
    int i = out;
    for(int count=0; count<full; count++){
        printf("%d ", buffer[i]);
        i = (i + 1) % size;
    }
    printf("\n");
}
void producer(){
    if(full == size){
        printf("Buffer is Full\n");
        return;
    }
    printf("Enter Item: ");
    scanf("%d",&item);
    buffer[in] = item;
    in = (in + 1) % size;
    full++;
    empty--;
    printf("Item %d inserted\n",item);
    display();
}
void consumer(){
    if(full == 0){
        printf("Buffer is Empty\n");
        return;
    }
    item = buffer[out];
    out = (out + 1) % size;
    full--;
    empty++;
    printf("Item %d consumed\n",item);
    display();
}
int main(){
    int choice;
    printf("Enter Buffer Size: ");
    scanf("%d",&size);
    empty = size;
    while(1){
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        if(choice == 1)
            producer();
        else if(choice == 2)
            consumer();
        else if(choice == 3)
            break;
        else
            printf("Invalid Choice\n");
    }
    return 0;
}