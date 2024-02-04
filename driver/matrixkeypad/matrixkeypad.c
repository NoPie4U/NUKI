#include "matrixkeypad.h"
#include <stdio.h>
int MatixKeypad_init(const struct device* dev, char* const buffer, const unsigned int size) {
    struct _matrixkeypadAPI* api = (struct _matrixkeypadAPI*)dev->api;
    return api->init(dev, buffer, size);
}

int MatixKeypad_setBuffer(const struct device* dev, const char* const input, const unsigned int size) {
    struct _matrixkeypadAPI* api = (struct _matrixkeypadAPI*)(dev->api);
    return api->setbuffer(dev, input, size);
}

int MatixKeypad_getBuffer(const struct device* dev, const char** const buffer) {
    struct _matrixkeypadAPI* api = (struct _matrixkeypadAPI*)dev->api;
    return api->getbuffer(dev, buffer);
}

int _MatixKeypad_init(const struct device* dev, char* const buffer, const unsigned int size)
{
    struct _matrixkeypadCONF *conf = (struct _matrixkeypadCONF*)(dev->conf);
    conf->buffer = buffer;
    conf->buffer_size = size;

    for(int i=0;i<size;i++) {
        conf->buffer[i] = 0;
    }

    return MatrixKeypad_OK;
}

int _MatixKeypad_setBuffer(const struct device* dev, const char* const input, const unsigned int size)
{
    struct _matrixkeypadCONF *conf = (struct _matrixkeypadCONF*)(dev->conf);
    if(size > conf->buffer_size)
        return 0;

    for(int i=0;i<size;i++) {
        conf->buffer[i] = input[i];
    }

    return conf->buffer_size;
}

int _MatixKeypad_getBuffer(const struct device* dev, const char** buffer)
{
    struct _matrixkeypadCONF *conf = (struct _matrixkeypadCONF*)(dev->conf);
    *buffer = conf->buffer;
    return conf->buffer_size;
}
