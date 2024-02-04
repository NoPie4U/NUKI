#include "matrixkeypad.h"

int MatixKeypad_init(const struct device *dev, char* const buffer, const unsigned int size) {
    struct _matrixkeypadAPI* api = (struct _matrixkeypadAPI*)dev->api;
    return api->init(dev, buffer, size);
}

void MatixKeypad_isr(const struct device *dev) {
    struct _matrixkeypadAPI* api = (struct _matrixkeypadAPI*)dev->api;
    api->isr(dev);
}

int _MatixKeypad_init(const struct device *dev, char* const buffer, const unsigned int size)
{
    struct _matrixkeypadCONF *conf = (struct _matrixkeypadCONF*)&(dev->conf);
    //conf->buffer = buffer;
    //conf->buffer_size = size;
}

void _MatixKeypad_isr(const struct device *dev)
{
    //read 
}
