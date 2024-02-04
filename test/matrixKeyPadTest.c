#include <stdio.h>
#include <matrixkeypad/matrixkeypad.h>

//create instance of an MatrixKeyPad
DECLAR_MatrixKeypad(matrixkeypad0)

/**
 * Basic Test to check Data copy function in KeyPad Library
 */
int main()
{
    char buffer[16];

    if(MatixKeypad_init(&matrixkeypad0, buffer, sizeof(buffer)) != 0)
        return 1;

    char in[] = "asdf";
    MatixKeypad_setBuffer(&matrixkeypad0, in, sizeof(in));


    const char* input;
    MatixKeypad_getBuffer(&matrixkeypad0, &input);

    for(int i=0;i<4;i++) {
        if(input[i] != in[i])
            return 2;
    }

    return 0;
}