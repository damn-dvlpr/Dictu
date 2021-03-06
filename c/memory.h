#ifndef dictu_memory_h
#define dictu_memory_h

#include <unistd.h>

#include "object.h"
#include "common.h"

#define ALLOCATE(vm, type, count) \
    (type*)reallocate(vm, NULL, 0, sizeof(type) * (count))

#define FREE(vm, type, pointer) \
    reallocate(vm, pointer, sizeof(type), 0)

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define SHRINK_CAPACITY(capacity) \
    ((capacity) < 16 ? 7 : (capacity) / 2)

#define GROW_ARRAY(vm, previous, type, oldCount, count) \
    (type*)reallocate(vm, previous, sizeof(type) * (oldCount), \
        sizeof(type) * (count))

#define FREE_ARRAY(vm, type, pointer, oldCount) \
    reallocate(vm, pointer, sizeof(type) * (oldCount), 0)

void *reallocate(VM *vm, void *previous, size_t oldSize, size_t newSize);

void grayObject(VM *vm, Obj *object);

void grayValue(VM *vm, Value value);

void collectGarbage(VM *vm);

void freeObjects(VM *vm);

void freeObject(VM *vm, Obj *object);

#endif
