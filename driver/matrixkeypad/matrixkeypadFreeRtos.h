#include "matrixkeypad.h"

/**
 * Configuartion struct of the FreeRTOS MartixKeyPad
 */
struct _matrixkeypadRTOSCONF {
    struct _matrixkeypadCONF base;
    const QueueHandle_t queue;
};

/**
 * API for FreeRTOS
 */
struct _matrixkeypadFreeRTOSAPI {
    struct _matrixkeypadAPI base;
    void (*initRTOS)(const struct device*, char* const buffer, const unsigned int size, const QueueHandle_t q);
    void (*isr)(const struct device*);
};

/**
 * Convenience function to call the interrupt service routine 
 * @param device The device to be used
 */
void MatixKeypad_isr(const struct device *dev);

int _MatixKeypadRTOS_init(const struct device *, char* const buffer, const unsigned int size);
void _MatixKeypadRTOS_isr(const struct device *);

/**
 * API Instance
 */
static const struct _matrixkeypadFreeRTOSAPI matrixkeypadFreeRTOSAPI = {
    .base=matrixkeypadFreeRTOSAPI,
    .initRTOS=_MatixKeypadRTOS_init,
    .isr=_MatixKeypadRTOS_isr
};

#define DECLAR_MatrixKeypadRTOS(NAME) \
struct _matrixkeypadRTOSCONF MatixKeyPad_CONF_##NAME = {.buffer=NULL, .buffer_size=0}; \
DECLAR_DEVICE(NAME, &MatixKeyPad_CONF_##NAME, &matrixkeypadFreeRTOSAPI)
