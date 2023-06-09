/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Turma 94 - Prof. Luciano Digiampietri                         **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   Miguel de Menezes Silva                      12891223         **/
/**                                                                 **/
/*********************************************************************/

/*
	Implementacao de diversas funcoes matematicas
*/

#include <stdio.h>

/*
  Funcao somaDigitos(int valor): esta funcao devera receber um numero
	inteiro como parametro (valor}). Se este numero for menor ou igual
	a zero ou maior que 99999, a funcao devera retornar o valor -1.
  Caso contrario, a funcao devera somar os digitos do numero de acordo com suas
	unidades, dezenas, centenas, milhares e dezenas de milhares e retornar esta
	soma.
  Por exemplo, para o numero 2345, deve retornar 14 que corresponde a:
	2 + 3 + 4 + 5.

  Parametro:
	valor - Valor inteiro a ter seus digitos somados
*/
int somaDigitos(int valor)
{
	int soma = 0;

	/* COMPLETE A IMPLEMENTACAO DA FUNCAO*/

	if (valor <= 0 || valor > 99999)
	{
		return -1;
	}
	else
	{

		while (valor > 0)
		{
			soma = soma + (valor % 10); // % faz o retorno do resto da divisão
			valor = (int)(valor / 10);
		}
	}

	return soma;
}

/*
  Funcao somaIntervalo(int inicio, int fim): esta funcao devera receber dois
	numeros inteiro (inicio e fim).
  Se qualquer desses numeros for negativo ou nulo a funcao devera retornar -1;
  Se o valor de fim for menor do que o valor de inicio, a funcao tambem devera
	retornar -1.
  Caso contrario, a funcao devera retornar a soma de todos os numeros inteiros
	de inicio ate fim. Por exemplo, para inicio=3 e fim=4, a funcao devera
	retornar 7, valor obtido pela soma dos seguintes valores: 3 + 4.
  Ja para inicio=3 e fim=6, a funcao devera retornar 18, valor obtido pela
	soma dos seguintes valores: 3 + 4 + 5 + 6.

  Parametros:
	inicio - Valor inteiro que representa o inicio do intervalo
	fim - Valor inteiro que representa o fim do intervalo
*/
int somaIntervalo(int inicio, int fim)
{
	int resultado = 0;

	if (inicio <= 0 || fim <= 0 || fim < inicio) // realiza as verificações
	{
		return -1; // se der errado, retorna -1
	}
	else
	{
		for (int i = inicio; i <= fim; i++)
		{
			resultado += i; // incrementa no resultado
		}
	}

	return resultado;
}

/*
  Funcao somaInteiros(int inicio, int limite): esta funcao devera receber
	dois numeros inteiro (inicio e limite).
  Se qualquer desses numeros for negativo ou nulo a funcao devera retornar -1;
  Se o valor de limite for menor do que o valor de inicio, a funcao tambem
	devera retornar -1.
  Caso contrario, a funcao devera retornar o maior valor da soma dos inteiros
	consecutivos a partir de inicio, desde que esse valor seja menor ou igual
	ao valor de limite.
  Por exemplo, para inicio=3 e limite=5, a funcao devera retornar 3, valor
	obtido apenas pelo numero inicial: 3 (pois se somarmos 3 e 4 a soma sera 7
	que e maior do que o limite).
  Ja para inicio=4 e limite=17, a funcao devera retornar 15, valor obtido pela
	soma dos seguintes valores: 4 + 5 + 6 (se, adicionalmente, somarmos 7,
	o valor ultrapassaria o valor de limite).

  Parametros:
	inicio - Primeiro valor a participar da soma
	limite - Valor limitante para a soma dos inteiros (a soma devera ser menor
			 ou igual a este valor)
*/
int somaInteiros(int inicio, int limite)
{
	int soma = 0;
	// int somaFinal = inicio;  //n sei se pode add outras variaveis

	if (inicio <= 0 || limite <= 0 || limite < inicio)
	{
		return -1;
	}
	else
	{
		/* n sabia se poderia criar/usar outras variáveis, então refiz a função */

		// enquanto soma for menor q limite => ADD +1
		// for (int i = inicio + 1; soma <= limite; i++)
		// {
		// 	soma += i; // add +1 na soma
		// 	// quando soma for <= limite e soma > soma final
		// 	// soma final existe pq quando soma > "valor ideal" ele n add mais
		// 	if (soma > somaFinal && soma <= limite)
		// 	{
		// 		somaFinal = soma;
		// 	}
		// }
		soma = inicio;

		for (int i = inicio + 1; soma <= limite; i++)
		{
			soma += i;
			if (soma > limite)
				return soma - i;
		}
	}

	return soma;
}

/*
  Funcao dividindoPorDois(double valor, int divisoes): esta funcao devera
	receber um numero real (valor) e um numero inteiro (divisoes).
  Se o valor de divisoes for nulo ou negativo, a funcao devera retornar -1.
  Caso contrario, a funcao devera retornar o resultado de valor/2^divisoes
	(isto e, valor dividido por dois elevado a divisoes).
  Este resultado devera ser obtido a partir de sucessivas divisoes.
  Por exemplo, para valor=8 e divisoes=4, a funcao devera retornar 0.5,
	valor obtido pela seguinte conta: 8/2/2/2/2.

  Parametros:
	valor - Dividendo inicial da divisao (valor que sera dividido sucessivas
			vezes por 2)
	divisoes - Numero de vezes que a variavel valor sera dividida por 2

*/
double dividindoPorDois(double valor, int divisoes)
{
	double resultado = 0;

	if ((divisoes <= 0))
	{
		return -1;
	}
	else
	{
		// FIXME:
		int expoente = 1; // não consegui resolver esse problema sem criar essa var
		for (int i = divisoes; i != 0; i--)
		{
			expoente *= 2;
		}
		resultado += valor / expoente;
	}

	return resultado;
}

