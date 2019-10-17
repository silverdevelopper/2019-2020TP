#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include "SingleLineer.h"
int main()
{
    int resp=1;
    Contact *head=NULL;
    City *headcty=NULL;
    Contact c={"name","surname","DIY","123"};
    Contact c1={"name1","surname1","IST","1234"};
    Contact c2={"name2","surname2","BUR","1235"};
    Contact c3={"name3","surname3","ANT","1235"};
    Contact c4={"name4","surname4","IST","1235"};
    City cty1={"DIY",412};
    City cty2={"IST",212};
    City cty3={"BUR",300};
    City cty4={"ANT",500};
    Contact *addcont=malloc(sizeof(Contact));
    City *addcity=malloc(sizeof(City));
   
    insterList(&head,c);
    insterList(&head,c1);
    insterList(&head,c2);
    insterList(&head,c3);
    insterList(&head,c4);
    inster_City_List(&headcty,cty1);
    inster_City_List(&headcty,cty2);
    inster_City_List(&headcty,cty3);
    inster_City_List(&headcty,cty4);
    printf("\n\n");
    printList(head,headcty);
 

    
   
   while (resp)
   {
        printf("\n\n-----SL MENUYE HOSGELDINIZ-----\n");
        printf("-yeni kisi girmek icin 1’e\n");
        printf("-yeni sehir girmek icin 2’ye\n");
        printf("-kisi aramak icin 3’e\n");
        printf("-kisi silmek icin 4’e\n");
        printf("-sehir aramak icin 5’ya\n");
        printf("-sehir silmek icin 6’ya\n");
        printf("-kisiler listesini yazdirmak icin 7’ye\n");
        printf("-sehirler listesini yazdirmak icin 8’e\n");
        printf("-menuden cikmak icin 9’a basiniz.\n");
       scanf("%d",&resp);
       switch(resp)
       {
           case 1: 
           new_contact(addcont);
           insterList(&head,*addcont);
           printList(head,headcty); break;
           case 2: new_City(addcity);
           inster_City_List(&headcty,*addcity);
           printListofCity(headcty);
            break;
           case 3:
           printf("Kisi Soyadı Gir: ");
           char soyadi[20];scanf("%s",soyadi); 
           searchContactBySurname(head,soyadi,headcty);
           break; 

           case 4: 
           printf("Silmek istediginiz kisinin Soyadını Giriniz:");
           char sil[20]; scanf("%s",sil);
           deleteContactBySurname(&head,sil,headcty);
           printList(head,headcty);
           break;

           case 5:
           printf("Enter cityd Code: ");
           int n=0; scanf("%d",&n);
           serachCityByCode(headcty,n); break;
           case 6:
           printListofCity(headcty);
           printf("Silmek istediginiz sehrin adını Giriniz:");
           char sil_sehir[20]; scanf("%s",sil_sehir); 
           deleteCityByName(&headcty,sil_sehir);
           printListofCity(headcty);
           break;
           case 7: 
           printList(head,headcty);
           break;
           case 8: 
           printListofCity(headcty);break;
           case 9: resp=0; break;
           default: printf("Dogru Bas\n"); continue;
       }
   }
   
return 0;
}