#include "../../includes/ifmai.h"

t_data	*data;
/*
bir sınırlayıcı (limiter) karakter dizisi belirtilene kadar kullanıcıdan girdi alır ve
belirtilen dosya tanımlayıcısına (file descriptor) bu girdileri yazar.
Bu fonksiyon, aynı zamanda limiter karakter dizisi tek tırnak içinde mi yoksa çift tırnak içinde mi yer alıyor diye kontrol eder. 
Eğer tek tırnak içindeyse, girdileri tek tırnak içindeki bir karakter dizisi olarak düzenleyerek yazdırır.
Aksi halde, girdileri çift tırnak olarak edit data'ya gönderip editlenmiş datayı yazdırır.
*/
void wait_limiter(char *limiter,int _fd)
{
	t_bool	var_flag;
	char	*input;
	char	*edited_data;

	var_flag = !is_contains_quote(limiter);
	input = readline(">");
	while (!macrocomp(limiter,input))
	{
		if(var_flag)
			edited_data = edit_data(add_char(input,'\"'));//len eksik
		else
			edited_data = edit_data(add_char(input,'\''));//len eksik
		write(_fd, edited_data, ft_strlen(edited_data));
		write(_fd,"\n",1);
		free(edited_data);
		input = readline(">");
	}
	close(_fd);
}
/*
Bu fonksiyon, önceki geçici dosya tanımlayıcısını kapatır ve yeni bir dosya tanımlayıcısı açarak, 
'.heredoc.txt' adlı bir geçici dosyada kullanıcının girdilerini saklar. 
/Girdiler wait_limiter()'in içinde alınır/
bir 'heredoc' (burada belirtilen bir sınırlayıcı karakter dizisi) kullanarak, 
'wait_limiter()' fonksiyonunu çağırır.
*/
void read_heredoc(char *limiter,t_redirection *redir)
{
	if(redir->fd_heredoc)
		close(redir->fd_heredoc);
	redir->fd_heredoc = open("includes/.heredoc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	wait_limiter(limiter,redir->fd_heredoc);
}
/*
belirtilen komut dizgisindeki her bir 'heredoc' öğesi için 'read_heredoc()' fonksiyonunu çağırarak, 
geçici dosyalarda kullanıcının girdilerini saklar. 
Bu fonksiyon ayrıca 'heredoc' yapılandırması için gereken dosya tanımlayıcılarını da yönetir.
Her pipe aralığı index'le belirlenip '|' işareti görüldüğünde index arttırılır.
*/
void init_heredoc(void)
{
	t_redirection *redir;
    t_lexer		*arg;
	t_lexer		*head;//gereksiz.
	int			index;

	index = 0;
	arg = data->dvd_str->lexer;
	head = arg;
	redir = data->_redirection;
    redir = malloc(sizeof(t_redirection)*(data->dvd_str->pipe_count+2));
    while (arg && arg->str)
    {
        if(macrocomp(arg->str,"<<") && arg->next)
            read_heredoc(arg->next->str,&(redir[index])); //heredoc struct
        if(macrocomp(arg->str,"|"))
			index++;
        arg = arg->next;
    }
	arg = head;// gereksiz zaten iter struct kullanıyon *_*
}