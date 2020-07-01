#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__


#include <stdio.h>
typedef void (*voidptr)(void*,...);
//inline void printFunc(const char* fname)
//{
//    printf("%-60s | ", fname);
//}



//// TextFormatter ////////////

//class TextFormatter
//{
//public:
//    virtual ~TextFormatter() { };
//    virtual void print(const char* text) const = 0;
//};
typedef struct text_formatter{
    char c;
    voidptr* void_ptr;
}text_formatter;
void tf_destroy(text_formatter* this);
void init_text_formatter(text_formatter* this);
/*print*/
//
////// DefaultTextFormatter ////////////
//
//class DefaultTextFormatter: public TextFormatter
//{
//public:
//    DefaultTextFormatter();
//    DefaultTextFormatter(const DefaultTextFormatter&);
//    DefaultTextFormatter& operator=(const DefaultTextFormatter&);
//    ~DefaultTextFormatter();
//
//    virtual void print(const char* text) const;
//
//private:
//    class Ider
//    {
//    private:
//        static int next_id;
//    public:
//        static int getId() { return next_id++; }
//    };
//
//    const int id;
//};
typedef struct ider{

}ider;

typedef struct default_text_formmater{
    text_formatter t;
    int id;
}default_text_formmater;
typedef default_text_formmater* default_text_formmaterptr;
void init_default_text_formmater(default_text_formmaterptr this);
void init_default_text_formmater_dtf(default_text_formmaterptr this , const default_text_formmaterptr other);
default_text_formmaterptr dtf_assignment(default_text_formmaterptr this,default_text_formmaterptr other);
void v_dft_print_cptr(default_text_formmaterptr this,const char* text);
void dtf_destroy_text(default_text_formmaterptr this);
default_text_formmaterptr dft_generateFormatterArray();
//// PrePostFixer ////////////

//class PrePostFixer: public DefaultTextFormatter
//{
//public:
//    PrePostFixer(const char* prefix, const char* postfix);
//    ~PrePostFixer();
//
//    virtual void print(const char* text) const;
//    virtual void print(long num, char symbol = '\0') const;
//
//    virtual char getDefaultSymbol() const;
//
//protected:
//    const char* getPrefix() const;
//    const char* getPostfix() const;
//
//private:
//    void print_num(long num) const;
//    void print_num(long num, char symbol) const;
//
//    const char* pre;
//    const char* post;
//};
typedef struct pre_post_fixer{
    default_text_formmater dft;
    const char *pre;
    const char *post;
}pre_post_fixer;
typedef pre_post_fixer* pre_post_fixerptr;;
void ppf_init_fixer(pre_post_fixerptr this,const char* prefix, const char* postfix);
/*virtual*/void ppf_destroy_text(pre_post_fixerptr this);
/*virtual*/void v_ppf_print_cptr(pre_post_fixerptr this,const char* text);
/*virtual*/void v_ppf_print_lc(pre_post_fixerptr this,long num , char symbol);
/*virtual*/char ppf_get_default_symbol(pre_post_fixerptr this);

//// PrePostFixer Defs ////////////

/*inline functions*/
//inline const char* PrePostFixer::getPrefix() const
//inline const char* PrePostFixer::getPostfix() const
//inline void PrePostFixer::print_num(long num) const
//{
//    printFunc("[PrePostFixer::print_num(long)]");
//    printf("%s%ld%s\n", pre, num, post);
//}
//
//inline void PrePostFixer::print_num(long num, char symbol) const
//{
//    printFunc("[PrePostFixer::print_num(long, char)]");
//    printf("%s%c%ld%s\n", pre, symbol, num, post);
//}


//inline char PrePostFixer::getDefaultSymbol() const
//{
//    return '\0';
//}
//
//inline void PrePostFixer::print(long num, char symbol) const
//{
//    printFunc("[PrePostFixer::print(long, char)]");
//    printf("-->\n");
//
//    if (symbol)
//        print_num(num, symbol);
//    else
//        print_num(num);
//}



//// PrePostDollarFixer ////////////

//class PrePostDollarFixer: public PrePostFixer
//{
//public:
//    PrePostDollarFixer(const char* prefix, const char* postfix);
//    PrePostDollarFixer(const PrePostDollarFixer& other);
//    ~PrePostDollarFixer();
//
//    void print(int num, char symbol = $) const;
//    void print(long num, char symbol = $) const;
//    void print(double num, char symbol = $) const;
//    char getDefaultSymbol() const;
//};
typedef struct pre_post_dollar_fixer{
    pre_post_fixer ppf;
}pre_post_dollar_fixer;
typedef pre_post_dollar_fixer* pre_post_dollar_fixerptr;

void ppdf_init_fixer_cptrcptr(pre_post_dollar_fixerptr this,const char* prefix, const char* posfix);
void ppdf_init_fixer_ppdf(pre_post_dollar_fixerptr this,const pre_post_dollar_fixerptr other);
/*virtual*/void ppdf_destroy_fixer(pre_post_dollar_fixerptr this);
/*virtual*/void ppdf_print_lc(pre_post_dollar_fixerptr this,long num, char symbol );
void ppdf_print_ic(pre_post_dollar_fixerptr this,int num, char symbol );
void ppdf_print_dc(pre_post_dollar_fixerptr this,double num, char symbol );
/*virtual*/char ppdf_get_default_symbol(pre_post_dollar_fixerptr this);
//// PrePostDollarFixer Defs ////////////

