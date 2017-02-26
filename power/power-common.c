#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "power-common.h"

const char * eas_governors[] = {
    SCHED_GOVERNOR,
    SCHEDUTIL_GOVERNOR,
    NULL
};

int is_eas_governor(const char *governor) {
    for(int index = 0; eas_governors[index] != NULL; index++) {
        if ((strncmp(governor, eas_governors[index], strlen(eas_governors[index])) == 0) && (strlen(governor) == strlen(eas_governors[index])))
            return 1;
    }
    return 0;
}
