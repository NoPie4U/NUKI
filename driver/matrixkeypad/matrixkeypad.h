#include "../device.h"

/**
 * Retrun Values of the MatrixKeyPad API
 */
enum MatrixKeypad_status {
    MatrixKeypad_OK = 0,
    MatrixKeypad_ERROR,
    INPUT_COMPLETE, /**< complete sequence read*/
    INPUT_ABORT, /**< input sequence aborted*/
    INPUT_ERROR /**< error during input sequence*/
};

/**
 * Configuartion struct of the basic MartixKeyPad
 */
struct _matrixkeypadCONF {
    char* buffer;
    unsigned int buffer_size;
};

/**
 * API
 */
struct _matrixkeypadAPI {
    int (*init)(const struct device*, char* const buffer, const unsigned int size);
    int (*setbuffer)(const struct device*, const char* const input, const unsigned int size);
    int (*getbuffer)(const struct device*, const char** const buffer);
};

/**
 * Convenience function to call constructor 
 * @param device The device to construct
 * @param buffer Allocated buffer for the input
 * @param size Size of the buffer
 * @return MatrixKeypad_status
 */
int MatixKeypad_init(const struct device *, char* const buffer, const unsigned int size);
/**
 * Convenience function to set the buffer contents
 * @param device The device to be used
 * @param input Input will be copied to the internal buffer
 * @param size Size of the input
 */
int MatixKeypad_setBuffer(const struct device*, const char* const input, const unsigned int size);
/**
 * Convenience function to retrieve buffer contents
 * @param device The device to be used
 * @param buffer Will be set to a pointer to the internal buffer 
 * @return size Size of the internal buffer
 */
int MatixKeypad_getBuffer(const struct device*, const char** const buffer);

int _MatixKeypad_init(const struct device *, char* const buffer, const unsigned int size);
int _MatixKeypad_setBuffer(const struct device*, const char* const input, const unsigned int size);
int _MatixKeypad_getBuffer(const struct device*, const char** buffer);

/**
 * API Instance
 */
static const struct _matrixkeypadAPI MatixKeyPad_API = {
    .init=_MatixKeypad_init,
    .setbuffer=_MatixKeypad_setBuffer,
    .getbuffer=_MatixKeypad_getBuffer
};

#define DECLAR_MatrixKeypad(NAME) \
struct _matrixkeypadCONF MatixKeyPad_CONF_##NAME = {.buffer=NULL, .buffer_size=0}; \
DECLAR_DEVICE(NAME, &MatixKeyPad_CONF_##NAME, &MatixKeyPad_API)
