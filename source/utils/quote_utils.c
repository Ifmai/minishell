#include "../../includes/ifmai.h"
/*
quote içerip içermediğini kontrol eder (herhangi bir işaret görürse(quote) direkt TRUE döndürür)
*/
t_bool is_contains_quote(char *input)
{
    while (*input)
    {
        if(*input =='\''|| *input == '\"')
            return TRUE;
        input++;
    }
    return FALSE;
}

/*
quote_type:
It allows us to understand whether double quotes or single quotes come first.
*/
int quote_type(char quote,int *q_hold)
{
    static int hold = 0;

    if (quote == '\'' || quote == '\"')
    {
        if(quote == '\''&&(hold == 0 || hold == 1))
        {
            *q_hold = Qt(*q_hold,1);
            if(hold == 0)
                hold = 1;
            else if(hold == 1)
                hold = 0;
            return (1);
        }
		else if(quote == '\"' && (hold == 0 || hold == 2 )){
            *q_hold = Qt(*q_hold,2);
            if(hold == 0)
                hold = (2);
            else if (hold == 2)
                hold = 0;
            return(2);}
    }
    return 0;
}

/*
reset_q_type:
to not leave the static variable open
*/
void reset_q_type(int q_hold)
{
    if(q_hold == 0)
        return;
    else if(q_hold == 1)
        quote_type('\'',&q_hold);
    else
        quote_type('\"',&q_hold);
}
