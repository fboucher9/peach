// See LICENSE for license details
#ifndef peach_buffer_h_
#define peach_buffer_h_
#include <peach_object.h>
union peach_buffer_ptr {
    void const * mc_void_ptr;
    void * m_void_ptr;
    char const * mc_char_ptr;
    char * m_char_ptr;
    unsigned char const * mc_uchar_ptr;
    unsigned char * m_uchar_ptr;
};
struct peach_buffer : public peach_object {
    peach_buffer() = default;
    ~peach_buffer() = default;
    bool f_init();
    bool f_init_range(void const * p_min,
        void const * p_max);
    bool f_init_vector(void const * p_buffer,
        size_t i_buffer_len);
    bool f_init_sz(char const * p_buffer0);
    void f_cleanup();
    size_t f_len() const;
    peach_buffer_ptr m_min_ptr;
    peach_buffer_ptr m_max_ptr;
    private:
    peach_buffer(peach_buffer const & r) = delete;
    peach_buffer & operator=(peach_buffer const & r) = delete;
};
#endif // #ifndef peach_buffer_h_
