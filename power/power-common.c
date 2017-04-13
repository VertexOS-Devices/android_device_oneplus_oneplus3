#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <utils/Log.h>
#include "power-common.h"

const char * eas_governors[] = {
    SCHEDUTIL_GOVERNOR,
    SCHED_GOVERNOR,
    PWRUTIL_GOVERNOR,
    ALUCARDSCHED_GOVERNOR,
    DARKNESSSCHED_GOVERNOR,
    NULL
};

int is_eas_governor(const char *governor) {
    for(int index = 0; eas_governors[index] != NULL; index++) {
        if ((strncmp(governor, eas_governors[index], strlen(eas_governors[index])) == 0) && (strlen(governor) == strlen(eas_governors[index])))
            return 1;
    }
    return 0;
}

int get_int(const char* file_path, int fallback_value) {
	FILE *file;
	file = fopen(file_path, "r");
	if (file == NULL) {
		ALOGE("%s: failed to open: %s", __func__, strerror(errno));
		return fallback_value;
	}
	int value;
	fscanf(file, "%d", &value);
    fclose(file);
	return value;
}
