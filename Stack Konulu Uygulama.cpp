/*Ödevin adým adým açýklamasý;
1-	Bir adet stack yapýsý oluþturun. Bu stack yapýsý aþaðýda belirtildiði þekilde çift yönlü baðlý liste olarak oluþturulmalýdýr.

struct node{
	int data;
struct node *next;
struct node *prev;
}

//Struct yapýsýnda ilk giren elemaný top olarak tutuyoruz.
struct node *top = NULL; 


2-	Programýn içerisinde, indislerinde 5 adet sesli 5 adet sessiz harf bulunduran bir dizi olmalýdýr. Bu dizi bilgisayar tarafýndan oluþturulmuþ rastgele harflerden oluþmalýdýr. Burada kontrol etmeniz gereken þey dizinin içerisinde mutlaka 5 adet rastgele sesli harf ve 5 adet rastgele sessiz harf bulunmalýdýr. (Harfler tekrar edebilir).

3-	Daha sonra bu dizideki elemanlarý oluþturduðunuz stack yapýsýna aktaracaðýz. Eðer gelen harf sessiz ise bu harften sonra gelen harf sesli olmalýdýr. Eðer sessiz bir harften sonra gelen harf sessiz ise bu harfi stack yapýsýndan atýp listeden rastgele yeni bir harf alacaðýz. Gelen harf sesli olana kadar bu iþleme devam edilecektir. Ayný þekilde sesli harften sonra da yalnýzca sessiz bir harf gelebilir. Burada pop ve push fonksiyonlarýný kodlamanýz gerekiyor. Stack yapýsýna eleman eklemek için push(), stack yapýsýndan eleman çýkarmak içinse pop() fonksiyonunu kullanmalýsýnýz. Her yeni eklenen harf stack yapýsýnýn yeni top elemaný olmalýdýr. 

4-	Stack yapýsýnda bir sesli - bir sessiz harf þeklinde toplam 6 harf olduðunda LIFO (Last-In-First-Out) mantýðý ile stack yapýsýndan tek tek veriler çýkarýlmalýdýr. Her çýkartýlan veri ekrana yazdýrýlmalýdýr.

*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
	int data;
	struct Node*next;
	struct Node*prev;
};
struct Node*top=NULL;

void push(int data){
	struct Node* yeninode=(struct Node*)malloc(sizeof(struct Node));
	yeninode->data=data;
	yeninode->next=top;
	yeninode->prev=NULL;
	if(top!=NULL){
		top->prev=yeninode;
	}
	top=yeninode;
}
int pop(){
	if(top==NULL){
		printf("Stack bostur.");
		return -1;
	}
	struct Node*temp=top;
	int data=temp->data;
	top=top->next;
	if(top!=NULL){
		top->prev=NULL;
	}
	free(temp);
	return data;
}
void stackekle(char harfler[]){
	for(int i=0;i<10;i++){
		if(harfler[i]=='b'||harfler[i]=='c'||harfler[i]=='d'||harfler[i]=='f'||harfler[i]=='g'||harfler[i]=='h'||harfler[i]=='j'||harfler[i]=='k'||harfler[i]=='l'||harfler[i]=='m'||harfler[i]=='n'||harfler[i]=='p'||harfler[i]=='r'||harfler[i]=='s'||harfler[i]=='t'||harfler[i]=='v'||harfler[i]=='y'||harfler[i]=='z'){
			if(top!=NULL&&(top->data=='b'||top->data=='c'||top->data=='d'||top->data=='f'||top->data=='g'||top->data=='h'||top->data=='j'||top->data=='k'||top->data=='l'||top->data=='m'||top->data=='n'||top->data=='p'||top->data=='r'||top->data=='s'||top->data=='t'||top->data=='v'||top->data=='y')){
				pop();
			}
			push(harfler[i]);
		}
		else if(harfler[i]=='e'||harfler[i]=='a'||harfler[i]=='u'||harfler[i]=='o'||harfler[i]=='i'){
			if(top!=NULL&&(top->data=='a'||top->data=='e'||top->data=='u'||top->data=='o'||top->data=='i')){
				pop();
			}
			push(harfler[i]);
		}
	}
}
char sesliharf(){
	char sesliharfler[]={'a','e','o','u','i'};
	return sesliharfler[rand()%5];
}
char sessizharf(){
	char sessizharfler[]={'b','c','d','f','g','h','j','k','l','m','n','p','r','s','t','v','y','z'};
	return sessizharfler[rand()%18];
}
void diziyikaristir(char dizi[]){
	for(int i=9;i>0;i--){
		int j=rand()%(i+1);
		char temp=dizi[i];
		dizi[i]=dizi[j];
		dizi[j]=temp;
	}
}
int main(){
	srand(time(NULL));
	char harfler[10];
	for(int i=0;i<5;i++){
		harfler[i]=sesliharf();
	}
	for(int i=5;i<10;i++){
		harfler[i]=sessizharf();
	}
	diziyikaristir(harfler);
	printf("Rastgele harfler:");
	for(int i=0;i<10;i++){
		printf("%c",harfler[i]);
	}
	printf("\n");
	stackekle(harfler);
	printf("\nStackten cikartilan harfler:\n");
	while(top!=NULL){
		int data=pop();
		if(data!=-1){
			printf("%c\n",data);
		}
	}
	return 0;
}


