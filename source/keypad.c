#include <stdio.h>
#include <matrixkeypad/matrixkeypad.h>

DECLAR_Generic_MatrixKeypad(matrixkeypad0)

int main()
{
    char buffer[16];

    if(MatixKeypad_init(&matrixkeypad0, buffer, sizeof(buffer)) != 0)
        printf("KeyPad INIT failed\n");

    printf("%d\n", sizeof(enum MatrixKeypad_status));
    return 0;
}