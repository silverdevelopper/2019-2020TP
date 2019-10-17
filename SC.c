#include "SC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * HOCAM ÇOK DA BİR FARK YOK ARALARINDA SLyi  YAZDIĞIM
 * ŞEKİLDE DİĞERLERİ DE ÇALIŞIYOR SADECE INSERT EDERKEN VE
 * ARAMA YAPARKEN BIRAZ FARK OLUŞUYOR
 * Hocam bu yaptığımda sc ve dc aynnı oluyor hiçbir farklılığı olmuyor 
 * sadece left kısımdan da gidilebiliyor ama ben yapmaya gerek duymuyorum
 * çoğu aynı zaten Saat de gec 3.10 oldu :)
*/
void insterList(Contact **head, Contact c)
{
    Contact *tmp = *head;
    Contact *new_node = (Contact*)malloc(sizeof(Contact));
    strcpy(new_node->name,c.name);
    strcpy(new_node->surname,c.surname);
    strcpy(new_node->city,c.city);
    strcpy(new_node->homeNumber,c.homeNumber);
    new_node->next = NULL;
    if(*head==NULL)
    {
        *head=new_node;
        (*head)->next=*head;
        return;
    }
    if(strcmp((*head)->surname,c.surname)>=0) 
    {
        while (tmp->next!=*head)
        {
            tmp=tmp->next;
        }
        tmp->next=new_node;
        new_node->next=*head;
        *head=new_node;
    
    }
    else {
        tmp=(*head)->next;
    while (tmp->next!= *head && strcmp(tmp->next->surname,c.surname)<0) {
    tmp = tmp->next;
    }
    new_node->next=tmp->next;
    tmp->next = new_node;
   
    }
   
}
void inster_City_List(City **head,City c)
{
    City *tmp = *head;
    City *new_node = (City*)malloc(sizeof(City));
    strcpy(new_node->city,c.city);
    new_node->code=c.code;
  if(*head==NULL)
    {
        *head=new_node;
        (*head)->next=*head;
        return;
    }
    if(strcmp((*head)->city,c.city)>=0) 
    {
        while (tmp->next!=*head)
        {
            tmp=tmp->next;
        }
        tmp->next=new_node;
        new_node->next=*head;
        *head=new_node;
    
    }
    else {
        tmp=(*head)->next;
    while (tmp->next!= *head && strcmp(tmp->next->city,c.city)<0) {
    tmp = tmp->next;
    }
    new_node->next=tmp->next;
    tmp->next = new_node;
   
    }
    
}

void printListofCity(City *list){
    City *tmp=list;
    if(list==NULL)
    {
        printf("Boş Liste\n");
        return;
    }
    printf("\nCities:\n");

    while(tmp->next != list)
    {
        
        printCity(*tmp);
        tmp=tmp->next;
        
    }
    printCity(*tmp);
    printf("\n");
}
void printList(Contact *list,City *list2){
    Contact *tmp=list;
    printf("\nContacts:\n");
    if(list==NULL){
        printf("NULL Liste\n");
        return;
    }
    
    while(tmp->next!=list)
    {
        printContact(*tmp,list2);
        tmp=tmp->next;
    }
    printContact(*tmp,list2);
    printf("\n");
}
void new_contact(Contact *d)
{
     printf("isim:\n");
    scanf("%s",d->name);
    printf("soyisim:\n");
    scanf("%s",d->surname);
    printf("sehir:\n");
    scanf("%s",d->city);
    printf("phone Namber:\n");
    scanf("%s",d->homeNumber);
}
void new_City(City *d)
{
    printf("Cities:\n");
    printf("Sehir Adı:\n");
    scanf("%s",d->city);
    printf("Kodu:\n");
    scanf("%d",&d->code);
   
}
void printHomeNumber(char name[20],City *list)
{
    City *tmp=list;
    int code=serachCityByName(list,name,0);
    printf("%d",code);
    
}
void printContact(Contact c,City *list)
{
    printf("Name:%s\nSurname:%s\ncity:%s\nHomeNumber:",c.name,c.surname,c.city);
    printHomeNumber(c.city,list);
    printf("%s",c.homeNumber);
    printf("\n\n");
}
void printCity(City c){
    printf("\nName: %s\nCode:c%d\n\n",c.city,c.code);
}
void searchContactBySurname(Contact *list,char c[20],City *list2){
    Contact *tmp=list;
    while(tmp->next!=list)
    {
        if(strcmp(tmp->surname,c)==0)
        {
            printContact(*tmp,list2);
            return;
        }
        tmp=tmp->next;
    }
    printf("Bulunamadı\n");
}
char *serachCityByCode(City *list,int id){
    City *tmp=list;
    while(tmp->next!=list)
    {
        if(tmp->code==id)
       { 
           printCity(*tmp);
           return tmp->city;
       }
        tmp=tmp->next;
    }
    
    return "";
}
int serachCityByName(City *list,char name[],int yaz){
    City *tmp=list;
    while(tmp->next!=list)
    {
        if(!strcmp(tmp->city,name))
       { 
           if(yaz)
           printCity(*tmp);
           return tmp->code;
       }
        tmp=tmp->next;
    }
    
    return -1;
}
void deleteContactBySurname(Contact **head,char surname[20],City *list)
{
    Contact *tmp=*head;
    Contact *prev;
    if(!strcmp(tmp->surname,surname)&& tmp->next!=(*head))
    {
        *head=(*head)->next;
        free(tmp);
        return;
    }
    while (tmp!=*head && strcmp(surname,tmp->surname))
    {
        prev=tmp;
        tmp=tmp->next;  
        
    }
    
    if (tmp == *head) 
    {
        prev->next=(*head)->next;
        free(head);
    return;
    }; 
    prev->next = tmp->next; 
  
    free(tmp);
    
    
}
void deleteCityByName(City **head,char name[20])
{
    City *tmp=*head;
    City *prev;
    if(!strcmp(tmp->city,name)&& tmp->next!=(*head))
    {
        *head=(*head)->next;
        free(tmp);
        return;
    }
    while (tmp->next!=(*head) && strcmp(name,tmp->city))
    {
        prev=tmp;
        tmp=tmp->next;  
        
    }
    
    if (tmp == *head) {
        prev->next=(*head)->next;
        free(head);
        return;
    } 
    prev->next = tmp->next; 
  
    free(tmp);
}