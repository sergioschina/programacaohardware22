/****************************************************************************
 * Copyright (C) 2021 by Programação de Hardware Engenharia de computação   *
 *                                                                          *
 * This file is part of TP02.                                                *
 *                                                                          *
 * TP02 é um software livre: você pode redistribuí-lo e / ou modificá-lo     *
 * sob os termos da GNU Lesser General Public License conforme publicada    *
 * pela Free Software Foundation, seja a versão 3 da Licença, ou            *
 * (à sua escolha) qualquer versão posterior.                               *
 *                                                                          *
 * O TP02 é distribuído na esperança de que seja útil,                       *
 * mas SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de             *
 * COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM DETERMINADO FIM. Veja o                *
 * GNU Lesser General Public License para obter mais detalhes.              *
 *                                                                          *
 * Você deve ter recebido uma cópia do GNU Lesser General Public            *
 * Licença junto com TP02. Caso contrário, consulte                          *
 *<http://www.gnu.org/licenses/>.                                           *
 * <https://www.doxygen.nl/manual/index.html>                               *
 ****************************************************************************/

/**
 * @file TP02.h
 * @author Aluno
 * @date 13 Aug 2020
 * @brief TP02 da matéria Programação de Hardware do 6 ciclo de engenharia de computação.
 *
 * Altere aqui a descrição completa do que o programa faz;
 * As tags Doxygen são palavras precedidas por uma barra invertida @ \ 
 * ou por um símbolo @@.
 * @see http://inovfablab.unisanta.br
 * @see http://fabmanager.unisanta.br
 */

#ifndef _TP02_
#  define _TP02_

#include <avr/io.h>

/**
 * @brief Este Tp é o segundo TP da disciplica de Programãção de Hardware.
 *
 *  O aluno(a) deverá desenvolver um código em C, em que ele deverá criar as funções de manipulação de IO (usando os registros DDRx,PINx,PORTx) onde cada deverá proporcionar ao usuário
 *  poder escolher qualquer pino e port que ele quiser.  Em seguida, na função main, o aluno deverá implementar um exemplo usando as funçoes, e de preferencia para implementar 
 *  como se fosse um projeto (de sua escolha. EX: Sensor de janelas).A resposta deverá ser implementado cabeçalho de acordo com o exemplo deste e descrição de cada comando usando Doxygen.
 *  A resposta deverá ser enviada para o próprio github do aluno, e postar os arquivos fonte na tarefa do teams, deve-se postar os arquivos em si(não postarem em formato zip).
 */


typedef struct TP02Struct_struct {
	int a;    /**< Exemplo de explicação de uma struct #a. */
	int b;    /**< Exemplo de explicação de uma struct#b. */
	double c; /**< Exemplo de explicação de uma struct #c */
} TP02Struct;

//exemplo de documentação de uma função - Versão completa - Pode apagar ou usar a seu gosto

/**
 * @brief Exemplo mostrando como documentar uma função com Doxygen.
 *
 * Descrição do que a função faz. Esta parte pode se referir aos parâmetros
 * da função, como @p param1 ou @p param2. Uma palavra de código também pode ser
 * inserido como @c isso que é equivalente a <tt> isso </tt> e pode ser útil
 * para dizer que a função retorna um @c void ou um @c int. Se você quiser
 * mais de uma palavra na fonte da máquina de escrever, então apenas use @ <tt @>.
 * Também podemos incluir texto literalmente,
 * @verbatim assim @endverbatim
 * Às vezes, também é conveniente incluir um exemplo de uso:
 * @code
 * TP02Struct * out = TP02_The_Function_Name (param1, param2);
 * printf ("algo ... \ n");
 * @endcode
 * Ou,
 * @code {.py}
 * pyval = python_func (arg1, arg2)
 * imprimir pyval
 * @endcode
 * quando o idioma não é o usado no arquivo fonte atual (mas
 * <b> tenha cuidado </b>, pois isso pode ser compatível apenas com as versões recentes
 * de Doxygen). A propósito, <b> é assim que você escreve texto em negrito </b> ou,
 * se for apenas uma palavra, você pode apenas fazer isso com @b.
 * @param param1 Descrição do primeiro parâmetro da função.
 * @param param2 O segundo, que segue @p param1.
 * @return Descreva o que a função retorna.
 * @ver TP02_The_Second_Function
 * @ver TP02_The_Last_One
 * @ver http: // website /
 * @note Algo a ser observado.
 * @warning Warning
 */
TP02Struct TP02_The_Function_Name(TP02Struct param1, TP02Struct param2 /*, ...*/);// pode deletar esta função é apenas exemplo

//exemplo de documentação de uma função - Versão mais simples - Pode apagar ou usar a seu gosto
/**
  * @brief Uma função de stub simples para mostrar como os links funcionam.
  *
  * Links são gerados automaticamente para páginas da web (como http://www.inovfablab.unisanta.br)
  * e para estruturas, como TP02Struct_struct. Para tipos digitados, use
  * #TP02Struct.
  * Para funções, links automáticos são gerados quando os parênteses () seguem
  * o nome da função, como TP02_The_Function_Name ().
  * Alternativamente, você pode usar #TP02_The_Function_Name.
  * @return @c NULL é sempre retornado.
  */
TP02Struct TP02_The_Second_Function(void);// pode deletar esta função é apenas exemplo

//exemplo de documentação de uma função - Versão resumida - Pode apagar ou usar a seu gosto
/**
  * O resumo pode ser omitido. Se você configurar o Doxygen com
  * <tt> JAVADOC_AUTOBRIEF = YES </tt>, então a primeira linha do comentário é usada
  * em vez de. Nesta função, seria como se
  * @verbatim @brief Brief pode ser omitido. @endverbatim
  * foi usado em seu lugar.
  */
TP02Struct TP02_The_Last_One(void); // pode deletar esta função é apenas exemplo


int main(void)
{
    /* Seu programa aqui */
    while (1) 
    {
    }
}

#endif /* _TP02_ */