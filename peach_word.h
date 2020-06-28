// See LICENSE for license details
#ifndef peach_word_h_
#define peach_word_h_
#include <peach_list.h>
#include <peach_buffer.h>
struct peach_word : public peach_list {
    peach_word() = default;
    ~peach_word() = default;
    bool f_init(peach_buffer const & r_data);
    void f_cleanup();
    // data is stored into chunk list then transfered to a word
    peach_buffer m_data;
    private:
    peach_word(peach_word const & r) = delete;
    peach_word & operator =(peach_word const & r) = delete;
};
union peach_word_ptr {
    peach_list_ptr o_list_ptr;
    peach_word const * pc_word;
    peach_word * p_word;
};
struct peach_word_it : public peach_list_it {
    peach_word_it(peach_list const & r_list);
    ~peach_word_it();
    bool f_next(peach_word_ptr * r_word_ptr);
};
#endif // #ifndef peach_word_h_