//inline char PrePostDollarFixer::getDefaultSymbol() const
//{
//    return DEFAULT_SYMBOL;
//}

//// PrePostHashFixer ////////////

//class PrePostHashFixer: public PrePostDollarFixer
//{
//private:
//    static const char DEFAULT_SYMBOL = '#';
//public:
//    PrePostHashFixer(int prc = 4);
//    ~PrePostHashFixer();
//
//    void print(int num, char symbol = DEFAULT_SYMBOL) const;
//    void print(long num, char symbol = DEFAULT_SYMBOL) const;
//    void print(double num, char symbol = DEFAULT_SYMBOL) const;
//    char getDefaultSymbol() const;
//
//private:
//    int precision;
//};
typedef struct pre_post_hash_fixer{
    pre_post_dollar_fixer ppdt;
    int precision;
}pre_post_hash_fixer;
typedef  pre_post_hash_fixer* pre_post_hash_fixerptr;
void pphf_init_hash_fixer_i(pre_post_hash_fixerptr this, int prc);
/*virtual*/void pphf_destroy_hash_fixer(pre_post_hash_fixerptr);
/*virtual*/void pphf_print_lc(pre_post_hash_fixerptr this,long num ,char symbol);
void pphf_print_ic(pre_post_hash_fixerptr this,int num ,char symbol);
void pphf_print_dc(pre_post_hash_fixerptr this, double num ,char symbol);
/*virtual*/char pphf_get_default_symbol(pre_post_hash_fixerptr this);

//// PrePostHashFixer Defs ////////////


//
//inline char PrePostHashFixer::getDefaultSymbol() const
//{
//    return DEFAULT_SYMBOL;
//}


//// PrePostFloatDollarFixer ////////////

//class PrePostFloatDollarFixer: public PrePostDollarFixer
//{
//protected:
//    static const char DEFAULT_SYMBOL = '@';
//
//public:
//    PrePostFloatDollarFixer(const char* prefix, const char* postfix);
//    ~PrePostFloatDollarFixer();
//    void print(float num) const;
//    void print(float num, char symbol) const;
//    char getDefaultSymbol() const;
//};
typedef struct pre_post_float_dollar_fixer{
    pre_post_dollar_fixer ppdf;
}pre_post_float_dollar_fixer;
typedef pre_post_float_dollar_fixer* pre_post_float_dollar_fixerptr;
void ppfdf_init_dollar_fixer_cptrcptr(pre_post_float_dollar_fixerptr this, const char* prefix,const char* postfix);
/*virtual*/void ppfdf_destroy_dollar_fixer(pre_post_float_dollar_fixerptr this);
void ppfdf_print_f(pre_post_float_dollar_fixerptr this, float num);
void ppfdf_print_fc(pre_post_float_dollar_fixerptr this, float num, char symbol);
/*virtual*/char ppfdf_get_default_symbol(pre_post_float_dollar_fixerptr this);

//// PrePostFloatDollarFixer Defs ////////////

//inline char PrePostFloatDollarFixer::getDefaultSymbol() const
//{
//    return DEFAULT_SYMBOL;
//}
//
////// PrePostChecker ////////////
//
//class PrePostChecker: public PrePostFloatDollarFixer
//{
//public:
//    PrePostChecker();
//    ~PrePostChecker();
//
//    void printThisSymbolUsingFunc() const;
//    void printThisSymbolDirectly() const;
//    void printDollarSymbolByCastUsingFunc() const;
//    void printDollarSymbolByScopeUsingFunc() const;
//    void printDollarSymbolByCastDirectly() const;
//    void printDollarSymbolByScopeDirectly() const;
//};
typedef struct pre{
    pre_post_float_dollar_fixer p;
}pre_post_checker;
typedef pre_post_checker* pre_post_checkerptr;
void ppc_init_checker(pre_post_checkerptr this);
/*virtual*/void ppc_destroy_checker(pre_post_checkerptr this);
void ppc_print_this_symbol_using_func(pre_post_checkerptr);
void ppc_print_this_symbol_directly(pre_post_checkerptr);
void ppc_print_dollar_symbol_by_casting_using_func(pre_post_checkerptr);
void ppc_print_dollar_symbol_by_scope_func(pre_post_checkerptr);
void ppc_print_dollar_symbol_by_cast_directly(pre_post_checkerptr);
void ppc_print_dollar_symbol_by_scope_directly(pre_post_checkerptr);
//
//
////// Multiplier ////////////
//
//class Multiplier: public DefaultTextFormatter
//{
//public:
//    Multiplier(int t = 2);
//    ~Multiplier();
//
//    void print(const char*) const;
//    int getTimes() const;
//    void setTimes(int);
//private:
//    int times;
//};
typedef struct multiplier{
    default_text_formmater d;
    int times;
}multiplier;
typedef multiplier* multiplierptr;
///*virtual*/void init_multiplier_i(multiplierptr this,int t);
void destroy_multiplier(multiplierptr this);
void multiplier_print_cptr(multiplierptr this,const char*);
//int multiplier_get_times(multiplierptr this);
//void multiplier_set_times_i(multiplierptr this,int t);

//
////// Multiplier Defs ////////////
//
//inline Multiplier::Multiplier(int t)
//:   times(t)
//{
//    printf("--- Multiplier CTOR: times = %d\n", times);
//}
//

//




#endif // __CPP2C_POLYMORPHISM_H__

