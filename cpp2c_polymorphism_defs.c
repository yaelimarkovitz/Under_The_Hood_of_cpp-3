#include "cpp2c_polymorphism_defs.h"
#include <stdlib.h>
int default_text_formatter_ider_text_id;
int default_text_formatter_ider_next_id = 0;
//int DefaultTextFormatter::Ider::next_id = 0;
//using std::printf;
voidptr tf_arr[2] = {(voidptr)tf_destroy,NULL};
voidptr dtf_arr[2] = {(voidptr)dtf_destroy_text,(voidptr)v_dft_print_cptr};
voidptr ppf_arr[4]={(voidptr)ppf_destroy_text,(voidptr)v_ppf_print_cptr,(voidptr)v_ppf_print_lc,(voidptr)ppf_get_default_symbol};
voidptr ppdf_arr[4]={(voidptr)ppdf_destroy_fixer,(voidptr)v_ppf_print_cptr,(voidptr)ppdf_print_lc,(voidptr)ppdf_get_default_symbol};
voidptr pphf_arr[4]={(voidptr)pphf_destroy_hash_fixer,(voidptr)v_ppf_print_cptr,(voidptr)pphf_print_lc,(voidptr)pphf_get_default_symbol};
voidptr ppfdf_arr[4]={(voidptr)ppfdf_destroy_dollar_fixer,(voidptr)v_ppf_print_cptr,(voidptr)ppdf_print_lc,(voidptr)ppfdf_get_default_symbol};
voidptr ppc_arr[4]={(voidptr)ppc_destroy_checker,(voidptr)v_ppf_print_cptr,(voidptr)ppdf_print_lc,(voidptr)ppfdf_get_default_symbol};
voidptr multiplier_arr[2]={(voidptr)destroy_multiplier,(voidptr)multiplier_print_cptr};
void init_text_formatter(text_formatter* this){
    this->void_ptr=tf_arr;
}

////// DefaultTextFormatter Defs ////////////

//DefaultTextFormatter::DefaultTextFormatter()
//:   id(Ider::getId())
//{
//    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", id);
//}
void tf_destroy(text_formatter* this){}

void init_default_text_formmater(default_text_formmaterptr this){
    this->id = default_text_formatter_ider_next_id++;
    this->t.void_ptr=dtf_arr;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
//DefaultTextFormatter::DefaultTextFormatter(const DefaultTextFormatter& other)
//:   id(Ider::getId())
//{
//    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other.id, id);
//}
void init_default_text_formmater_dtf(default_text_formmaterptr this , const default_text_formmaterptr other){
    this->t = other->t;
    printf("%d \n",other->id);
    this->id = default_text_formatter_ider_next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}
//DefaultTextFormatter& DefaultTextFormatter::operator=(const DefaultTextFormatter& other)
//{
//    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other.id, id);
//    return *this;
//}
default_text_formmaterptr dtf_assignment(default_text_formmaterptr this,default_text_formmaterptr other){
    this->t = other->t;

    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}
//void DefaultTextFormatter::print(const char* text) const
//{
//    printFunc("[DefaultTextFormatter::print(const char*)]");
//    printf("%s\n", text);
//}
void v_dft_print_cptr(default_text_formmaterptr this,const char* text){
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n",text);
}
//DefaultTextFormatter::~DefaultTextFormatter()
//{
//    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", id);
//}
void dtf_destroy_text(default_text_formmaterptr this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
    tf_arr[0](this);
}
//DefaultTextFormatter* generateFormatterArray()
//{
//    return new DefaultTextFormatter[3];
//}
default_text_formmaterptr dft_generateFormatterArray(){
    default_text_formmaterptr new = malloc(sizeof(default_text_formmater)*3);
    for (int i = 0; i < 3; ++i) {
        default_text_formmater tmp;
        init_default_text_formmater(&tmp);
        *(new+i) = tmp;
    }
    return new;
}

////// PrePostFixer Defs ////////////
//PrePostFixer::PrePostFixer(const char* prefix, const char* postfix)
//:   pre(prefix)
//,   post(postfix)
//{
//    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", pre, post);
//}
void ppf_init_fixer(pre_post_fixerptr this,const char* prefix, const char* postfix){
    init_default_text_formmater(&this->dft);
    this->dft.t.void_ptr = ppf_arr;
    this->pre=prefix;
    this->post=postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}
//PrePostFixer::~PrePostFixer()
//{
//    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", pre, post);
//}
void ppf_destroy_text(pre_post_fixerptr this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre,this-> post);
    dtf_destroy_text(&this->dft);
}
//void PrePostFixer::print(const char* text) const
//{
//    printFunc("[PrePostFixer::print(const char*)]");
//    printf("%s%s%s\n", pre, text, post);
//}
/*virtual*/void v_ppf_print_cptr(pre_post_fixerptr this,const char* text){
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n",this->pre, text,this->post);
}
/*virtual*/void v_ppf_print_lc(pre_post_fixerptr this,long num , char symbol){
    printf("%-60s | ","[PrePostFixer::print(long, char)]");
    printf("-->\n");
    if (symbol) {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    }
    else{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }

}
/*virtual*/char ppf_get_default_symbol(pre_post_fixerptr this){
    return '@';
}

