/****************************************************************************
 * Copyright (C) 2021 by Programa��o de Hardware Engenharia de computa��o   *
 *                                                                          *
 * This file is part of TP02.                                                *
 *                                                                          *
 * TP02 � um software livre: voc� pode redistribu�-lo e / ou modific�-lo     *
 * sob os termos da GNU Lesser General Public License conforme publicada    *
 * pela Free Software Foundation, seja a vers�o 3 da Licen�a, ou            *
 * (� sua escolha) qualquer vers�o posterior.                               *
 *                                                                          *
 * O TP02 � distribu�do na esperan�a de que seja �til,                       *
 * mas SEM QUALQUER GARANTIA; sem mesmo a garantia impl�cita de             *
 * COMERCIALIZA��O ou ADEQUA��O A UM DETERMINADO FIM. Veja o                *
 * GNU Lesser General Public License para obter mais detalhes.              *
 *                                                                          *
 * Voc� deve ter recebido uma c�pia do GNU Lesser General Public            *
 * Licen�a junto com TP02. Caso contr�rio, consulte                          *
 *<http://www.gnu.org/licenses/>.                                           *
 * <https://www.doxygen.nl/manual/index.html>                               *
 ****************************************************************************/

/**
 * @file TP02.h
 * @author Aluno
 * @date 13 Aug 2020
 * @brief TP02 da mat�ria Programa��o de Hardware do 6 ciclo de engenharia de computa��o.
 *
 * Altere aqui a descri��o completa do que o programa faz;
 * As tags Doxygen s�o palavras precedidas por uma barra invertida @ \ 
 * ou por um s�mbolo @@.
 * @see http://inovfablab.unisanta.br
 * @see http://fabmanager.unisanta.br
 */

#ifndef _TP02_
#  define _TP02_

#include <avr/io.h>

/**
 * @brief Este Tp � o segundo TP da disciplica de Program���o de Hardware.
 *
 *  O aluno(a) dever� desenvolver um c�digo em C, em que ele dever� criar as fun��es de manipula��o de IO (usando os registros DDRx,PINx,PORTx) onde cada dever� proporcionar ao usu�rio
 *  poder escolher qualquer pino e port que ele quiser.  Em seguida, na fun��o main, o aluno dever� implementar um exemplo usando as fun�oes, e de preferencia para implementar 
 *  como se fosse um projeto (de sua escolha. EX: Sensor de janelas).A resposta dever� ser implementado cabe�alho de acordo com o exemplo deste e descri��o de cada comando usando Doxygen.
 *  A resposta dever� ser enviada para o pr�prio github do aluno, e postar os arquivos fonte na tarefa do teams, deve-se postar os arquivos em si(n�o postarem em formato zip).
 */


typedef struct TP02Struct_struct {
	int a;    /**< Exemplo de explica��o de uma struct #a. */
	int b;    /**< Exemplo de explica��o de uma struct#b. */
	double c; /**< Exemplo de explica��o de uma struct #c */
} TP02Struct;

//exemplo de documenta��o de uma fun��o - Vers�o completa - Pode apagar ou usar a seu gosto

/**
 * @brief Exemplo mostrando como documentar uma fun��o com Doxygen.
 *
 * Descri��o do que a fun��o faz. Esta parte pode se referir aos par�metros
 * da fun��o, como @p param1 ou @p param2. Uma palavra de c�digo tamb�m pode ser
 * inserido como @c isso que � equivalente a <tt> isso </tt> e pode ser �til
 * para dizer que a fun��o retorna um @c void ou um @c int. Se voc� quiser
 * mais de uma palavra na fonte da m�quina de escrever, ent�o apenas use @ <tt @>.
 * Tamb�m podemos incluir texto literalmente,
 * @verbatim assim @endverbatim
 * �s vezes, tamb�m � conveniente incluir um exemplo de uso:
 * @code
 * TP02Struct * out = TP02_The_Function_Name (param1, param2);
 * printf ("algo ... \ n");
 * @endcode
 * Ou,
 * @code {.py}
 * pyval = python_func (arg1, arg2)
 * imprimir pyval
 * @endcode
 * quando o idioma n�o � o usado no arquivo fonte atual (mas
 * <b> tenha cuidado </b>, pois isso pode ser compat�vel apenas com as vers�es recentes
 * de Doxygen). A prop�sito, <b> � assim que voc� escreve texto em negrito </b> ou,
 * se for apenas uma palavra, voc� pode apenas fazer isso com @b.
 * @param param1 Descri��o do primeiro par�metro da fun��o.
 * @param param2 O segundo, que segue @p param1.
 * @return Descreva o que a fun��o retorna.
 * @ver TP02_The_Second_Function
 * @ver TP02_The_Last_One
 * @ver http: // website /
 * @note Algo a ser observado.
 * @warning Warning
 */
TP02Struct TP02_The_Function_Name(TP02Struct param1, TP02Struct param2 /*, ...*/);// pode deletar esta fun��o � apenas exemplo

//exemplo de documenta��o de uma fun��o - Vers�o mais simples - Pode apagar ou usar a seu gosto
/**
  * @brief Uma fun��o de stub simples para mostrar como os links funcionam.
  *
  * Links s�o gerados automaticamente para p�ginas da web (como http://www.inovfablab.unisanta.br)
  * e para estruturas, como TP02Struct_struct. Para tipos digitados, use
  * #TP02Struct.
  * Para fun��es, links autom�ticos s�o gerados quando os par�nteses () seguem
  * o nome da fun��o, como TP02_The_Function_Name ().
  * Alternativamente, voc� pode usar #TP02_The_Function_Name.
  * @return @c NULL � sempre retornado.
  */
TP02Struct TP02_The_Second_Function(void);// pode deletar esta fun��o � apenas exemplo

//exemplo de documenta��o de uma fun��o - Vers�o resumida - Pode apagar ou usar a seu gosto
/**
  * O resumo pode ser omitido. Se voc� configurar o Doxygen com
  * <tt> JAVADOC_AUTOBRIEF = YES </tt>, ent�o a primeira linha do coment�rio � usada
  * em vez de. Nesta fun��o, seria como se
  * @verbatim @brief Brief pode ser omitido. @endverbatim
  * foi usado em seu lugar.
  */
TP02Struct TP02_The_Last_One(void); // pode deletar esta fun��o � apenas exemplo


int main(void)
{
    /* Seu programa aqui */
    while (1) 
    {
    }
}

#endif /* _TP02_ */