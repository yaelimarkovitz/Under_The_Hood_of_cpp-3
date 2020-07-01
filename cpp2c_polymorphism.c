#include "cpp2c_polymorphism_defs.h"
extern voidptr multiplier_arr[2];

void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");
    pre_post_fixer angleBrackets;
    ppf_init_fixer(&angleBrackets,"<<< ", " >>>");
    angleBrackets.dft.t.void_ptr[1](&angleBrackets,"hello world");
    angleBrackets.dft.t.void_ptr[2](&angleBrackets,-777,'\0');
//    angleBrackets.print(-777);
    angleBrackets.dft.t.void_ptr[2](&angleBrackets,350,'#');
    angleBrackets.dft.t.void_ptr[2](&angleBrackets,(long int)3.14,'\0');
//    angleBrackets.print(350, '#');
//    angleBrackets.print(static_cast<long int>(3.14));
    printf("\n--- end doPrePostFixer() ---\n\n");
    ppf_destroy_text(&angleBrackets);
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");
//
    pre_post_dollar_fixer asterisks;
    ppdf_init_fixer_cptrcptr(&asterisks,"*****","*****");
//    PrePostDollarFixer asterisks("***** ", " *****");
//    asterisks.ppf.dft.t.void_ptr[2](&asterisks,-777,'\0');
    ppdf_print_ic(&asterisks,-777,'$');
//    asterisks.print(-777);
    ppdf_print_ic(&asterisks,350,'#');
//    asterisks.print(350, '#');
    ppdf_print_dc(&asterisks,3.14,'$');
//    asterisks.print(3.14f);
//
    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    ppdf_destroy_fixer(&asterisks);
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    pre_post_checker check;
    ppc_init_checker(&check);
    ppc_print_this_symbol_using_func(&check);
    ppc_print_this_symbol_directly(&check);
    ppc_print_dollar_symbol_by_cast_directly(&check);
    ppc_print_dollar_symbol_by_scope_directly(&check);
    ppc_print_dollar_symbol_by_casting_using_func(&check);
    ppc_print_dollar_symbol_by_scope_func(&check);

//    check.printThisSymbolUsingFunc();
//    check.printThisSymbolDirectly();
//    check.printDollarSymbolByCastDirectly();
//    check.printDollarSymbolByScopeDirectly();
//    check.printDollarSymbolByCastUsingFunc();
//    check.printDollarSymbolByScopeUsingFunc();

    printf("\n--- end doPrePostChecker() ---\n\n");
    ppc_destroy_checker(&check);
}
void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    pre_post_float_dollar_fixer hashes;
    ppfdf_init_dollar_fixer_cptrcptr(&hashes,"### ", " ###");
//    PrePostFloatDollarFixer hashes("### ", " ###");
    ppfdf_print_f(&hashes,-777);
//    hashes.print(-777);
    ppfdf_print_fc(&hashes,350,'#');
//    hashes.print(350, '#');
    ppfdf_print_f(&hashes,3.14);
//    hashes.print(3.14f);
    pre_post_dollar_fixer hashes2;
    ppdf_init_fixer_ppdf(&hashes2,&hashes.ppdf);
//    PrePostDollarFixer hashes2(hashes);
    ppdf_print_dc(&hashes2,7.5,'$');
    ppdf_print_ic(&hashes2,100,'$');
//    hashes2.print(7.5);
//    hashes2.print(100);

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
    ppdf_destroy_fixer(&hashes2);
    ppfdf_destroy_dollar_fixer(&hashes);

}

