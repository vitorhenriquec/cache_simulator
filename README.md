# Projeto: Cachesimulator #
## Contribuidor ##
20170063851 - Vitor Henrique Coelho Bezerra - `vitorhenrique908@gmail.com`

## Sobre ##
Programa que simula o comportamento interno de uma *cache* L1 e da memória principal. O simulador recebe como entrada uma sequencia de comandos que podem ser de leitura ou escrita e o endereço solicitado. A *cache* simulada deve verificar a presença ou não do bloco contendo o dado solicitado (acarretando em um *Hit* ou *Miss*). O simulador deve ser configurável no que diz respeito aos aspectos de projeto de cache discutidos em sala: Mapeamento(Direto, Totalmente Associativo, Parcialmente Associal), Politica de Substituição(Direta,*FIFO*,*LRU*,*LFU*) e Política de Escrita(*Write-through*).

## Arquivo de configuração ##
O programa lê o arquivo `.config.txt` presente na pasta `config`. Para o funcionamente o programa lê do arquivo e interpretra os valores da seguinte maneira:<br>

```
- Tamanho do bloco (em número de palavras)
- Numero de linhas da cache
- Numero de blocos da memória principal
- Mapeamento (1 – Direto(*directed-mapped*); 2 – Totalmente Associativo(*fully associative*); 3 – Parcialmente Associativo(*n-way setassociative*))
- Numero de conjuntos (caso não seja Parcialmente Associativo, ler o valor normalmente mas desconsidere-o)
- Política de substituição (1 – Aleatório; 2 – *FIFO*; 3 – *LFU*; 4 – *LRU*) 
```

## Comandos ##
O simulador aceita como entrada 3 comandos: *Read*, *Write* e *Show*. O comando *Show* mostra a situação da *cache* L1 e da memória principal. Já o comando *Read* aceita como argumento o endereço do bloco dá memória a ser lido. Como resposta o programa deve retorna *Hit* ou *Miss* e e a linha da cache que contém o bloco solicitado. Por fim, o comando *Write*, que recebe como argumento um endereço e o valor, escreve nesse endereço o valor especificado. 

## Compilação ##

Para compilar o código deve-se primeiro executar uma limpeza dos arquivos compilados anteriormente com a execução do comando  `make clean` no terminal, garantindo que o terminal está acessando a pasta raiz do projeto. Após esse passo, tamb´em na pasta raiz do projeto, faz-se necessário compila-lo através do comando `make`.

## Execução ##
Para executar o programa, basta executar no terminal o comando `./bin/programa` e isso deve ser feito também com a garantia que o terminal esteja acessando a pasta raiz do projeto, 


