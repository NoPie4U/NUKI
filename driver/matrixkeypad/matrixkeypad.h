#include "../device.h"

enum MatrixKeypad_status {
    INPUT_COMPLETE,
    INPUT_ABORT,
    INPUT_ERROR
};


struct _matrixkeypadCONF {
    char* buffer;
    unsigned int buffer_size;
};

struct _matrixkeypadAPI {
    int (*init)(const struct device*, char* const buffer, const unsigned int size);
    void (*isr)(const struct device*);
};

int MatixKeypad_init(const struct device *dev, char* const buffer, const unsigned int size);

void MatixKeypad_isr(const struct device *dev);
int _MatixKeypad_init(const struct device *dev, char* const buffer, const unsigned int size);
void _MatixKeypad_isr(const struct device *dev);


static const struct _matrixkeypadAPI genericMatixKeyPad_API = {.init=_MatixKeypad_init, .isr=_MatixKeypad_isr};

#define DECLAR_Generic_MatrixKeypad(NAME) \
struct _matrixkeypadCONF genericMatixKeyPad_CONF_##NAME = {.buffer=NULL, .buffer_size=0}; \
DECLAR_DEVICE(NAME, &genericMatixKeyPad_CONF_##NAME, &genericMatixKeyPad_API)
