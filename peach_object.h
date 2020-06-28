// See LICENSE for license details
#ifndef peach_object_h_
#define peach_object_h_
#include <peach_types.h>
struct peach_object {
    peach_object() = default;
    ~peach_object() = default;
    static void * operator new(size_t i_len);
    static void operator delete(void * p_buffer);
    private:
    peach_object(peach_object const & r) = delete;
    peach_object & operator=(peach_object const & r) = delete;
};
#endif // #ifndef peach_object_h_
