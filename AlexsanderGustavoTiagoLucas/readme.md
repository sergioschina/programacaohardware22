# Seguidor de Linha

## Descrição

Este trabalho trata-se de um mecanismo seguidor de linha utilizando ferramentas aprendidas em C na aula de programação de hardware sem a utilização de bibliotecas externas com o intuito de fazer os alunos terem a curiosidade de buscar a origem das funções que tanto utilizam, assim criando as suas próprias.

## Integrantes do Grupo

1. Alexsander de Oliveira _**192149**_ 👨🏾‍💻 
2. Gustavo Adegas _**167137**_ 👨🏾‍💻 
3. Tiago Lucena _**185223**_ 👨🏾‍💻
4. Lucas Bezerra	_**186167**_ 👨🏾‍💻 

## Lista de Componentes

- [x] 2x Transistores TIP120
- [x] 2x Resistores 4k
- [x] 2x Diodos 1N40001
- [x] 10x Jumpers M-F
- [x] 8x Born 2 Entradas
- [x] 1x Barra de Pinos
- [x] 1x Arduino Black
- [x] 2x Sensores LM393
- [x] 1x Bateria 9v
- [x] 4x Pilhas
- [x] 2x Motores DC 3-6v
- [x] 1x Switch On/Off

## Documentação Doxygen


### Seguidor de Linha
> v1.0

Projeto de um veículo seguidor de linha.

- Documentacao
- Seguidor

<div class="header">
    <div class="summary">
        <a href="#define-members">Definições e Macros</a> &#124;
        <a href="#func-members">Funções</a> &#124;
        <a href="#var-members">Variáveis</a>
    </div>
    <div class="headertitle">
        <div class="title">Referência do Arquivo Seguidor.c</div>
    </div>
