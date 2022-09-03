#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "module.h"

// struct Person {
//     char firstName[20];
//     char lastName[20];
//     int age;
// };

typedef struct Person_struct {
    char firstName[20];
    char lastName[20];
    int age;
    void (*doWork) (char * dataRetrieved);
}Person;

void updatePerson(Person* person, char* dataRetrieved) {
    strcpy(person->firstName,"data from dataRecieved ");
    strcpy(person->lastName,"data from dataRecieved ");
    person->age = 29;
}

void exclamIt(char* str){
    strcat(str,"!");//concate ! at the end of the input string
}

void doWorkForPerson(char* dataRetrieved){
    Person person;
    updatePerson(&person, dataRetrieved);
    printf("Person %s %s is %d years old.\n",person.firstName,person.lastName,person.age);
}

//This generic function takes a function pointer as an argument in order to do any kind of work so far
void connectAndGetInfo(char* url, void (*doWork) (char* dataRetrieved) ){

    //Connect to wireless
    //Conenct to endpoint
    //allocate memory
    char* dataRetrieved = (char*)malloc(sizeof(char)*1024);
    doWork(dataRetrieved);

    //fill the buffer with data: getRequest(&dataRetreived)
    //Do work and get a person object
    //clean up memory and other recourses

    free((void *)dataRetrieved );
}

void app_main(void)
{
    connectAndGetInfo("http://getperon.com",doWorkForPerson);
    // char string[20] = "Hello, world";
    // exclamIt(string);
    // printf("%s\n",string);
    // Person* person = (Person*) malloc(sizeof(Person));
    // updatePerson(person);
    // printf("Person %s %s is %d years old.\n",person->firstName,person->lastName,person->age);
}