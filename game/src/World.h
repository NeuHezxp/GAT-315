#pragma once

#include "Body.h"

extern ncBody* ncBodies;
extern int ncncncBodyCount;

extern ncBody* CreatencBody();
extern void DestroyncBody(ncBody* ncBody);
extern void DestroyAllncBodies();