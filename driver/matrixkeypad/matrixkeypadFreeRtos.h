#include "matrixkeypad.h"

struct _matrixkeypadRTOSCONF {
    struct _matrixkeypadRTOSCONF base;
    QueueHandle_t queue;
};

struct _matrixkeypadFreeRTOSAPI {
    struct _matrixkeypadAPI base;
    void (*isr)(const struct device*);
};

static const struct _matrixkeypadAPI genericMatixKeyPad_API = {.init=_MatixKeypadRTOS_init, .isr=_MatixKeypadRTOS_isr};
