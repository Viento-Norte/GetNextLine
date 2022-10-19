//###
#include"get_next_line.h"
//#include"utils.h"
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
//All test wiht gcc -Wall -Werror -Wextra -fsanitize=address//
/*/###############===CHECH FREE_MEMORY & CREATE_MZERO===##############

int main (void)
{
char	*str;
char	str1[]= "HOLA mundo\n";
int		c;
char		*p;

c = -1;
p = NULL;
str = create_mzero(sizeof(char) * 12);
while (str1[++c])
	str[c] = str1[c];
ft_putstr(str);
free_memory(NULL,&p);
free_memory(&str,0);
return(0);
}*/
/*/##############===CHECK HAVE_NEWLINE===##############
int main (void)
{
char	str1[] = "HOLA MUNDO";
char	str2[] = "hola,\n mundo";
char	str3[] = "";
char	str4[] = "\n\n\n\n";
char	str5[] = "\n";
char	*str;

str = NULL;
ft_putstr(str1);
ft_putstr(" have a new line? [expected NO] result: ");
if (have_newline(str1))
	ft_putstr("YES");
	else
	ft_putstr("NO");
ft_putstr("\n");
ft_putstr(str2);
ft_putstr(" have a new line? [expected YES] result: ");
if (have_newline(str2))
	ft_putstr("YES");
	else
	ft_putstr("NO");
ft_putstr("\n");
ft_putstr(str3);
ft_putstr(" \"\" have a new line? [expected NO] result: ");
if (have_newline(str3))
	ft_putstr("YES");
	else
	ft_putstr("NO");
ft_putstr("\n");
ft_putstr(str);
ft_putstr(" *(NULL) have a new line? [expected NO] result: ");
if (have_newline(str))
	ft_putstr("YES");
	else
	ft_putstr("NO");
ft_putstr("\n");
ft_putstr(" \\n\\n\\n\\n have a new line? [expected YES] result: ");
if (have_newline(str4))
	ft_putstr("YES");
	else
	ft_putstr("NO");
ft_putstr("\n");
ft_putstr(" \\n have a new line? [expected YES] result: ");
if (have_newline(str5))
	ft_putstr("YES");
	else
	ft_putstr("NO");
}*/
/*//###############===CHECK LEN_LINE===############
int main (void)
{
char	str1[] = "HOLA MUNDO";
char	str2[] = "hola,\n mundo";
char	str3[] = "";
char	str4[] = "\n\n\n\n";
char	str5[] = "\n";
char	*str;

str = NULL;
ft_putstr(str1);
ft_putstr("\nlen_line(\"HOLA MUNDO\") = 10 [expected]\n result = ");
ft_putnbr(len_line(str1));
ft_putstr("\n");
ft_putstr(str2);
ft_putstr("\nlen_line(\"hola,\\n mundo\") = 6 [expected]\n result = ");
ft_putnbr(len_line(str2));
ft_putstr("\n");
ft_putstr(str3);
ft_putstr("\nlen_line(\"\") = 0 [expected]\n result = ");
ft_putnbr(len_line(str3));
ft_putstr("\n");
ft_putstr(str);
ft_putstr("\nlen_line(NULL) = 0 [expected]\n result = ");
ft_putnbr(len_line(str));
ft_putstr("\n");
ft_putstr("\nlen_line(\"\\n\\n\\n\\n\") = 1 [expected]\n result = ");
ft_putnbr(len_line(str4));
ft_putstr("\n");
ft_putstr("\nlen_line(\"\\n\") = 1 [expected]\n result = ");
ft_putnbr(len_line(str5));
ft_putstr("\n");

return(0);
}*/
/*/###########===CHECK STRJOIN===###########################
int main (void)
{
char	str1[] = "HOLA MUNDO";
char	str2[] = "hola, \n mundo";
char	str3[] = "";
char	str4[] = "\n\n\n\n";
char	str5[] = "\n";
char 	*str ;
char 	*out;

str = NULL;
ft_putstr("str1 = \"HOLA MUNDO\" \nstr2 = \"hola, \\n mundo\" \nstr3 = \"\" \n*str *(NULL)");
ft_putstr("\nstr4 = \"\\n\\n\\n\\n\" str5 = \"\\n\" \n");
out = strjoin(str1, str2);
ft_putstr("\nOut1 [strjoin(str1, str2)]: ");
ft_putstr(out);
free_memory(&out,NULL);
out = strjoin(str2, str1);
ft_putstr("Out2 [strjoin(str2, str1)]:");
ft_putstr(out);
free_memory(&out,NULL);
out = strjoin(str, str1);
ft_putstr("Out3 [strjoin(str, str1)]: ");
ft_putstr(out);
free_memory(&out,NULL);
out = strjoin(str2, str3);
ft_putstr("Out4 [strjoin(str2, str3)]: ");
ft_putstr(out);
free_memory(&out,NULL);
out = strjoin(str3, str2);
ft_putstr("Out5 [strjoin(str3, str2)]: ");
ft_putstr(out);
free_memory(&out,NULL);
out = strjoin("", str1);
ft_putstr("Out6 [strjoin(\"\", str1)]: ");
ft_putstr(out);
free_memory(&out,NULL);

out = strjoin("", str4);
ft_putstr("Out7 [strjoin(\"\", str4)]: ");
ft_putstr(out);
free_memory(&out,NULL);

out = strjoin("", str5);
ft_putstr("Out8 [strjoin(\"\", str5)]: ");
ft_putstr(out);
free_memory(&out,NULL);

return(0);
}
*/
//##############====CHECK GET NEXT LINE==#############################################
int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int		count;

	//(void)argc;			// Casting argc to quiet the compiler's warnings.
	fd = open(argv[1], O_RDONLY); 	// Open the file given as an argument at program launch
	line = "";			// Initialize this variable to be able to use it in the following loop
	count = 0;
	while (line != NULL)
	{
		count++;
		line = get_next_line(fd);
		//ft_putstr("Line ");
		//ft_putnbr(++count);
		//ft_putstr(": ");
		//ft_putstr(line);
		printf("Line%i: %s",count,line);
		getchar();	
		free(line);
		
	}
	fd = close(fd);
	//free(line);
	return (0);
}
