#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>
#include <stdint.h>

/*
 * buffer errors
 */
typedef enum {
    NO_MEM = -1, /* no memory to alloc */
    OK = 0,  /* success */
} buf_error_t;

typedef struct buffer {
    uint8_t *data;  /* actual characters data */
    size_t size;  /* string size */
    size_t a_size;  /* allocated memory  size */
    size_t unit;  /* reallocation unit size; unit=0 => readonly buffer */
} buf_t;

/*
 * API functions
 */

buf_t *buf_new(size_t unit);  /* new a buffer */
int buf_grow(buf_t *buf, size_t target_size);  /* grow up buffer to target size */
void buf_free(buf_t *buf);  /* release buffer */

#endif