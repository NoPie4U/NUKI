#include <stdio.h>
#include <matrixkeypad/matrixkeypadFreeRtos.h>

//create instance of an MatrixKeyPad
DECLAR_MatrixKeypadRTOS(matrixkeypad0)

//Queue used to signal new matrix KeyPadInput available
QueueHandle_t keypadinput_q;

/**
 *the Service Handling the KeyPad input
*/
void KeypadTask( void * pvParameters )
{
    while(1)
    {
        xQueueReceive(keypadinput_q, portMAX_DELAY);

        //rate limiting
        //verify input
        //unlock ...

        //or forward input to different device
    }
}

/*
 * Main of the Matrix KeyPad Project
 */
int main(void)
{
    char buffer[16];

    keypadinput_q = xQueueCreate( 2, sizeof(MatrixKeypad_status) );

    if(MatixKeypad_init(&matrixkeypad0, buffer, sizeof(buffer)) != 0)
        printf("KeyPad INIT failed\n");

    //TODO start KeypadTask thread

    while(1) {}

    return 0;
}