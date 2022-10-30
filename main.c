//
//  main.c
//  AI-NPuzzle
//
//  Created by Sena Kanik on 20.10.2022.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[],int size){
    printf("array: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void generateState(int initial [], int goal [],int x){
   
    time_t t;
    srand((unsigned) time(&t));
    int range= x*x; //n boyutlu puzzle da olabilecek kare sayısı.
    int count=0;
    int check=0;//sayının diziye eklenmemiş olma durumu
    //int  initial[range];
    //int goal[range];
    //random  sayısı dizisi üretme --> initial State
    
    while(count<range){ //diziye eklenmiş sayı kontrolü
        int r = rand() % range;
        for(int j=0;j<range;j++){
            //yeni üretilen sayı daha önce diziye eklenmiş mi diye kontrol ediliyor.
            if(initial[j]== r ){
                check=1;
            }
        }
        //sayı dizide ypksa diziye ekleme işlemi.
            if(check==0){
                initial[count]=r;
                count++;
            }
        else
            check=0;//her üretilen sayı sonunda yeni sayıya geçilirken başlangıç değerine dönmek gerekir.
        }
   
    //random üretielen sayı dizisi yazdırma
    printArray(initial,range);
    // random sayı dizisi üretme -->Goal State
    check=0;
    count=0;
    while(count<range){ //diziye eklenmiş sayı kontrolü
        int r = rand() % range;
        for(int j=0;j<range;j++){
            //yeni üretilen sayı daha önce diziye eklenmiş mi diye kontrol ediliyor.
            if(goal[j]== r ){
                check=1;
            }
        }
        //sayı dizide ypksa diziye ekleme işlemi.
            if(check==0){
               goal[count]=r;
                count++;
            }
        else
            check=0;//her üretilen sayı sonunda yeni sayıya geçilirken başlangıç değerine dönmek gerekir.
        }
    printArray(goal, range);
    //üretilen random sayıların matrise yerleştirme işlemi yapılıyor. -->inital State
    int matris[x][x];
    int goalMatris[x][x];
    int boyut=0;//matrisin j indexi için
    int sayi=0;//tek boyutlu dizi indexi
    while(boyut<x){
        for(int i=0;i<x;i++){
            matris[boyut][i]=initial[sayi];
            sayi++;
            
        }
        boyut++;
    }
    
    //-->Goal State
    boyut=0;
    sayi=0;
    while(boyut<x){
        for(int i=0;i<x;i++){
            goalMatris[boyut][i]=goal[sayi];
            sayi++;
            
        }
        boyut++;
    }
    
   //matrisin gösterimi.
    printf("Inital State of %d-Puzzle \n",x*x-1);
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            printf("\t%d ",matris[i][j]);
        }
        printf("\n");
    }
    
    printf("Goal State of %d-Puzzle \n",x*x-1);
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            printf("\t%d ",goalMatris[i][j]);
        }
        printf("\n");
    }
}



struct queue {
  int items[1000];
  int front;
  int rear;
};



int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(struct queue* q, int value) {
  if (q->rear == 10000 - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}


int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    
  }
  return item;
}


void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
        
      printf("%d ", q->items[i]);
    }
  }
}

void printQueueArr(struct queue* q,int range) {
  int i = q->front;
   
  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
        
        for(int x=q->items[i];&x<&x+4*range;x++){
           printf("%d",x);
          
        }
     
    }
  }
}

