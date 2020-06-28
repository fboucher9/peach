// See LICENSE for license details
#include <peach_stdin.h>
#include <stdio.h>
#include <string.h>
size_t peach_stdin::s_read(peach_buffer const & r_buffer) {
    return fread(r_buffer.m_min_ptr.m_void_ptr, 1, r_buffer.f_len(), stdin);
}
size_t peach_stdin::s_read_line(peach_buffer const & r_buffer) {
    size_t i_line_len = 0;
    char * const p_char = r_buffer.m_min_ptr.m_char_ptr;
    size_t const z_buffer_len = r_buffer.f_len();
    if (z_buffer_len <= 0x7fff) {
        int const i_buffer_len = z_buffer_len & 0x7fff;
        char * p_std_result = fgets(p_char, i_buffer_len, stdin);
        if (p_std_result == p_char) {
            i_line_len = strlen(p_char);
        }
    }
    return i_line_len;
}
