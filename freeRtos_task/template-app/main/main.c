#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* Task noticifications */

TaskHandle_t receiverHandler = NULL;

void sender(void* params){
    while(true){
        xTaskNotifyGive(receiverHandler);
        vTaskDelay(2000 / portTICK_PERIOD_MS );
    }
}

void receiver(void* params){
    while(true){
        ulTaskNotifyTake(pdFALSE, portMAX_DELAY); // portMAx_DELAY will halt this line here until it recieves notifiction
        printf("Recieved notification\n");
        vTaskDelay( 2000 / portTICK_PERIOD_MS );
    }
}

void app_main(void)
{
    xTaskCreate(&receiver,"sender",2048,NULL,2, &receiverHandler);
    xTaskCreate(&sender,"reciever",2048,NULL,2,NULL); // Not sure how task 2 can be executed when lower priority
}