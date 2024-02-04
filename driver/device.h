/**
 * Abstract Base class for all Devices
 */
struct device {
    void* conf; /**< pointer to the configuration struct of the implementation*/
    const void* api; /**< pointer to the API struct of the implementation*/
};

#define DECLAR_DEVICE(NAME, CONF, API) struct device NAME = {.conf=CONF, .api=API};