</div>
<!--header-->
<div class="contents">
    <div class="textblock"><code>#include &lt;avr/io.h&gt;</code><br />
        <code>#include &lt;avr/interrupt.h&gt;</code><br />
    </div>
    <table class="memberdecls">
        <tr class="heading">
            <td colspan="2">
                <h2 class="groupheader"><a id="define-members" name="define-members"></a>
                    Definições e Macros</h2>
            </td>
        </tr>
        <tr class="memitem:a43bafb28b29491ec7f871319b5a3b2f8">
            <td class="memItemLeft" align="right" valign="top">#define&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a43bafb28b29491ec7f871319b5a3b2f8">F_CPU</a>&#160;&#160;&#160;16000000</td>
        </tr>
        <tr class="separator:a43bafb28b29491ec7f871319b5a3b2f8">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:a9ba4c5862e2e97b55ede827cc970f3fe">
            <td class="memItemLeft" align="right" valign="top">#define&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a9ba4c5862e2e97b55ede827cc970f3fe">CLEARBIT</a>(ADDRESS,
                BIT)&#160;&#160;&#160;(ADDRESS &amp;= ~(1&lt;&lt;BIT))</td>
        </tr>
        <tr class="separator:a9ba4c5862e2e97b55ede827cc970f3fe">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:a0724532369ee5d568fd4f5e96abafb55">
            <td class="memItemLeft" align="right" valign="top">#define&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a0724532369ee5d568fd4f5e96abafb55">SETBIT</a>(ADDRESS,
                BIT)&#160;&#160;&#160;(ADDRESS |= (1&lt;&lt;BIT))</td>
        </tr>
        <tr class="separator:a0724532369ee5d568fd4f5e96abafb55">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:a1277abbecdb0df171c6e1df4ae3811ab">
            <td class="memItemLeft" align="right" valign="top">#define&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a1277abbecdb0df171c6e1df4ae3811ab">CHECKBIT</a>(ADDRESS,
                BIT)&#160;&#160;&#160;(ADDRESS &amp; (1&lt;&lt;BIT))</td>
        </tr>
        <tr class="separator:a1277abbecdb0df171c6e1df4ae3811ab">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:af4bee8b6b74d884693d799eb4d2dc564">
            <td class="memItemLeft" align="right" valign="top">#define&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#af4bee8b6b74d884693d799eb4d2dc564">CLEAR_PWM_VALUE</a>(ENVIROLMENT)&#160;&#160;&#160;(ENVIROLMENT
                = 0)</td>
        </tr>
        <tr class="separator:af4bee8b6b74d884693d799eb4d2dc564">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:ab3519967169f23cbc7ae5c80a8550692">
            <td class="memItemLeft" align="right" valign="top">#define&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#ab3519967169f23cbc7ae5c80a8550692">SET_PWM_VALUE</a>(ENVIROLMENT,
                VALUE)&#160;&#160;&#160;(ENVIROLMENT = VALUE)</td>
        </tr>
        <tr class="separator:ab3519967169f23cbc7ae5c80a8550692">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
    </table>
    <table class="memberdecls">
        <tr class="heading">
            <td colspan="2">
                <h2 class="groupheader"><a id="func-members" name="func-members"></a>
                    Funções</h2>
            </td>
        </tr>
        <tr class="memitem:a133ed1a49478fb7bb1342ca544c6d488">
            <td class="memItemLeft" align="right" valign="top">void&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a133ed1a49478fb7bb1342ca544c6d488">configureIO</a> ()</td>
        </tr>
        <tr class="separator:a133ed1a49478fb7bb1342ca544c6d488">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:a882a3542a3b70772b13c57af57c6ac4f">
            <td class="memItemLeft" align="right" valign="top">void&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a882a3542a3b70772b13c57af57c6ac4f">configureInterrupt</a> ()</td>
        </tr>
        <tr class="separator:a882a3542a3b70772b13c57af57c6ac4f">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:a8a3c143f55e90d02d1bf68b7a6c21aa6">
            <td class="memItemLeft" align="right" valign="top">void&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a8a3c143f55e90d02d1bf68b7a6c21aa6">configurePWM</a> ()</td>
        </tr>
        <tr class="separator:a8a3c143f55e90d02d1bf68b7a6c21aa6">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:afea150fcd685610cb9f7672fce361e53">
            <td class="memItemLeft" align="right" valign="top">&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#afea150fcd685610cb9f7672fce361e53">ISR</a> (INT0_vect)</td>
        </tr>
        <tr class="separator:afea150fcd685610cb9f7672fce361e53">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:a22acfb428840c6d9aa212764589cf6c6">
            <td class="memItemLeft" align="right" valign="top">&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a22acfb428840c6d9aa212764589cf6c6">ISR</a> (INT1_vect)</td>
        </tr>
        <tr class="separator:a22acfb428840c6d9aa212764589cf6c6">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:ae66f6b31b5ad750f1fe042a706a4e3d4">
            <td class="memItemLeft" align="right" valign="top">int&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#ae66f6b31b5ad750f1fe042a706a4e3d4">main</a> ()</td>
        </tr>
        <tr class="separator:ae66f6b31b5ad750f1fe042a706a4e3d4">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
    </table>
    <table class="memberdecls">
        <tr class="heading">
            <td colspan="2">
                <h2 class="groupheader"><a id="var-members" name="var-members"></a>
                    Variáveis</h2>
            </td>
        </tr>
        <tr class="memitem:af7abfe93e2ea0325e6d6d615c6612235">
            <td class="memItemLeft" align="right" valign="top">int&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#af7abfe93e2ea0325e6d6d615c6612235">DEFAULT_PWM_VALUE</a> = 160</td>
        </tr>
        <tr class="separator:af7abfe93e2ea0325e6d6d615c6612235">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
        <tr class="memitem:a902f0c71f873bc9f63e11622947880ec">
            <td class="memItemLeft" align="right" valign="top">int&#160;</td>
            <td class="memItemRight" valign="bottom"><a class="el"
                    href="_seguidor_8c.html#a902f0c71f873bc9f63e11622947880ec">STOP_TIME_MS</a> = 50</td>
        </tr>
        <tr class="separator:a902f0c71f873bc9f63e11622947880ec">
            <td class="memSeparator" colspan="2">&#160;</td>
        </tr>
    </table>
    <h2 class="groupheader">Definições e macros</h2>
    <a id="a1277abbecdb0df171c6e1df4ae3811ab" name="a1277abbecdb0df171c6e1df4ae3811ab"></a>
    <h2 class="memtitle"><span class="permalink"><a
                href="#a1277abbecdb0df171c6e1df4ae3811ab">&#9670;&#160;</a></span>CHECKBIT</h2>
    <div class="memitem">
        <div class="memproto">
            <table class="memname">
                <tr>
                    <td class="memname">#define CHECKBIT</td>
                    <td>(</td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">ADDRESS, </td>
                </tr>
                <tr>
                    <td class="paramkey"></td>
                    <td></td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">BIT&#160;</td>
                </tr>
                <tr>
                    <td></td>
                    <td>)</td>
                    <td></td>
                    <td>&#160;&#160;&#160;(ADDRESS &amp; (1&lt;&lt;BIT))</td>
                </tr>
            </table>
        </div>
        <div class="memdoc">
        </div>
    </div>
    <a id="af4bee8b6b74d884693d799eb4d2dc564" name="af4bee8b6b74d884693d799eb4d2dc564"></a>
    <h2 class="memtitle"><span class="permalink"><a
                href="#af4bee8b6b74d884693d799eb4d2dc564">&#9670;&#160;</a></span>CLEAR_PWM_VALUE</h2>
    <div class="memitem">
        <div class="memproto">
            <table class="memname">
                <tr>
                    <td class="memname">#define CLEAR_PWM_VALUE</td>
                    <td>(</td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">ENVIROLMENT</td>
                    <td>)</td>
                    <td>&#160;&#160;&#160;(ENVIROLMENT = 0)</td>
                </tr>
            </table>
        </div>
        <div class="memdoc">
        </div>
    </div>
    <a id="a9ba4c5862e2e97b55ede827cc970f3fe" name="a9ba4c5862e2e97b55ede827cc970f3fe"></a>
    <h2 class="memtitle"><span class="permalink"><a
                href="#a9ba4c5862e2e97b55ede827cc970f3fe">&#9670;&#160;</a></span>CLEARBIT</h2>
    <div class="memitem">
        <div class="memproto">
            <table class="memname">
                <tr>
                    <td class="memname">#define CLEARBIT</td>
                    <td>(</td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">ADDRESS, </td>
                </tr>
                <tr>
                    <td class="paramkey"></td>
                    <td></td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">BIT&#160;</td>
                </tr>
                <tr>
                    <td></td>
                    <td>)</td>
                    <td></td>
                    <td>&#160;&#160;&#160;(ADDRESS &amp;= ~(1&lt;&lt;BIT))</td>
                </tr>
            </table>
        </div>
        <div class="memdoc">
        </div>
    </div>
    <a id="a43bafb28b29491ec7f871319b5a3b2f8" name="a43bafb28b29491ec7f871319b5a3b2f8"></a>
    <h2 class="memtitle"><span class="permalink"><a
                href="#a43bafb28b29491ec7f871319b5a3b2f8">&#9670;&#160;</a></span>F_CPU</h2>
    <div class="memitem">
        <div class="memproto">
            <table class="memname">
                <tr>
                    <td class="memname">#define F_CPU&#160;&#160;&#160;16000000</td>
                </tr>
            </table>
        </div>
        <div class="memdoc">
        </div>
    </div>
    <a id="ab3519967169f23cbc7ae5c80a8550692" name="ab3519967169f23cbc7ae5c80a8550692"></a>
    <h2 class="memtitle"><span class="permalink"><a
                href="#ab3519967169f23cbc7ae5c80a8550692">&#9670;&#160;</a></span>SET_PWM_VALUE</h2>
    <div class="memitem">
        <div class="memproto">
            <table class="memname">
                <tr>
                    <td class="memname">#define SET_PWM_VALUE</td>
                    <td>(</td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">ENVIROLMENT, </td>
                </tr>
                <tr>
                    <td class="paramkey"></td>
                    <td></td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">VALUE&#160;</td>
                </tr>
                <tr>
                    <td></td>
                    <td>)</td>
                    <td></td>
                    <td>&#160;&#160;&#160;(ENVIROLMENT = VALUE)</td>
                </tr>
            </table>
        </div>
        <div class="memdoc">
        </div>
    </div>
    <a id="a0724532369ee5d568fd4f5e96abafb55" name="a0724532369ee5d568fd4f5e96abafb55"></a>
    <h2 class="memtitle"><span class="permalink"><a
                href="#a0724532369ee5d568fd4f5e96abafb55">&#9670;&#160;</a></span>SETBIT</h2>
    <div class="memitem">
        <div class="memproto">
            <table class="memname">
                <tr>
                    <td class="memname">#define SETBIT</td>
                    <td>(</td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">ADDRESS, </td>
                </tr>
                <tr>
                    <td class="paramkey"></td>
                    <td></td>
                    <td class="paramtype">&#160;</td>
                    <td class="paramname">BIT&#160;</td>
                </tr>
                <tr>
                    <td></td>
                    <td>)</td>
                    <td></td>
                    <td>&#160;&#160;&#160;(ADDRESS |= (1&lt;&lt;BIT))</td>
                </tr>
            </table>
        </div>
        <div class="memdoc">
        </div>
    </div>
    <h2 class="groupheader">Funções</h2>
    <a id="a882a3542a3b70772b13c57af57c6ac4f" name="a882a3542a3b70772b13c57af57c6ac4f"></a>
    <h2 class="memtitle"><span class="permalink"><a
                href="#a882a3542a3b70772b13c57af57c6ac4f">&#9670;&#160;</a></span>configureInterrupt()</h2>
    <div class="memitem">
        <div class="memproto">
            <table class="memname">
                <tr>
                    <td class="memname">void configureInterrupt </td>
                    <td>(</td>
                    <td class="paramname"></td>
                    <td>)</td>
                    <td></td>
                </tr>
            </table>

