### jogo Batalha Naval - MateCheck

***Estrutura do Tabuleiro
O jogo é baseado em um tabuleiro 10x10, representado por uma matriz bidimensional tabuleiro[TAMANHO][TAMANHO], onde cada célula pode conter valores diferentes dependendo das interações das habilidades.
Além da matriz principal, há outras matrizes auxiliares que armazenam os efeitos individuais das habilidades:
- cone[TAMANHO][TAMANHO] – Representa a forma geométrica do cone.
- cruz[TAMANHO][TAMANHO] – Representa a cruz que será desenhada.
- octaedro[TAMANHO][TAMANHO] – Representa o octaedro no tabuleiro.
- areaAfetada[TAMANHO][TAMANHO] – Armazena as áreas impactadas.
Todas essas matrizes são inicializadas com zeros, garantindo que, no início do jogo, o tabuleiro esteja vazio.

***Exibição do Tabuleiro (imprimirTabuleiro())
A função imprimirTabuleiro() é responsável por mostrar a matriz na tela, combinando os valores das diferentes habilidades aplicadas:
- Cabeçalho:
- Exibe um título * Tabuleiro Batalha Naval *.
- Imprime os identificadores das colunas (A, B, C... J).
- Exibe a numeração das linhas (1 a 10).
- Preenchimento do Tabuleiro:
- Percorre todas as células do tabuleiro e soma os valores presentes nas matrizes (tabuleiro, cone, cruz, octaedro e areaAfetada).
- Exibe os números na tela, indicando onde cada habilidade foi aplicada.

***Habilidades do Jogo
Cada forma geométrica tem sua função específica para alterar o tabuleiro:
*preencherCone(matriz, linha, coluna)
Marca um cone, expandindo sua base para baixo:
- O ponto inicial recebe 3.
- A segunda linha afeta três células (esquerda, central e direita).
- A terceira linha amplia ainda mais a base, afetando cinco células.

*preencherCruz(matriz, linha, coluna)
Desenha uma cruz, afetando:
- Duas posições acima e abaixo da célula central.
- Duas posições à esquerda e à direita.

*preencherOctaedro(matriz, linha, coluna)
Cria um octaedro afetando as células adjacentes (cima, baixo, esquerda, direita) ao redor do ponto inicial.

*marcarAreaAfetada(matriz, linha, coluna)
Define áreas impactadas, inserindo o número 5 na posição específica da matriz.

***Execução do Jogo (main())
A função main() inicializa o tabuleiro e aplica habilidades em coordenadas específicas:
- preencherCone(cone, 5, 2) → Aplica um cone na linha 6 e coluna C.
- preencherCruz(cruz, 2, 3) → Desenha uma cruz na linha 3, coluna D.
- preencherOctaedro(octaedro, 3, 7) → Marca um octaedro na linha 4, coluna H.
- marcarAreaAfetada(areaAfetada, 9, 9) → Marca áreas atingidas em posições estratégicas.
Após aplicar todas as habilidades, a função imprimirTabuleiro() é chamada para exibir o tabuleiro atualizado.

***Objetivo e Possíveis Melhorias
Esse jogo pode ser uma estratégia de ataque e defesa, onde cada habilidade afeta certas regiões do tabuleiro. Algumas melhorias que poderiam ser adicionadas:
- Implementar jogadores que podem escolher onde posicionar os ataques.
- Permitir uma interação dinâmica, onde o usuário escolhe os alvos durante a execução.
- Adicionar uma lógica de pontuação baseada na cobertura das áreas impactadas.

***Conclusão
O código constrói uma base sólida para um jogo de Batalha Naval Estratégica, utilizando padrões geométricos para modificar o tabuleiro.


