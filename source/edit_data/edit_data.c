#include "../../includes/ifmai.h"
/*
 bir karakteri bir karakter dizisine dönüştürmek için kullanılır.
  Bu amaçla, ilk olarak bir iki boyutlu bir karakter dizisi oluşturulur. 
  Bu dizi, karakterin kendisini ve bir sonlandırıcı karakter olan '\0' karakterini içerir. 
  Ardından, oluşturulan bu dizi, işlev tarafından geri döndürülür.
*/
char *char_to_str(char ch)
{
    char* str = (char*) malloc(2 * sizeof(char)); // '\0' için yer ayırmak için 2 boyutlu char dizisi oluşturulur.
    str[0] = ch;
    str[1] = '\0';
    return str;
}
/*
her döngüde quote'lar atlanır
eğer data bitmemişse
verilen bir karakter dizisindeki değişkenleri değiştirerek düzenlenmiş bir karakter dizisi döndürür. 
Bu işlem, '$' işareti ile başlayan bir alt dize bulunduğunda gerçekleşir. 
Bu işareti takip eden alt dize, bir değişken ismi olarak kabul edilir ve bu isimle ilgili değer, 
işlevin get_variable() yardımcı işlevi tarafından bulunur. 
Değişkenin bulunmasından sonra, alt dize orijinal diziden çıkarılır ve yeni düzenlenmiş karakter dizisi ile değiştirilir. 
eğer değişken yoksa da string'in tek bir char'ı edited'data'ya atanıp joined data ile birleştirilir
Bu işlem, alt dize işlenene kadar devam eder.
*/
char *edit_data(char *substring)
{
	char *edited_data;
	char *joined_data;
	int quote;
	
	quote = 0;
	joined_data = ft_strdup("");
	while (*substring != '\0')
	{
		while (quote_type(*substring, &quote))
			substring++;
		if(*substring != '\0')
		{
			if (quote != 1 && *substring == '$')
			{
				edited_data = get_variable(substring++);
				substring += variable_len(substring);
			}
			else
				edited_data = char_to_str(*substring++);
			joined_data = new_str_join(joined_data, edited_data);
		}
	}
	reset_q_type(quote);
	return (joined_data);
} 
/*
bir karakter dizisine bir karakter eklemek için kullanılır.
*/
char* add_char(char* str, char add_char)
{
    int str_len;
    char* new_str;
	
	str_len = ft_strlen(str);
	new_str = ft_calloc(str_len + 3, 1);
    new_str[0] = add_char;
    ft_memcpy(new_str + 1, str, str_len);
    new_str[str_len + 1] = add_char;
    //new_str[str_len + 2] = '\0';
    free(str);
    return (new_str);
}


char	**double_strdup(char **s1)
{
	char	**rtn;
	int		len;
	int		i;

	i = 0;
	len = chardb_len(s1) + 1;
	rtn = ft_calloc(len, sizeof(char *));
	if (!rtn)
		return (0);
	while(s1[i] != 0)
	{
		rtn[i] = s1[i];
		i++;
	}
	free(s1);
	return (rtn);
}
