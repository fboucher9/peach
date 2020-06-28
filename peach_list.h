// See LICENSE for license details
#ifndef peach_list_h_
#define peach_list_h_
#include <peach_object.h>
struct peach_list;
struct peach_list_it;
union peach_list_ptr {
    void const * mc_void_ptr;
    void * m_void_ptr;
    peach_list const * mc_list_ptr;
    peach_list * m_list_ptr;
};
struct peach_list : public peach_object {
    friend struct peach_list_it;
    peach_list();
    ~peach_list();
    static void s_join( peach_list * p_left, peach_list * p_right);
    bool is_empty() const;
    private:
    peach_list_ptr m_next_ptr;
    peach_list_ptr m_prev_ptr;
    peach_list(peach_list const & r) = delete;
    peach_list & operator=(peach_list const & r) = delete;
};
struct peach_list_it : public peach_object {
    peach_list_it(peach_list const & r_list);
    ~peach_list_it();
    bool f_cur(peach_list_ptr * r_list_ptr);
    bool f_first(peach_list_ptr * r_list_ptr);
    bool f_last(peach_list_ptr * r_list_ptr);
    bool f_next(peach_list_ptr * r_list_ptr);
    bool f_prev(peach_list_ptr * r_list_ptr);
    private:
    peach_list_ptr m_cur_ptr;
    peach_list_ptr m_end_ptr;
    peach_list_it(peach_list_it const & r) = delete;
    peach_list_it & operator=(peach_list_it const & r) = delete;
};
#endif // #ifndef peach_list_h_