```c
        37 {
        38
        39 /*
        40 Primariamente iremos configurar/habilitar o INT0 e INT1
        41 Respectivamente no arduino
        42 PD2: INT0 (ATMega, PORTD2)
        43 PD3: INT1 (ATMega, PORTD3)
        44 */
        45
        46 // Habilitando Interrupções: INT0 e INT 1
        47 SETBIT(EIMSK, INT0);
        48 SETBIT(EIMSK, INT1);
        49
        50 /*
        51 Configurando interrupções no seguinte pattern:
        52 INT0:
        53 Quando houver alteração de nivel lógico:
        54 ISC01: 0
        55 ISC00: 1
        56 INT1:
        57 Quando houver alteração de nivel lógico:
        58 ISC11: 0
        59 ISC10: 1
        60 */
        61
        62 SETBIT(EICRA, ISC00);
        63 SETBIT(EICRA, ISC10);
        64
        65 CLEARBIT(EICRA, ISC01);
        66 CLEARBIT(EICRA, ISC11);
        67
        68 //Habilitando interrupções globais
        69 sei();
        70}
```

<div class="ttc" id="a_seguidor_8c_html_a0724532369ee5d568fd4f5e96abafb55">
<div class="ttname"><a href="_seguidor_8c.html#a0724532369ee5d568fd4f5e96abafb55">SETBIT</a></div>
<div class="ttdeci">#define SETBIT(ADDRESS, BIT)</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:5</div>
</div>
<br/>
<div class="ttc" id="a_seguidor_8c_html_a9ba4c5862e2e97b55ede827cc970f3fe">
<div class="ttname"><a href="_seguidor_8c.html#a9ba4c5862e2e97b55ede827cc970f3fe">CLEARBIT</a></div>
<div class="ttdeci">#define CLEARBIT(ADDRESS, BIT)</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:4</div>
<br/>
<a id="a133ed1a49478fb7bb1342ca544c6d488" name="a133ed1a49478fb7bb1342ca544c6d488"></a>
<h2 class="memtitle"><span class="permalink"><a
href="#a133ed1a49478fb7bb1342ca544c6d488">&#9670;&#160;</a></span>configureIO()</h2>

