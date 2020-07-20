#ifndef W5N_CLIENTE_H
#define W5N_CLIENTE_H

#include <string>

class Cliente{
    protected:
    int tempo_de_cadastro;
    std::string documento; // CPF ou CNPJ
    std::string descricao; // Nome ou razão social

	public:
    Cliente();
    

    void setTempo_de_cadastro(int t);
    int getTempo_de_cadastro();
    void setDocumento(std::string s);
    std::string getDocumento();
    void setDescricao(std::string s);
    std::string getDescricao();
};

#endif