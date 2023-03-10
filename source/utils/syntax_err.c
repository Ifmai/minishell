#include "../../includes/ifmai.h"
/*
 bir t_lexer yapısının str öğesinin < veya > sembolüne eşit olup olmadığını kontrol eder.
 Eğer sembol bu karakterlerden birine eşitse, TRUE döndürülür; aksi halde FALSE döndürülür.
*/
t_data  *data;

t_bool is_redir_symbol(t_lexer *lexer)
{
    if (macrocomp(lexer->str,"<") || macrocomp(lexer->str,">"))
        return TRUE;
    return FALSE;
}

/*
mevcut t_lexer yapısının üzerinde gezinir ve <, > sembollerini kontrol eder. 
Eğer bir sembol bulunursa, hemen sonrasındaki t_lexer yapısının sembol olup olmadığı kontrol edilir. Eğer sembol değilse veya yoksa, | sembolüne eşit değilse, syntax hatası olduğu sonucuna varılır ve TRUE döndürülür. Aksi halde, gezinme işlemine devam edilir.

*/

t_bool syntax_err()
{
    t_lexer *head;
    t_lexer *lexer;

    lexer = data->dvd_str->lexer;
    head = lexer;
    while (lexer && lexer->str)
    {
        if(macrocomp(lexer->str,"<") || macrocomp(lexer->str,">"))
        {
            if (!(lexer->next)||is_redir_symbol(lexer->next) || macrocomp(lexer->str,"|"))
            {
                lexer->next = NULL;//freeleme konulabilir
                lexer = head;
                return TRUE;
            }
        }
            lexer = lexer->next;
    }
    lexer = head;
    return FALSE;
}