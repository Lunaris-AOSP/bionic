/*
 * Copyright (C) 2023 Paranoid Android
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <string.h>

#include "system_properties/prop_imitation_hooks.h"

#define GMS_UNSTABLE "com.google.android.gms.unstable"

#define PROP_FIRST_API_LEVEL "ro.product.first_api_level"
#define PROP_PIH_FIRST_API_LEVEL "persist.sys.pihooks_DEVICE_INITIAL_SDK_INT"

void PropImitationHooks::OnFind(const char** name) {
  if (getprogname() == nullptr || strcmp(getprogname(), GMS_UNSTABLE) != 0) {
    return;
  }
  PIH_LOG("name is %s", *name);
  if (strcmp(*name, PROP_FIRST_API_LEVEL) == 0) {
    *name = PROP_PIH_FIRST_API_LEVEL;
  } else {
    return;
  }
  PIH_LOG("name changed to %s", *name);
}
