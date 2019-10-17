#ifndef SINGLELINEER_H_
#define SINGLELINEER_H_
#define size 20


typedef struct contact
{
    char name[size];
    char surname[size];
    char city[size];
    char homeNumber[size];
    struct contact *next;
}Contact;

typedef struct citycode
{
    char city[size];
    int code;
    struct citycode *next;
}City;
void deleteCityByName(City **head,char name[20]);
void deleteContactBySurname(Contact **head,char surname[20],City *list);
void printHomeNumber(char name[20],City *list);
void printListofCity(City *list);
void printCity(City c);
void new_City(City *d);
void new_contact(Contact *d);
void createContact(Contact **c);
void printList(Contact *list,City *list2);
void inster_City_List(City **head,City c);
void insterList(Contact **head, Contact c);
void printContact(Contact c,City *list);
char *serachCityByCode(City *list,int id);
int serachCityByName(City *list,char name[],int yaz);
void searchContactBySurname(Contact *list,char c[20],City *list2);
#endif 