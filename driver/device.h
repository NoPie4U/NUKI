struct device {
    void* conf;
    const void* api;
};

#define DECLAR_DEVICE(NAME, CONF, API) struct device NAME = {.conf=CONF, .api=API};
