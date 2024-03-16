#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double res = 0.;

unsigned long long fact(unsigned long n)
{

	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact(n - 1);
	}
}

unsigned long long pgcd(unsigned long long m, unsigned long long n)
{

	unsigned long long tmp;
	if (n > m)
	{

		tmp = n;
		n = m;
		m = tmp;
	}

	tmp = m % n;
	while (tmp != 0)
	{

		m = n;
		n = tmp;
		tmp = m % n;
	}
	return n;
}

unsigned long long ppcm(unsigned long long m, unsigned long long n)
{

	return (m * n) / pgcd(m, n);
}

/*Puissance : pow(base, exp);*/

double eval(double a, double b, char c) {
	
	switch (c)
		{

		case '+':
			res = a + b;
			break;
		case '-':
			res = a - b;
			break;
		case '*':
			res = a * b;
			break;
		case '/':
			if(b != 0) res = a / b;
			else printf("Math error\n");
			break;
		case '%':
			res = (unsigned long long)a % (unsigned long long)b;
			break;
		case '^':
			res = pow(a, b);
			break;
		case '!':
			res = fact((unsigned long)a);
			break;
		case 'p':
			res = ppcm((unsigned long long)a, (unsigned long long)b);
			break;
		case 'g':
			res = pgcd((unsigned long long)a, (unsigned long long)b);
			break;
		default:
			printf("Operation invalide \n");
	}
	return res;
}

int main(void)
{

	printf("Bienvenue dans Kajio...\n\n"

		   "Les operations sont identifié par un caractère: \n"
		   "\t-Addition: + \n"
		   "\t-Soustraction: - \n"
		   "\t-Multiplication: * \n"
		   "\t-Division: / \n"
		   "\t-Factorielle: ! \n"
		   "\t-Reste(modulo): %% \n"
		   "\t-PGCD: g \n"
		   "\t-PPCM: p \n\n"

		   "- On prend en charge seulement deux operandes\n"
		   "- Kajio memorise le resultat de la dernière opération et l'utilise comme opérande"
		   " s'il en manque un \n (ex: '5 *' pour multiplier le dernier resultat par 5).\n"
		   "- Entrez 'q' pour quitter Kajio\n\n"

	);

	while (1)
	{

		double a, b;
		char op;
		char entry[256];

		printf("/> ");
		fgets(entry, sizeof(entry), stdin);
		int n = sscanf(entry, "%lf %c %lf", &a, &op, &b);

		int quit = 0, i = 0;
		while(entry[i] != '\0') if(entry[i++] == 'q') quit = 1;


		if(quit)
		{
			printf("\nVous venez de quitter Kajio... \n\n");
			break;
		}


		if(n < 2) continue;
		if(n == 2) b = res;
		
		eval(a, b, op);
		if(!(op == '/' && b == 0)) printf("%.2lf \n", res);
	}

	return 0;
}