////// PrePostDollarFixer Defs ////////////
//PrePostDollarFixer::PrePostDollarFixer(const char* prefix, const char* postfix)
//:   PrePostFixer(prefix, postfix)
//{
//    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
void ppdf_init_fixer_cptrcptr(pre_post_dollar_fixerptr this,const char* prefix, const char* posfix){
    ppf_init_fixer(&this->ppf,prefix,posfix);
    this->ppf.dft.t.void_ptr = ppdf_arr;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
}
//PrePostDollarFixer::PrePostDollarFixer(const PrePostDollarFixer& other)
//:   PrePostFixer(other)
//{
//    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
void ppdf_init_fixer_ppdf(pre_post_dollar_fixerptr this,const pre_post_dollar_fixerptr other){
    ppf_init_fixer(&this->ppf,other->ppf.pre,other->ppf.post);
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
}
//PrePostDollarFixer::~PrePostDollarFixer()
//{
//    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
/*virtual*/void ppdf_destroy_fixer(pre_post_dollar_fixerptr this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->ppf.pre, this->ppf.post);
    (*ppf_arr)(this);
}
//void PrePostDollarFixer::print(long num, char symbol) const
//{
//    printFunc("[PrePostDollarFixer::print(long, char)]");
//    printf("-->\n");
//
//    PrePostFixer::print(num, symbol);
//}
/*virtual*/void ppdf_print_lc(pre_post_dollar_fixerptr this,long num, char symbol ){
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    this->ppf.dft.t.void_ptr = ppf_arr;
    this->ppf.dft.t.void_ptr[2](&this->ppf,num,symbol);
    this->ppf.dft.t.void_ptr=ppdf_arr;
}
//void PrePostDollarFixer::print(int num, char symbol) const
//{
//    printFunc("[PrePostDollarFixer::print(int, char)]");
//    printf("-->\n");
//
//    print(long(num), symbol);
//}
void ppdf_print_ic(pre_post_dollar_fixerptr this,int num, char symbol ){
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    this->ppf.dft.t.void_ptr[2](this,num,symbol);
}
//void PrePostDollarFixer::print(double num, char symbol) const
//{
//    printFunc("[PrePostDollarFixer::print(double, char)]");
//    printf("%s%c%f%s\n", getPrefix(), symbol, num, getPostfix());
//}
void ppdf_print_dc(pre_post_dollar_fixerptr this,double num, char symbol ){
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this->ppf.pre, symbol, num, this->ppf.post);
}
/*virtual*/char ppdf_get_default_symbol(pre_post_dollar_fixerptr this){
    return '$';
}

