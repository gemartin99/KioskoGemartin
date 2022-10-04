#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

int	static	ft_space(char c)
{
	return (
		c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r'
	);
}

int	ft_atoi(char *str)
{
	int				i;
	int				final_value;
	long long int	nbr;

	nbr = 0;
	i = 0;
	final_value = 1;
	while (str[i] && ft_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			final_value = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr < -INT_MIN && final_value == -1)
			return (0);
		if (nbr > INT_MAX && final_value == 1)
			return (-1);
	}
	return (nbr * final_value);
}

char	*get_next_line(int fd)
{
	char	a[999999] = {0};
	char	*new_s;
	int		i = 0;
 
	if (fd < 0)
		return (NULL);
	while (read(fd, &a[i], 1) == 1)
	{
		if (a[i] == '\n')
		{
			
			i++;
			break;
		}
		i++;
	}
	if (!a[0])
		return (NULL);
	new_s = malloc(i + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (a[i])
	{
		new_s[i] = a[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

int main(int argc, char **argv)
{
	char *s = "rm -rf .stock.txt";
	if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'b' && argv[1][2] == '\0')
		system(s);
	FILE *fd2;
	int pan, fideos, aguas, white, kinder, caramelo, kitkat, patatas, dinero, fd;
	int a_pan, a_fideos, a_aguas, a_white, a_kinder, a_caramelo, a_kitkat, a_patatas, a_dinero;

	float a, b, c, d, e, f, g, h, res;
	char *s_pan, *s_fideos, *s_aguas, *s_white, *s_kinder, *s_caramelo, *s_kitkat, *s_patatas, *s_dinero;
	fd = open(".stock.txt", O_RDONLY);
	printf("Inserta el stock de pan 🥖\n");
	scanf("%i", &pan);
	printf("Inserta el stock de fideos 🍜\n");
	scanf("%i", &fideos);
	printf("Inserta el stock de aguas 💧\n");
	scanf("%i", &aguas);
	printf("Inserta el stock de kinder bueno white 🍫\n");
	scanf("%i", &white);
	printf("Inserta el stock de kinder hacendado 🍫\n");
	scanf("%i", &kinder);
	printf("Inserta el stock de barrita caramelo 🍫\n");
	scanf("%i", &caramelo);
	printf("Inserta el stock de kitkat 🍫\n");
	scanf("%i", &kitkat);
	printf("Inserta el stock de patatas 🥔\n");
	scanf("%i", &patatas);
	if (access(".stock.txt", F_OK) != -1)
	{
		s_pan = get_next_line(fd);
		a_pan = ft_atoi(s_pan);
		free(s_pan);
		s_fideos = get_next_line(fd);
		a_fideos = ft_atoi(s_fideos);
		free(s_fideos);
		s_aguas = get_next_line(fd);
		a_aguas = ft_atoi(s_aguas);
		free(s_aguas);
		s_white = get_next_line(fd);
		a_white = ft_atoi(s_white);
		free(s_white);
		s_kinder = get_next_line(fd);
		a_kinder = ft_atoi(s_kinder);
		free(s_kinder);
		s_caramelo = get_next_line(fd);
		a_caramelo = ft_atoi(s_caramelo);
		free(s_caramelo);
		s_kitkat = get_next_line(fd);
		a_kitkat = ft_atoi(s_kitkat);
		free(s_kitkat);
		s_patatas = get_next_line(fd);
		a_patatas = ft_atoi(s_patatas);
		free(s_patatas);
		s_dinero = get_next_line(fd);
		a_dinero = ft_atoi(s_dinero);
		free(s_dinero);
		pan = a_pan - pan;
		fideos = a_fideos - fideos;
		aguas = a_aguas - aguas;
		white = a_white - white;
		kinder = a_kinder - kinder;
		caramelo = a_caramelo - caramelo;
		kitkat = a_kitkat - kitkat;
		patatas = a_patatas - patatas;
		dinero = a_dinero;
		a = 0.13;
		b = 0.10;
		c = 0.31;
		d = 0.17;
		e = 0.20;
		f = 0.24;
		g = 0.15;
		h = 0.15;
		res = (pan * a) + (fideos * b) + (aguas * c) + (white * d) + (kinder * e) + (caramelo * f) + (kitkat * g) + (patatas * h);
		printf("\n\n ⬇️  Productos vendidos hoy ⬇️  \n\n");
		printf("\n🔸 Pan %d\n\n🔸 Fideos %d\n\n🔸 Aguas %d\n\n🔸 White %d\n\n🔸 Kinder %d\n\n🔸 Caramelo %d\n\n🔸 Kitkat %d\n\n🔸 Patatas %d\n\n🔸 Dinero en la hucha la ultima vez %d€\n\n", pan, fideos, aguas, white, kinder, caramelo, kitkat, patatas, dinero);
		printf("Beneficio neto: %.2f€\n", res);
		a = 0.80;
		b = 1.00;
		c = 0.50;
		d = 1.00;
		e = 0.40;
		f = 0.50;
		g = 0.60;
		h = 1.00;
		res = (pan * a) + (fideos * b) + (aguas * c) + (white * d) + (kinder * e) + (caramelo * f) + (kitkat * g) + (patatas * h);
		printf("Beneficio bruto: %.2f€\n", res);
		res = res + dinero;
		printf("En la hucha debe haber %.2f€\n\n", res);
	}
	printf("En la hucha se deja: \n");
	scanf("%i", &dinero);
	fd2 = fopen(".stock.txt","w");
	fprintf(fd2, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", pan, fideos, aguas, white, kinder, caramelo, kitkat, patatas, dinero);
	return (0);
}