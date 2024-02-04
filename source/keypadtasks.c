#include <stdio.h>
#include <matrixkeypad/matrixkeypad.h>

DECLAR_Generic_MatrixKeypad(matrixkeypad0)

QueueHandle_t keypadinput_q;

void KeypadTask( void * pvParameters )
{
    while(1)
    {
        xQueueReceive(keypadinput_q, portMAX_DELAY);
    }
}

int main()
{
    char buffer[16];

    keypadinput_q = xQueueCreate( 2, sizeof(MatrixKeypad_status) );

    if(MatixKeypad_init(&matrixkeypad0, buffer, sizeof(buffer)) != 0)
        printf("KeyPad INIT failed\n");

    


    return 0;
}