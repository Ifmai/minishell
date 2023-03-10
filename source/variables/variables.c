#include "../../includes/ifmai.h"

t_bool is_variable_char(char data)
{
    if(data >= 'A' && data <= 'Z')
        return true;
    else if (data >= 'a' && data <= 'z')
        return true;
    else if(data >= '0' && data <= '9')
        return true;
    else if(data == '_')
        return true;
    else
        return false;
}

int variable_len(char *data)
{
    int len = 0;

    while (data[len] != '\0' &&\
    is_variable_char(data[len]))
        len++;
    return len;
}
/*
İlk olarak, girdinin başındaki '$' işaretinin olup olmadığını kontrol eder. Sonra devam edip etmediğini kontrol edeer.
Eğer varsa, 'variable_len()' fonksiyonunu kullanarak değişken adının uzunluğunu belirler. 
Daha sonra, bu değişken adını geçerli bir değişken olarak kabul eden 'getenv()' işlevini kullanarak değişkenin değerini elde eder. 
Eğer değişken bulunamazsa, boş bir karakter dizisi ("") döndürülür. Eğer '$' işareti yoksa,ya da devam etmiyorsa fonksiyon, girdinin kendisini geri döndürür.
*/
char    *get_variable(char *input)
{
	char	*var_data;
    char	*temp;
	int 	i;

	i = 0;
    if(*input == '$' && *(input+1) != '\0')
	{
		input++;
		i = variable_len(input);
		temp = ft_substr(input,0,i);
		var_data = getenv(temp);
		free(temp);
		if(var_data == NULL)
			var_data = ft_strdup("");
		return (var_data);
	}
	else
		return (input);
}
