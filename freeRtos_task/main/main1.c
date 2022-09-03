#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task creation and how to run tasks on the second core */

void task1(void* param){
    while(true){
        printf("Reading tempperature from %s\n", (char *)param);
        vTaskDelay( 1000 / portTICK_PERIOD_MS );
    }
}

void task2(void* param){
    while(true){
        printf("Reading humidity from %s\n",(char*)param);
        vTaskDelay( 2000 / portTICK_PERIOD_MS );
    }
}

void app_main(void)
{
    xTaskCreate(&task1,"Temperature Reading",2048,"task1",1,NULL);
    //Using the second core
    xTaskCreatePinnedToCore(&task2,"Humidity Reading",2048,"task2",5,NULL,1); // Not sure how task 2 can be executed when lower priority
}