<div class="memitem">
<div class="memproto">
<table class="memname">
<tr>
<td class="memname">void configureIO </td>
<td>(</td>
<td class="paramname"></td>
<td>)</td>
<td></td>
</tr>
</table>

```c
17 {
18 /*
19 Configurando portas no pattern:
20 PORTD:
21 2: Entrada (Sensor)
22 3: Entrada (Sensor)
23 5: Saída (Motor 1)
24 6: Saída (Motor 2)
25 */
26
27 // Configurando as entradas;
28 CLEARBIT(DDRD, PORTD2);
29 CLEARBIT(DDRD, PORTD3);
30
31 //Configurando as Saídas;
32 SETBIT(DDRD, PORTD5);
33 SETBIT(DDRD, PORTD6);
34
35}
```
<a id="a8a3c143f55e90d02d1bf68b7a6c21aa6" name="a8a3c143f55e90d02d1bf68b7a6c21aa6"></a>
<h2 class="memtitle"><span class="permalink"><a
href="#a8a3c143f55e90d02d1bf68b7a6c21aa6">&#9670;&#160;</a></span>configurePWM()</h2>

<div class="memitem">
<div class="memproto">
<table class="memname">
<tr>
<td class="memname">void configurePWM </td>
<td>(</td>
<td class="paramname"></td>
<td>)</td>
<td></td>
</tr>
</table>

