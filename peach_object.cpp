#include <peach_object.h>
#include <stdlib.h>
void * peach_object::operator new(size_t i_len) {
    return malloc(i_len);
}
void peach_object::operator delete(void * p_buffer) {
    free(p_buffer);
}
