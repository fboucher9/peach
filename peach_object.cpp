#include <peach_object.h>
extern "C" {
#include <cv_heap/cv_heap.h>
}
void * peach_object::operator new(size_t i_len) {
    return cv_heap_alloc(i_len);
}
void peach_object::operator delete(void * p_buffer) {
    cv_heap_free(p_buffer);
}
