# SSC0300 - LINGUAGEM DE PROGRAMAÇÃO E APLICAÇÕES
# TRABALHO 2 - APLICAÇÕES DE ALGORITMOS DE ÁRVORES


# AMBIENTE DE DESENVOLVIMENTO
- PLATAFORMA: LINUX - Lubuntu - Baseado no Ubuntu
- COMPILADOR: GCC/CPP ( CODEBLOCKS )



# INSTRUÇÕES DE EXECUÇÃO DO PROGRAMA trab.c

	Ao executar o programa "trab.c", um menu irá abrir

	>> PARTE 1:

	A opção "1" ( Operações Basicas em Arvores ), irá levar para um menu secundário , que trará as opções de: Inserção, Remoção, Busca, Impressão e Sair.
	O usuário então, deverá, necessariamente, escolher a opção " 1 " do menu secundário para conseguir trabalhar de forma adequada. Caso contrário, se o usário escolher qualquer outra opção senão a " 1 ", primeiramente, não conseguirá usar o programa de forma adequada, e uma mensagem de elemento inexistente aparecerá.
	Ao inserir todos os elementos, o usuário, então, poderá trabalhar de forma natural no programa. Exemplo:
	
	( INSERINDO OS ELEMENTOS  ):
	Primeiramente, o usuário deverá escolher a quantidade de elementos a ser adicionado e logo após, inserir valor por valor. Se os elementos forem inseridos, uma mensagem de sucesso aparecerá na tela. Caso o elemento exista, uma mensagem advertará o usuário.

	(  EXCLUINDO OS ELEMENTOS ):
	Após a inserção, o usuário esta possibilitado em remover os elementos, se necessário. Caso o elemento exista, uma mensagem de sucesso aparecerá na tela.  Caso contrário,  o programa irá alertar o usuário que o valor é inexistente.

	( BUSCANDO ELEMENTO ):
	O usuário também poderá procurar um valor. Caso o valor exista, uma mensagem de sucesso na busca será exibida "Elemento encontrado". Caso contrário, o programa irá alertar o usuário que o elemento não existe.
	
	( IMPRESSÃO DOS ELEMENTOS )
	Por fim, se o usuário escolher a opção de impressão dos elementos, o programa irá imprimir os elementos dessa forma:
	
	Impressão em ordem
	Impressão Pre Ordem
	Impressão Pos Ordem
	Impressão Labelled Bracketing



	>> PARTE 2:
	A opção "2" ( Arvore Genealogica ), irá levar para um menu secundário, que trará as opções de: Inserção e Impressão:
	O usuário então, deverá, necessariamente, escolher a opção " 1 " do menu secundário para conseguir trabalhar de forma adequada. 
	O Usuário deverá escolher a quantidade de elementos a ser inseridos. NOTA: Nesse caso, os elementos serão inseridos 3 a 3. Ou seja, se o usuário escolher inserir 4 elementos, um total de 12 elementos deverá ser inserido. Exemplo:

	( INSERINDO ELEMENTOS ):
	Na subopção 1:
	O Usuário deverá inserir os elementos 3 a 3, como na imagem a seguir. Caso o elemento exista, ele não será adicionado. Caso contrário, ele será adicionado e uma mensagem de inserção aparecerá na tela.

	( IMPRIMINDO OS ELEMENTOS):
	Na subopção 2:
	Após o usários ter inserido os elementos da arvore, então ele poderá imprimir. Nessa opção, a impressão será mostrada em Labelled Bracketing e a Impressão da família por geração


# MODO DE FUNCIONAMENTO
 
	A struct é composto de uma variável INT para o valor do elemento inserido (caso possua), uma string nome (caso possua) e dois ponteiros que irão levar para os elementos descendentes a esquerda e a direita
	(IMAGEM 1)

	A função "void insercao(struct arvore **raiz, int elemento)" é a função responsável por adicionar os elementos.
	Primeiramente, há uma condição verificando se o ponteiro que entra como referência não é nulo. Se ele for nulo, uma variável auxiliar será criada para inserir o primeiro elemento. Se o ponteiro não for nulo, uma comparação será feita entre o elemento que entra por referência e o valor que aponta para o ponteiro da raiz que entra como referência. Se ele for menor, a função entrará no modo recursivo para o ponteiro do lado esquerdo da estrutura. Se ele for maior, a função entrará no modo recursivo para o ponteiro do lado direito da estrutura. Caso contrário, o elemento já existe e uma mensagem

	A função "struct arvore *DoisFilhos(struct arvore *raiz)" servirá como auxiliar da função remoção. Ela ira buscar os possíveis filhos de um lugar na arvore.
	
	A função "void remocao(struct arvore **raiz, int elemento)" é a função que irá buscar um elemento e removerá ele da arvore, caso exista.
	A função, basicamente, irá comparar se o elemento de entrada do usuário é maior que o valor do primeiro elemento da arvore, e então entrará na sua forma recursiva, até que o elemento descendente a esquerda e a direita sejam diferentes de nulos, e nesse caso, a função Doisfilhos entrará em ação. Caso contrarário, um ponteiro auxiliar será criado e o elemento sera removido.

	A função "int busca(struct arvore *raiz, int elemento )", irá buscar um elemento de entrada do usuário.  A função irá conferir se o ponteiro é nulo. Se for, ele retornará -1. Se o valor do ponteiro for igual ao elemento digitado pelo usuário, então, a função retornará o mesmo valor digitado pelo usuário. Caso contrario, ele ira comparar se o valor é menor ou maior. Caso for menor ele entrará na forma recursiva para esquerda. Caso for maior, a função entrará na forma recursiva a esquerda.
	
	As funções "void imprime_preordem(struct arvore *raiz)", "void imprime_posordem(struct arvore *raiz)", "void imprime_emordem(struct arvore *raiz)" e  "void imprime_labelledbracketing(struct arvore *raiz)" irá imprimir os valores da arvore, conforme foi inserido pelo usuário. Também de forma recursiva, até que o ponteiro seja nulo.

	A função "void inserir_membro(struct arvore **raiz, char string1[], char string2[], char string3[], int valor )", trabalhará de forma semelhante a função  "void insercao(struct arvore **raiz, int elemento)" da parte 1. A diferença que ela possuirá 3 entradas strings e irá trabalhar com as mesmas. O valor que entrará como referência, é utilizado para seguir a ordem, dado ao fato que uma string não pode seguir uma ordem como com números.
