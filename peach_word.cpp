// See LICENSE for license details
#include <peach_word.h>
#include <stdlib.h>
#include <string.h>
bool peach_word::f_init(peach_buffer const & r_data) {
    bool b_result = false;
    size_t const i_data_len = r_data.f_len();
    void * const p_void = malloc(i_data_len);
    if (p_void) {
        memcpy(p_void, r_data.m_min_ptr.mc_void_ptr, i_data_len);
        if (m_data.f_init_vector(p_void, i_data_len)) {
            b_result = true;
        }
        if (!b_result) {
            free(p_void);
        }
    }
    return b_result;
}
void peach_word::f_cleanup() {
    if (m_data.m_min_ptr.m_void_ptr) {
        free(m_data.m_min_ptr.m_void_ptr);
    }
    m_data.f_cleanup();
}
peach_word_it::peach_word_it(peach_list const & r_list) :
    peach_list_it(r_list) {
}
peach_word_it::~peach_word_it() {
}
bool peach_word_it::f_next(peach_word_ptr * r_word_ptr) {
    return peach_list_it::f_next(&r_word_ptr->o_list_ptr);
}
