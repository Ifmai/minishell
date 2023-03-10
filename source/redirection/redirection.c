#include "../../includes/ifmai.h"

t_data *data;
/*
mevcut dizinin adını alır ve sonuna / karakteri ekleyerek bir simge ekler. 
Bu simge, sonraki I/O yönlendirme işlemlerinde kullanılacaktır.
*/
char *add_symbol()
{
    char	*cwd;
	char	*added;
	char    buff[4096 + 1];

	cwd = getcwd(buff, 4096);
    added= ft_strjoin(cwd,"/");
    return added;
}
/*
fonksiyonu, verilen giriş (input) ve çıkış (output) dosya tanımlayıcılarına göre standart 
dosyaların (STDIN ve STDOUT) yeni tanımlayıcılara yeniden yönlendirilmesini gerçekleştirir. 
Fonksiyon, yeniden yönlendirmenin başarılı olup olmadığını kontrol eder.
*/

// bu fonksiyona gerek kalmayabilir ve ya benim dup2 ya taşıyabilirim file_operations da yapmak yerine....
int set_std_file(int in_fd, int out_fd)
{
    if(0 != in_fd && in_fd > 0)
    {
        dup2(in_fd, 0);
        return in_fd;
    }
    if(1 != out_fd && out_fd > 0)
    {
        dup2(out_fd, 1);
        return out_fd;
    }
    return 0;
}
/*
fonksiyonu, belirtilen dosya işlemi ve simge parametrelerine göre bir dosya açar ve yeni dosya tanımlayıcıları belirler. 
Bu işlem sonunda, set_std_file() fonksiyonu kullanılarak standart dosyaların yeniden tanımlayıcısı yeniden yönlendirilir. 
editlenmiş parametre freelenir
*/
void file_operations(char *redir_param,char *symbol, t_redirection *redir)
{
    char	*edited_param;

    data->in_fd = STDIN_FILENO;// bunlar dataya taşıncak.
    data->out_fd = STDOUT_FILENO;// iki tanesini gereksiz bir fd tutup o fd yi açıp yazıp kapatıcaz gereksiz değişken kullanımı.
	edited_param = ft_strjoin(add_symbol(),redir_param);
	if (macrocomp("<<",symbol))
        data->in_fd = redir->fd_heredoc;
    else if (macrocomp("<",symbol))
        data->in_fd = open(edited_param, O_RDONLY);
	if (macrocomp(">>",symbol))
    	data->out_fd = open(edited_param, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (macrocomp(">",symbol))
    	data->out_fd = open(edited_param, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    /* if(set_std_file(data->in_fd, data->out_fd) == 0)// bu değişebilir... // burda dosyayı açıp değiştirip kapatıp dup2 da açabilirim.
        printf("deneme"); */
    //file didnt opened2
	free(edited_param);
}
/*
bir düğümü listeden kaldırmak için
Fonksiyon, verilen düğümün bir önceki ve bir sonraki düğümle olan bağlantısını keser ve verilen düğümü listeden kaldırır.
*/
/* void remove_node(t_lexer **head, t_lexer *node) 
{
    static int i = 0;
    printf("girdim bro : %d\n",i++);
    if (*head == NULL || node == NULL) 
        return;
    if (*head == node) 
    {  // Eğer silinecek düğüm, listenin başındaysa
        *head = node->next;
    }
    else if (node->next != NULL) 
    {  // Eğer silinecek düğüm listenin sonunda değilse
        node->next->back = node->back;
    }
    else if (node->back != NULL) 
    {  // Eğer silinecek düğüm listenin başında değilse
        node->back->next = node->next;
    }
    free(node->str);
    node->back = NULL;
    node->next = NULL;
    free(node);
} */

 /*
 kelime veya sembol) listesindeki I/O yönlendirmelerini tespit eder ve bu yönlendirmeler için file_operations() fonksiyonunu çağırır. 
 bu yönlendirmelerin belirtilen token'ların listesinden silinmesi için remove_node() fonksiyonu kullanılır.
 */

/* void redirection(t_data *data)
{
    t_lexer *arg;
    t_redirection *redir;
    t_lexer *head;
    int     index;

    arg = data->dvd_str->lexer;
    head = arg;
    redir = data->_redirection;
    index = 0;
    printf("rec\n");
    while(arg != NULL)
    {
        if(is_redir_symbol(arg))
        {
            file_operations(arg->next->str, arg->str,redir);
            remove_node(&(arg->back),arg);// redir verilerininin bağlantısını kopar (şu anki ve next data silinmeli)
            remove_node(&(arg->back),arg);//next data
            // bu silme fonksiyonları çalışmıyor.
        }
        arg = arg->next;
    }
    arg = head;
    while(arg != NULL)
    {
        printf("arg->str : %s\n",arg->str);
        arg = arg->next;
    }
} */

char    **change_command(char **command, int i)
{
    char    **new_command;
    int     j;
    int     index;

    j = 0;
    index = 0;
    new_command = ft_calloc(sizeof(char *) , chardb_len(command) - 1);// 2 değil çünkü null için biri gidiyor.
    while(command[j])
    {
        if(j == i || j == i + 1)
            j++;
        else
        {
            new_command[index] = command[j];
            index++;
            j++;
        }
    }
    return (new_command);
}

char    **redirection(char **command)
{
    //char    **new_command;
    char    **temp;
    int     index;
    int     i;

    i = 0;
    index = 0;
    while(command[i] != 0)
    {
        if(is_redir_symbol_string(command[i]))
        {
            file_operations(command[i + 1] , command[i], data->_redirection);
            temp = change_command(command, i);
            command = double_strdup(temp);
        }
        else
            i++;
    }
    return (command);
}