/*
  Funcao valorDePI(double limiar): Existem diversas funcoes computacionais
	para calcular valores aproximados de diferentes constantes ou funcoes.
  A funcao a seguir computa uma aproximacao para o valor de pi.
  Esta funcao recebe o numero de iteracoes e calcula o valor de pi de acordo
	com este numero (quanto maior o numero, melhor sera a aproximacao).

  void calculoDoValorDePI(int iteracoes){
	double meuPI = 4; // valor inicial de pi ("primeira iteracao")
	int sinal = -1;
	double divisor = 3;
	for (int i=2;i<=iteracoes;i++){
	  meuPI += sinal * 4.0/divisor; // atualiza o valor de pi
	  divisor += 2; // incrementa o valor do divisor
	  sinal *= -1; // inverte o sinal da variavel sinal
	}
	printf("(%i) pi: %f\n", iteracoes, meuPI);
  }

  A funcao calculoDoValorDePI recebe como parametro o numero de iteracoes
	que serao realizadas para o calculo do valor aproximado de pi.

  Porem, neste exercicio voce deve implementar uma nova funcao:

	double valorDePI(double limiar), baseada na ideia da funcao acima, porem
	que, ao inves de executar um numero de iteracoes passado como parametro,
	ira receber como parametro um limiar de precisao que dira quando sua funcao
	devera parar de calcular a aproximacao, de acordo com a seguinte logica:

	a cada iteracao, voce devera comparar o valor atual de pi com o valor
	anterior (valor da iteracao anterior), enquanto essa diferenca
	(em valor absoluto [isto e, sem sinal]) for maior do que o valor de limiar,
	sua funcao devera continuar calculando o valor de pi.
	Assim que essa diferenca for menor ou igual ao valor de limiar, sua funcao
	devera retornar o valor atual de pi.
  Observacao: se o valor do parametro limiar for menor ou igual a 0,000001
	(um milionesimo), sua funcao devera retornar -1;
  Caso contrario devera retornar o valor aproximado de pi conforme explicado.
  Sua funcao nao devera imprimir nada na tela.

  Parametro:
	limiar - valor do limiar para conclusao do computo do valor de pi

*/

double valorDePI(double limiar)
{
	double resultado = 0;

	int sinal = -1;
	double divisor = 3;
	double meuPI = 4;	   // valor inicial de pi ("primeira iteracao")
	double novoPI = meuPI; // valor posterior de pi ("primeira iteracao")

	if (limiar <= 0.000001)
	{
		return -1;
	}
	else
	{

		do
		{
			meuPI += sinal * 4.0 / divisor;
			divisor += 2;
			sinal *= -1;

			double moduloDif = meuPI - novoPI;
			if (moduloDif < 0)
			{
				moduloDif = moduloDif * -1; // se o sinal for negativo, inverte ele
			}
			novoPI = meuPI;

			if (moduloDif <= limiar)
			{
				return meuPI;
			}

		} while (1); // enquanto for verdadeiro
	}
}

int main()
{

	int valor, ini, fim, limite, divisoes;
	double dividendo, limiar;

	/* Exemplos de testes para a funcao somaDigitos: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO somaDigitos #####\n\n");

	valor = -123;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 0;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 123456;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 2345;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	valor = 99999;
	printf("[somaDigitos]\tValor: %i\tResultado: %i\n\n", valor, somaDigitos(valor));

	/* Exemplos de testes para a funcao somaIntervalo: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO somaIntervalo #####\n\n");

	ini = -5;
	fim = 5;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 5;
	fim = 4;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 3;
	fim = 4;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 3;
	fim = 6;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	ini = 4;
	fim = 1000;
	printf("[somaIntervalo]\tInicio: %i, Fim: %i\tResultado: %i\n\n", ini, fim, somaIntervalo(ini, fim));

	/* Exemplos de testes para a funcao somaInteiros: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO somaInteiros #####\n\n");

	ini = -5;
	limite = 5;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 5;
	limite = 4;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 3;
	limite = 3;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 4;
	limite = 17;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 5;
	limite = 1000;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 5;
	limite = 980;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	ini = 1;
	limite = 9999;
	printf("[somaInteiros]\tInicio: %i, Limite: %i\tResultado: %i\n\n", ini, limite, somaInteiros(ini, limite));

	/* Exemplos de testes para a funcao dividindoPorDois: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO dividindoPorDois #####\n\n");

	dividendo = 4;
	divisoes = -5;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = 5;
	divisoes = 0;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = 8;
	divisoes = 4;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = 1024;
	divisoes = 8;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	dividendo = -4;
	divisoes = 20;
	printf("[dividindoPorDois]\tValor: %f, Divisoes: %i\tResultado: %f\n\n", dividendo, divisoes, dividindoPorDois(dividendo, divisoes));

	/* Exemplos de testes para a funcao valorDePI: */

	printf("\n##### EXEMPLOS DE TESTES - FUNCAO valorDePI #####\n\n");

	limiar = -0.2;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 1;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0.1;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0.001;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	limiar = 0.000002;
	printf("[valorDePI]\tLimiar: %f\tResultado: %f\n\n", limiar, valorDePI(limiar));

	/* se desejar, escreva seu codigo (para testes) aqui */

	return 0;
}