////// PrePostHashFixer Defs ////////////
//PrePostHashFixer::PrePostHashFixer(int prc)
//:   PrePostDollarFixer("===> ", " <===")
//,   precision(prc)
//{
//    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", getPrefix(), getPostfix(), precision);
//
//    print(9999.9999);
//}
void pphf_init_hash_fixer_i(pre_post_hash_fixerptr this, int prc){
    ppdf_init_fixer_cptrcptr(&this->ppdt,"===> ", " <===");
    this->ppdt.ppf.dft.t.void_ptr=pphf_arr;
    this->precision = prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->ppdt.ppf.pre, this->ppdt.ppf.post ,this->precision);
    pphf_print_dc(this,9999.9999,'#');
}
//PrePostHashFixer::~PrePostHashFixer()
//{
//    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
/*virtual*/void pphf_destroy_hash_fixer(pre_post_hash_fixerptr this){
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->ppdt.ppf.pre, this->ppdt.ppf.post);
    ppdf_arr[0](this);
}
//void PrePostHashFixer::print(long num, char symbol) const
//{
//    printFunc("[PrePostHashFixer::print(long, char)]");
//    printf("-->\n");
//
//    print(double(num), symbol);
//}
/*virtual*/void pphf_print_lc(pre_post_hash_fixerptr this,long num ,char symbol){
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");
    pphf_print_dc(this,(num),symbol);
}
//void PrePostHashFixer::print(int num, char symbol) const
//{
//    printFunc("[PrePostHashFixer::print(int, char)]");
//    printf("-->\n");
//
//    print(double(num), symbol);
//}
void pphf_print_ic(pre_post_hash_fixerptr this,int num ,char symbol){
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");
    pphf_print_dc(this,(num),symbol);
}
//inline void PrePostHashFixer::print(double num, char symbol) const
//{
//    printFunc("[PrePostHashFixer::print(double, char)]");
//
//    printf("%s[%c%.*f]%s\n", getPrefix(), symbol, precision, num, getPostfix());
//}
void pphf_print_dc(pre_post_hash_fixerptr this, double num ,char symbol){
    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->ppdt.ppf.pre, symbol, this->precision, num, this->ppdt.ppf.post);
}
/*virtual*/char pphf_get_default_symbol(pre_post_hash_fixerptr this){
    return '#';
}

////// PrePostFloatDollarFixer Defs ////////////
//PrePostFloatDollarFixer::PrePostFloatDollarFixer(const char* prefix, const char* postfix)
//:   PrePostDollarFixer(prefix, postfix)
//{
//    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
void ppfdf_init_dollar_fixer_cptrcptr(pre_post_float_dollar_fixerptr this, const char* prefix,const char* postfix){
    ppdf_init_fixer_cptrcptr(&this->ppdf,prefix,postfix);
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->ppdf.ppf.pre, this->ppdf.ppf.post);
}
//PrePostFloatDollarFixer::~PrePostFloatDollarFixer()
//{
//    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
/*virtual*/void ppfdf_destroy_dollar_fixer(pre_post_float_dollar_fixerptr this){
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->ppdf.ppf.pre, this->ppdf.ppf.post);
    ppdf_arr[0](this);
}
//void PrePostFloatDollarFixer::print(float num) const
//{
//    printFunc("[PrePostFloatDollarFixer::print(float)]");
//    printf("-->\n");
//
//    print(num, DEFAULT_SYMBOL);
//}
void ppfdf_print_f(pre_post_float_dollar_fixerptr this, float num){
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");
    ppfdf_print_fc(this,num,'@');
}
//void PrePostFloatDollarFixer::print(float num, char symbol) const
//{
//    printFunc("[PrePostFloatDollarFixer::print(float, char)]");
//
//    printf("%s%c%.2f%s\n", getPrefix(), symbol, num, getPostfix());
//}
void ppfdf_print_fc(pre_post_float_dollar_fixerptr this, float num, char symbol){
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2f%s\n", this->ppdf.ppf.pre, symbol, num, this->ppdf.ppf.post);
}
/*virtual*/char ppfdf_get_default_symbol(pre_post_float_dollar_fixerptr this){
    return '@';
}


//

