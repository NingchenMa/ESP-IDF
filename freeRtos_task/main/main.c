#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task noticifications */

static taskHandle_t receiverHandler = NULL;

void sender(void* params){
    while(true){
        xNotifiyGive(receiverHandler);
        //printf("Reading tempperature from %s\n", (char *)param);
        vTaskDelay(5000 / portTICK_PERIOD_MS );
    }
}

void receiver(void* params){
    while(true){
        //printf("Reading humidity from %s\n",(char*)param);
        ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
        printf("Recieved noticification\n");
        vTaskDelay( 2000 / portTICK_PERIOD_MS );
    }
}

void app_main(void)
{
    xTaskCreate(&receiver,"sender",2048,NULL,2,&receiverHandler);
    xTaskCreate(&sender,"reciever",2048,NULL,2,NULL); // Not sure how task 2 can be executed when lower priority
}