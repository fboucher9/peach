// See LICENSE for license details
#include <peach_buffer.h>
#include <string.h>
bool peach_buffer::f_init_range(void const * p_min,
    void const * p_max) {
    m_min_ptr.mc_void_ptr = p_min;
    m_max_ptr.mc_void_ptr = p_max;
    return true;
}
bool peach_buffer::f_init_vector(void const * p_buffer,
    size_t i_buffer_len) {
    m_min_ptr.mc_void_ptr = p_buffer;
    m_max_ptr.mc_uchar_ptr = m_min_ptr.mc_uchar_ptr + i_buffer_len;
    return true;
}
bool peach_buffer::f_init_sz(char const * p_buffer0) {
    m_min_ptr.mc_char_ptr = p_buffer0;
    m_max_ptr.mc_char_ptr = p_buffer0 + strlen(p_buffer0);
    return true;
}
void peach_buffer::f_cleanup() {
}
size_t peach_buffer::f_len() const {
    size_t i_data_len = 0;
    if (m_max_ptr.mc_uchar_ptr > m_min_ptr.mc_uchar_ptr) {
        ptrdiff_t const i_diff =
            m_max_ptr.mc_uchar_ptr - m_min_ptr.mc_uchar_ptr;
        i_data_len = i_diff & 0x7fffffffL;
    }
    return i_data_len;
}
