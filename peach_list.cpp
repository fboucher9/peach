// See LICENSE for license details
#include <peach_list.h>
peach_list::peach_list() {
    m_next_ptr.m_list_ptr = this;
    m_prev_ptr.m_list_ptr = this;
}
peach_list::~peach_list() {
    if (!is_empty()) {
        peach_list::s_join(this, this);
    }
}
void peach_list::s_join( peach_list * p_left, peach_list * p_right) {
    p_left->m_next_ptr.m_list_ptr->m_prev_ptr = p_right->m_prev_ptr;
    p_right->m_prev_ptr.m_list_ptr->m_next_ptr = p_left->m_next_ptr;
    p_left->m_next_ptr.m_list_ptr = p_right;
    p_right->m_prev_ptr.m_list_ptr = p_left;
}
bool peach_list::is_empty() const {
    return (m_next_ptr.mc_list_ptr == this);
}
peach_list_it::peach_list_it(peach_list const & r_list) {
    m_cur_ptr.mc_list_ptr = &r_list;
    m_end_ptr.mc_list_ptr = &r_list;
}
peach_list_it::~peach_list_it() {
}
bool peach_list_it::f_cur(peach_list_ptr * r_list_ptr) {
    if (m_cur_ptr.mc_void_ptr != m_end_ptr.mc_void_ptr) {
        *r_list_ptr = m_cur_ptr;
        return true;
    } else {
        return false;
    }
}
bool peach_list_it::f_first(peach_list_ptr * r_list_ptr) {
    m_cur_ptr = m_end_ptr;
    return f_next(r_list_ptr);
}
bool peach_list_it::f_last(peach_list_ptr * r_list_ptr) {
    m_cur_ptr = m_end_ptr;
    return f_prev(r_list_ptr);
}
bool peach_list_it::f_next(peach_list_ptr * r_list_ptr) {
    m_cur_ptr = m_cur_ptr.mc_list_ptr->m_next_ptr;
    return f_cur(r_list_ptr);
}
bool peach_list_it::f_prev(peach_list_ptr * r_list_ptr) {
    m_cur_ptr = m_cur_ptr.mc_list_ptr->m_prev_ptr;
    return f_cur(r_list_ptr);
}