void bfs(int initial[],int goal[],int x,struct queue *q,struct queue *q1,int arr[]){
//    printf("bfs içinde");
   
    int vertex=0;
    int count=0;
    int range=x*x;
    int tempList[range];
    int arrCount=0;
    
    while(count<range){
        tempList[count]=initial[count];
        count++;
        
    }
    count=0;
    
       printf("temp list kontrolü--------\n");
        printArray(tempList, range);
    
    int kontrol=0;
        int komsu=0;
        while(tempList[vertex]!=0){
            vertex++;
        }
        
        printf("içinde bulunduğu index: %d\t",vertex);

        printf("\ngidebileceği adresler-----\n");
        printf("%d\t",vertex-1);
        if(vertex-1>=0 && vertex%x!=0){
            enqueue(q,vertex-1);
            komsu++;
            
        }
        printf("%d\t",vertex+1);
        if(vertex+1<=range-1 && vertex%x!=x-1){
            enqueue(q, vertex+1);
            komsu++;
        }
        printf("%d\t",vertex+x);
        if(vertex+x<=range-1 ){
            enqueue(q, vertex+x);
            komsu++;
        }
        printf("%d\t",vertex-x);
        if(vertex-x>=0){
            enqueue(q, vertex-x);
            komsu++;
        }
        printQueue(q);
//        vertex=vertex-1;
        
        
        
        printf("\n\nilk kontrol\n\n");
//         tüm gidebileceği yerlere gidiyot.
        while(komsu!=0){
            printArray(tempList, range);
            int temp=0;
            int swap=dequeue(q);
            komsu--;
            
            printf("vertex: %d\n", vertex);
            temp=tempList[vertex];
            printf("temp:%d\n",temp);
            printf("swap:%d\n",swap);
            tempList[vertex]=tempList[swap];
            
            tempList[swap]=temp;
            printf("swap sonrası tempList:\n");
            printArray(tempList, range);
            
            
         printf("if kontrolüne girdi. Goal ile");
                for(int z=0; z<range;z++){
                    printf("\nindex:%d\t",z);
                    printf("tempList: %d\t",tempList[z]);
                    printf("goal: %d",goal[z]);
                    if(tempList[z]==goal[z])
                        kontrol++;
                    
                }
         printf("\n\ntempList: ");
        printArray(tempList, range);
        printf("\n\nGoal:");
        printArray(goal, range);
            printf("\nkontrol: %d",kontrol);
                    if(kontrol==range){
                        printf("\n\n\narrlar eşit  \n\n\n");
                        for(int m=0; m<range;m++){
                            arr[m]=tempList[m];
                           
                            
                        }
                       
                        break;
                    }
            else
                kontrol=0;
            
            int y=0;
            //swap edilmiş yeni arr başka bir queue ekleniyor.
            while( y<9){
                
                enqueue(q1, tempList[y]);
                y++;
            }
            arrCount++;
            
            printf("q1 içindeki array");
            printQueue(q1);
            printf("\n");
            int matris[x][x];
            int boyut=0;//matrisin j indexi için
            int sayi=0;//tek boyutlu dizi indexi
            while(boyut<x){
                for(int i=0;i<x;i++){
                    matris[boyut][i]=tempList[sayi];
                    sayi++;
                    
                }
                boyut++;
            }
            boyut=0;
            sayi=0;
            //matris görüntüsünde yazdırmak için
            printf("matris yazdırırlıyor\n");
            
            for(int k=0;k<x;k++){
                for(int l=0;l<x;l++){
                    printf("\t%d ",matris[k][l]);
                }
                printf("\n");
            }
            printf("\n");
           //diğer komşulara geçmek için tempList başa döndürülüyor.
            while(count<range){
                tempList[count]=initial[count];
                count++;

            }
            count=0;
            
        }
    if(kontrol!=range){
        //bulunulan state için bütün olasılıklar tamamlanmış oluyor.
        printf("%d",arrCount);
        printf("\n\n-----------------İLK KOMŞULAR BİTTİİ---------\n\n");
        printf("\n\n\n");
        int tempList2[range];
        
        //2. queue eklenen stateler yeni bir arr aktarılıyor.
        for(int c=0;c<range;c++){
            tempList2[c]=dequeue(q1);
        }
        
        printf("\n\n----------array çıkarılmış hali--------------\n");
        printQueue(q1);
        printArray(tempList2, range);

       
        printf("\n\ntempList2: ");
        printArray(tempList2, range);
        printf("\n\nGoal:");
        printArray(goal, range);
        
    
       
            printf("\n\n--------------------yeniden bfs giriyor---------\n");
            printf("\n\n---------------yeni düzeye geçiliyor----------\n\n");
            bfs(tempList2, goal, x,q,q1,arr);
            
        }
    else{
 printf("\n\n\narrlar eşit  \n\n\n");
    for(int m=0; m<range;m++){
        arr[m]=tempList[m];
        printf("Hedef:");
        printArray(arr, range);
        if(kontrol==range){
            printf("\n\n\n-------Goal State ulaşıldı.--------\n\n\n");
            int matris[x][x];
            int boyut=0;//matrisin j indexi için
            int sayi=0;//tek boyutlu dizi indexi
            while(boyut<x){
                for(int i=0;i<x;i++){
                    matris[boyut][i]=arr[sayi];
                    sayi++;
                    
                }
                boyut++;
            }
            boyut=0;
            sayi=0;
            printf("matris yazdırırlıyor\n");
            for(int k=0;k<x;k++){
                for(int l=0;l<x;l++){
                    printf("\t%d ",matris[k][l]);
                }
                printf("\n");
            }
            printArray(arr, range);
            printArray(goal, range);
            
            printf("tamamlandı.");
            }
        
    }
}

}

    
   
int main(int argc, const char * argv[]) {
   // struct queue* q = malloc(sizeof(struct queue));
    //q->front = -1;
    //q->rear = -1;
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    //0  ın bulunduğu noktayı tutan queue
    struct queue* q1 = malloc(sizeof(struct queue));
    q1->front = -1;
    q1->rear = -1;
    printf("\n\tÇözülmesini istediiniz puzzle boyutunu giriniz.\n");
    printf("\tBoyut: ");
    int x;
    scanf("%d",&x);
    int range=x*x;
    int goal[]={8,7,4,3,6,5,0,1,2};
    int initial[]={8,7,0,3,5,4,1,6,2};
    int arr[range];
    
//    int goal[range];
//    int initial[range];
//    int arr[range];
    
//   generateState(initial,goal,x);

    int matris[x][x];
    int goalMatris[x][x];
    int boyut=0;//matrisin j indexi için
    int sayi=0;//tek boyutlu dizi indexi
    while(boyut<x){
        for(int i=0;i<x;i++){
            matris[boyut][i]=initial[sayi];
            sayi++;

        }
        boyut++;
    }

    //-->Goal State
    boyut=0;
    sayi=0;
    while(boyut<x){
        for(int i=0;i<x;i++){
            goalMatris[boyut][i]=goal[sayi];
            sayi++;

        }
        boyut++;
    }
    printf("Inital State of %d-Puzzle \n",x*x-1);
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            printf("\t%d ",matris[i][j]);
        }
        printf("\n");
    }

    printf("Goal State of %d-Puzzle \n",x*x-1);
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            printf("\t%d ",goalMatris[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    //enqueue(q, 3);
    //enqueue(q, 4);
    //printQueue(q);
    bfs(initial, goal, x,q,q1,arr);
    return 0;
}