```c
72 {
73
74 /*
75 Configurando PWM:
76 Configurando TCCR0A:
77 Configurações:
78 - No Prescaler
79 - Non-Inverting Fast PWM
80 - Using OCR A Unit
81 - Using OCR B Unit
82 - Mode 3
83 BITS:
84 7: COM0A1 (1)
85 5: COMOB1 (1)
86 1: WGM01 (1)
87 0: WGM00 (1)
88
89 Configurando TCCR0B:
90 Configurações:
91 - No Prescaler
92 BITS:
93 0: CS00 (1)
94
95 Configurando TIMSK0:
96 Configuração:
97 - Habilitando Todos os tipos de interrupção
98 BITS:
99 0: TOIE0 (1)
100 */
101
102 SETBIT(TCCR0A, COM0A1);
103 SETBIT(TCCR0A, COM0B1);
104 SETBIT(TCCR0A, WGM01);
105 SETBIT(TCCR0A, WGM00);
106 SETBIT(TCCR0B, CS00);
107 SETBIT(TIMSK0, TOIE0);
108}
```

<a id="afea150fcd685610cb9f7672fce361e53" name="afea150fcd685610cb9f7672fce361e53"></a>
<h2 class="memtitle"><span class="permalink"><a
href="#afea150fcd685610cb9f7672fce361e53">&#9670;&#160;</a></span>ISR() <span
class="overload">[1/2]</span></h2>

<div class="memitem">
<div class="memproto">
<table class="memname">
<tr>
<td class="memname">ISR </td>
<td>(</td>
<td class="paramtype">INT0_vect&#160;</td>
<td class="paramname"></td>
<td>)</td>
<td></td>
</tr>
</table>

```c
110 {
111 if(!CHECKBIT(PIND, PORTD2)){
112     SET_PWM_VALUE(OCR0B, DEFAULT_PWM_VALUE);
113     SET_PWM_VALUE(OCR0A, DEFAULT_PWM_VALUE);
114 }else{
115     CLEAR_PWM_VALUE(OCR0B);
116     if(!CHECKBIT(PIND, PORTD3)){
117         SET_PWM_VALUE(OCR0A, 255);
118         _delay_ms(STOP_TIME_MS);
119     }
120 }
121}
```

<div class="ttc" id="a_seguidor_8c_html_a1277abbecdb0df171c6e1df4ae3811ab">
<div class="ttname"><a href="_seguidor_8c.html#a1277abbecdb0df171c6e1df4ae3811ab">CHECKBIT</a></div>
<div class="ttdeci">#define CHECKBIT(ADDRESS, BIT)</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:6</div>
</div>
<br/>
<div class="ttc" id="a_seguidor_8c_html_a902f0c71f873bc9f63e11622947880ec">
<div class="ttname"><a href="_seguidor_8c.html#a902f0c71f873bc9f63e11622947880ec">STOP_TIME_MS</a>
</div>
<div class="ttdeci">int STOP_TIME_MS</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:15</div>
</div>
<br/>
<div class="ttc" id="a_seguidor_8c_html_ab3519967169f23cbc7ae5c80a8550692">
<div class="ttname"><a href="_seguidor_8c.html#ab3519967169f23cbc7ae5c80a8550692">SET_PWM_VALUE</a>
</div>
<div class="ttdeci">#define SET_PWM_VALUE(ENVIROLMENT, VALUE)</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:12</div>
</div>
<br/>
<div class="ttc" id="a_seguidor_8c_html_af4bee8b6b74d884693d799eb4d2dc564">
<div class="ttname"><a
href="_seguidor_8c.html#af4bee8b6b74d884693d799eb4d2dc564">CLEAR_PWM_VALUE</a></div>
<div class="ttdeci">#define CLEAR_PWM_VALUE(ENVIROLMENT)</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:11</div>
</div>
<br/>
<div class="ttc" id="a_seguidor_8c_html_af7abfe93e2ea0325e6d6d615c6612235">
<div class="ttname"><a
href="_seguidor_8c.html#af7abfe93e2ea0325e6d6d615c6612235">DEFAULT_PWM_VALUE</a></div>
<div class="ttdeci">int DEFAULT_PWM_VALUE</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:14</div>
</div>
<br/>

