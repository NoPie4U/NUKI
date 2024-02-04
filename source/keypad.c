#include <stdio.h>
#include <matrixkeypad/matrixkeypad.h>

//create instance of an MatrixKeyPad
DECLAR_MatrixKeypad(matrixkeypad0)

/*
 * Main of the Matrix KeyPad Project
 */
int main(void)
{
    char buffer[16];

    if(MatixKeypad_init(&matrixkeypad0, buffer, sizeof(buffer)) != MatrixKeypad_OK)
        printf("KeyPad INIT failed\n");

    char in[] = "asdf";
    MatixKeypad_setBuffer(&matrixkeypad0, in, 4);


    const char* input;
    MatixKeypad_getBuffer(&matrixkeypad0, &input);

    printf("%s\n", input);
    return 0;
}