void runAsPrePostFixerRef(const pre_post_fixerptr pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");
    pp->dft.t.void_ptr[2](pp,123,'\0');
    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const pre_post_dollar_fixerptr pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
    ppdf_print_ic(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}
//
void runAsPrePostDollarFixerObj(pre_post_dollar_fixer pp)
{
    pre_post_dollar_fixer new;
    ppdf_init_fixer_ppdf(&new,&pp);
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    ppdf_print_ic(&new,123, '$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
    ppdf_destroy_fixer(&new);
}
//
void runAsPrePostHashFixerRef(const pre_post_hash_fixerptr pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");
    pphf_print_ic(pp,123,'#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");
    multiplier m1;
    multiplier m2;
    multiplier m3;
    multiplier m4;
    init_default_text_formmater(&m1.d);
    m1.d.t.void_ptr=multiplier_arr;
    m1.times=3;
    printf("--- Multiplier CTOR: times = %d\n", 3);
    init_default_text_formmater(&m2.d);
    m2.d.t.void_ptr=multiplier_arr;
    m2.times=5;
    printf("--- Multiplier CTOR: times = %d\n", 5);
//    init_default_text_formmater_dtf()
//    Multiplier m2 = 5;
    init_default_text_formmater_dtf(&m3.d,&m1.d);
    m3.times =m1.times;
    init_default_text_formmater_dtf(&m4.d,&m2.d);
    m4.times =m2.times;
    multiplier_print_cptr(&m1,"abc ");
    multiplier_print_cptr(&m2,"abc ");
    multiplier_print_cptr(&m3,"abc ");
    multiplier_print_cptr(&m4,"abc ");
//    m1.print("abc ");
//    m2.print("abc ");
//    m3.print("abc ");
//    m4.print("abc ");

    printf("\n--- end doMultiplier() ---\n\n");
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");
    pre_post_dollar_fixer d;
    ppdf_init_fixer_cptrcptr(&d,"!!!","!!!");
    default_text_formmater d1,d2,d3;
    init_default_text_formmater_dtf(&d1,&d.ppf.dft);
    ppdf_destroy_fixer(&d);
    multiplier m;
    init_default_text_formmater(&m.d);
    m.d.t.void_ptr=multiplier_arr;
    m.times=4;
    printf("--- Multiplier CTOR: times = %d\n", 4);
    init_default_text_formmater_dtf(&d2,&m.d);
    destroy_multiplier(&m);
    pre_post_checker p;
    ppc_init_checker(&p);
    printf("%d \n",p.p.ppdf.ppf.dft.id);
    init_default_text_formmater_dtf(&p.p.ppdf.ppf.dft , &d3);
    ppc_destroy_checker(&p);
    default_text_formmater formatters[] =
    {
            d1,d2,d3
    };

    for (int i = 0; i < 3; ++i)
        v_dft_print_cptr(&formatters[i],"hello world");
//        formatters[i].print("Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
    dtf_destroy_text(&d1);
    dtf_destroy_text(&d2);
    dtf_destroy_text(&d3);
}
//
void doFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");
    pre_post_dollar_fixer d;
    ppdf_init_fixer_cptrcptr(&d,"!!!","!!!");
    multiplier m;
    init_default_text_formmater(&m.d);
    m.d.t.void_ptr=multiplier_arr;
    m.times=4;
    printf("--- Multiplier CTOR: times = %d\n", 4);
    pre_post_checker p;
    ppc_init_checker(&p);
    default_text_formmaterptr pfmt[3] =
    {
            (default_text_formmaterptr)(&d),
            (default_text_formmaterptr)(&m),
            (default_text_formmaterptr)(&p)

    };

    for (int i = 0; i < 3; ++i)
        pfmt[i]->t.void_ptr[1](pfmt[i],"Hello World!");
    ppc_destroy_checker(&p);
    destroy_multiplier(&m);
    ppdf_destroy_fixer(&d);

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    default_text_formmaterptr formatters = dft_generateFormatterArray();

    for (int i = 0; i < 3; ++i)
        formatters[i].t.void_ptr[1](&formatters[i],"Hello World!");
//    delete[] formatters;
    for (int j = 0; j <3; ++j) {
        dtf_destroy_text(&formatters[j]);
    }
    printf("\n--- end doFormatterDynamicArray() ---\n\n");
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    pre_post_hash_fixer hfix;
    pphf_init_hash_fixer_i(&hfix,4);
    runAsPrePostFixerRef((pre_post_fixerptr)&hfix);
    runAsPrePostDollarFixerRef((pre_post_dollar_fixerptr)&hfix);
    runAsPrePostDollarFixerObj((hfix.ppdt));
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();
    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");
    pphf_destroy_hash_fixer(&hfix);

    return 0;
}