<a id="a22acfb428840c6d9aa212764589cf6c6" name="a22acfb428840c6d9aa212764589cf6c6"></a>
<h2 class="memtitle"><span class="permalink"><a
href="#a22acfb428840c6d9aa212764589cf6c6">&#9670;&#160;</a></span>ISR() <span
class="overload">[2/2]</span></h2>

<div class="memitem">
<div class="memproto">
<table class="memname">
<tr>
<td class="memname">ISR </td>
<td>(</td>
<td class="paramtype">INT1_vect&#160;</td>
<td class="paramname"></td>
<td>)</td>
<td></td>
</tr>
</table>

```c
123 {
124 if(!CHECKBIT(PIND, PORTD3)){
125     SET_PWM_VALUE(OCR0A, DEFAULT_PWM_VALUE);
126     SET_PWM_VALUE(OCR0B, DEFAULT_PWM_VALUE);
127 }else{
128     CLEAR_PWM_VALUE(OCR0A);
129     if(!CHECKBIT(PIND, PORTD2)){
130         SET_PWM_VALUE(OCR0B, 255);
131         _delay_ms(STOP_TIME_MS);
132     }
133 }
134}
```

<a id="ae66f6b31b5ad750f1fe042a706a4e3d4" name="ae66f6b31b5ad750f1fe042a706a4e3d4"></a>
<h2 class="memtitle"><span class="permalink"><a
href="#ae66f6b31b5ad750f1fe042a706a4e3d4">&#9670;&#160;</a></span>main()</h2>

<div class="memitem">
<div class="memproto">
<table class="memname">
<tr>
<td class="memname">int main </td>
<td>(</td>
<td class="paramname"></td>
<td>)</td>
<td></td>
</tr>
</table>

```c
136 {
137
138 configureIO();
139 configureInterrupt();
140 configurePWM();
141
142 while(1){
143 }
144
145 return 0;
146}

```

<div class="ttc" id="a_seguidor_8c_html_a133ed1a49478fb7bb1342ca544c6d488">
<div class="ttname"><a href="_seguidor_8c.html#a133ed1a49478fb7bb1342ca544c6d488">configureIO</a>
</div>
<div class="ttdeci">void configureIO()</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:17</div>
</div>
<br/>
<div class="ttc" id="a_seguidor_8c_html_a882a3542a3b70772b13c57af57c6ac4f">
<div class="ttname"><a
href="_seguidor_8c.html#a882a3542a3b70772b13c57af57c6ac4f">configureInterrupt</a></div>
<div class="ttdeci">void configureInterrupt()</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:37</div>
</div>
<br/>
<div class="ttc" id="a_seguidor_8c_html_a8a3c143f55e90d02d1bf68b7a6c21aa6">
<div class="ttname"><a href="_seguidor_8c.html#a8a3c143f55e90d02d1bf68b7a6c21aa6">configurePWM</a>
</div>
<div class="ttdeci">void configurePWM()</div>
<div class="ttdef"><b>Definition:</b> Seguidor.c:72</div>
</div>
<br/>
</div><!-- fragment -->
</div>
</div>
<h2 class="groupheader">Variáveis</h2>
<a id="af7abfe93e2ea0325e6d6d615c6612235" name="af7abfe93e2ea0325e6d6d615c6612235"></a>
<h2 class="memtitle"><span class="permalink"><a
href="#af7abfe93e2ea0325e6d6d615c6612235">&#9670;&#160;</a></span>DEFAULT_PWM_VALUE</h2>

<div class="memitem">
<div class="memproto">
<table class="memname">
<tr>
<td class="memname">int DEFAULT_PWM_VALUE = 160</td>
</tr>
</table>
</div>
<div class="memdoc">

</div>
</div>
<a id="a902f0c71f873bc9f63e11622947880ec" name="a902f0c71f873bc9f63e11622947880ec"></a>
<h2 class="memtitle"><span class="permalink"><a
href="#a902f0c71f873bc9f63e11622947880ec">&#9670;&#160;</a></span>STOP_TIME_MS</h2>

<div class="memitem">
<div class="memproto">
<table class="memname">
<tr>
<td class="memname">int STOP_TIME_MS = 50</td>
</tr>
</table>
</div>
<div class="memdoc">

</div>
</div>
</div>