//
////// PrePostChecker Defs ////////////
//PrePostChecker::PrePostChecker()
//:   PrePostFloatDollarFixer("[[[[ ", " ]]]]")
//{
//    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
void ppc_init_checker(pre_post_checkerptr this){
    ppfdf_init_dollar_fixer_cptrcptr(&this->p,"[[[[ ", " ]]]]");
    this->p.ppdf.ppf.dft.t.void_ptr=ppc_arr;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->p.ppdf.ppf.pre, this->p.ppdf.ppf.post);
}
//PrePostChecker::~PrePostChecker()
//{
//    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
//}
/*virtual*/void ppc_destroy_checker(pre_post_checkerptr this){
    printf("--- PrePostChecker DTOR: \"%s\"...\"%s\"\n", this->p.ppdf.ppf.pre, this->p.ppdf.ppf.post);
    ppfdf_arr[0](this);
}
//void PrePostChecker::printThisSymbolUsingFunc() const
//{
//    printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");
//
//    printf("Default symbol is %c\n", this->getDefaultSymbol());
//}
void ppc_print_this_symbol_using_func(pre_post_checkerptr this){
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");
    printf("Default symbol is %c\n", ((char(*)(const void* const))(this->p.ppdf.ppf.dft.t.void_ptr[3]))(this));
}
//void PrePostChecker::printThisSymbolDirectly() const
//{
//    printFunc("[PrePostChecker::printThisSymbolDirectly()]");
//
//    printf("Default symbol is %c\n", this->DEFAULT_SYMBOL);
//}
void ppc_print_this_symbol_directly(pre_post_checkerptr this){
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");
    printf("Default symbol is %c\n",'@');
}
//void PrePostChecker::printDollarSymbolByCastUsingFunc() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
//
//    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->getDefaultSymbol());
//}
void ppc_print_dollar_symbol_by_casting_using_func(pre_post_checkerptr this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
    this->p.ppdf.ppf.dft.t.void_ptr=ppfdf_arr;
    printf("Default symbol is %c\n",((char(*)(const void* const))(this->p.ppdf.ppf.dft.t.void_ptr[3]))(this));
    this->p.ppdf.ppf.dft.t.void_ptr=ppc_arr;
}
//void PrePostChecker::printDollarSymbolByScopeUsingFunc() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
//
//    printf("Default symbol is %c\n", this->PrePostDollarFixer::getDefaultSymbol());
//}
void ppc_print_dollar_symbol_by_scope_func(pre_post_checkerptr this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
    printf("Default symbol is %c\n", '$');
}
//void PrePostChecker::printDollarSymbolByCastDirectly() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");
//
//    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->DEFAULT_SYMBOL);
//}
void ppc_print_dollar_symbol_by_cast_directly(pre_post_checkerptr this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByCastDirectly()]");
    this->p.ppdf.ppf.dft.t.void_ptr=ppdf_arr;
    printf("Default symbol is %c\n",((char(*)(const void* const))(this->p.ppdf.ppf.dft.t.void_ptr[3]))(this));
    this->p.ppdf.ppf.dft.t.void_ptr=ppc_arr;
}
//void PrePostChecker::printDollarSymbolByScopeDirectly() const
//{
//    printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");
//
//    printf("Default symbol is %c\n", this->PrePostDollarFixer::DEFAULT_SYMBOL);
//}
void ppc_print_dollar_symbol_by_scope_directly(pre_post_checkerptr this){
    printf("%-60s | ","[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
    printf("Default symbol is %c\n",'$');
}

////// Multiplier Defs ////////////

//inline Multiplier::~Multiplier()
//{
//    printf("--- Multiplier DTOR: times = %d\n", times);
//}
void destroy_multiplier(multiplierptr this){
    printf("--- Multiplier DTOR: times = %d\n", this->times);
    dtf_arr[0](this);
}
//void Multiplier::print(const char* text) const
//{
//    printFunc("[Multiplier::print(const char*)]");
//
//    for (int i = 0; i < times; ++i)
//        printf("%s", text);
//    printf("\n");
//}
void multiplier_print_cptr(multiplierptr this,const char* text){
    printf("%-60s | ","[Multiplier::print(const char*)]");
    for (int i = 0; i < this->times; ++i) {
        printf("%s",text);
    }
    printf("\n");
}


