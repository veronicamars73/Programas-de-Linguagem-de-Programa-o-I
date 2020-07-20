# AUTORES:

- **ALAIDE LISANDRA MELO CARVALHO** (*20190036270*) 
- **JOSÉ VICTOR FERREIRA DA FONSECA** (*20190035854*)


# Prova de LP I - Supermercado

Projeto criado como método de avaliação da segunda unidade da disciplina de *Linguagem de Programação I* no período de 2020.5.

# Informações Importantes

## Compilação

Compile qualquer o programa utilizando o comando `make` no terminal dentro do diretório do programa. 

## Sobre o programa

O programa **supermercado** implementa as classes: *Estabelecimento*, *Cliente*, *Produto*, *ProdutoFornecedor* e Fornecedor.

### Estabelecimento

Representa um Estabelecimento comercial, apresenta os seguintes atributos:
- Nome;
- Produtos;

E os métodos:
- `listar()`;
- `venda(int cod_p)`;
- `caixa()`;
- `record_estoque`;
- `record_sales()`;

### Cliente

Representa clientes do estabelecimento, apresenta os seguintes atributos:
- codigo;
- saldo;
- sacola;
- qtd_clientes;

E os métodos:
- `aumentaSaldo(double saldo_ad)`;
- `compra(std::string nome_produto, Estabelecimento* est)`;
- `verSacola()`;
- `registro()`;

### Produto

Representa um produto do estabelecimento, apresenta os seguintes atributos:
- codigo;
- nome;
- unidadeDeMedida;
- preco;
- qtd;

### ProdutoFornecedor

Representa produtos existentes no Fornecedor, apresenta os seguintes atributos:
- nome;
- qtd;

### Fornecedor

Representa o Fornecedor do Estabelecimento que reabastece os produtos do supermercado, apresenta os seguintes atributos:
- nome;
- produtos;

E os métodos:
- `void listarProdutos()`;
- `int repassarProdutos(ProdutoFornecedor produtoRepassado)`;
- `int venda_forn(int p_cod, int qtd)`;
- `void registrar_venda_forn()`;

## Instruções de uso

O programa apresenta um main que permite a criação e modificação de clientes, listagem de produtos do estabelecimento, checagem da sacola dos clientes e realização de compras.

- Para a execução do main execute o comando abaixo no seu diretório de compilação do programa.
``` shell
$  ./supermercado
``` 


# Autoria

Programa desenvolvido por **Alaide Lisandra Melo Carvalho** (<mendie73@gmail.com>) e **José Victor Ferreira da Fonseca** (<josevictorjose8@gmail.com>) como projeto para a disciplina de *Linguagem de Programação I* de 2020.5.

&copy; IMD/UFRN 2020.
