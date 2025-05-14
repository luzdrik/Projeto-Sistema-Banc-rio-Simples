#include <iostream>
#include <string>
using namespace std;

class Cliente {
  private:
  // Atributos
  string nome;  //  Nome do Cliente
  string cpf;   //  CPF do Cliente
  
  public:
  // Construtores
  Cliente(string nome, string cpf) {
    this->nome = nome;
    this->cpf = cpf;
  }
  
  // Métodos getter
  string getNome() const {
    return nome; //  Retorna o valor do atributo privado nome
  }
  
  string getCPF() const {
    return cpf; //   Retorna o valor do atributo privado cpf
  }
  

};

class ContaBancaria {
  private:
  // Atributos
  int numero;      //  Número da conta
  double saldo;    //  Saldo da conta
  Cliente titular; //  Objeto do tipo Cliente -> Titular da conta 
  
  public:
  // Construtores
  ContaBancaria(int numero, Cliente titular, double saldo = 0.0)
    : numero(numero), saldo(saldo), titular(titular) {}   //  Construtor "{}" com corpo vazio necessário
  
  // Métodos getter
  int getNumero() const {
    return numero;  // Retorna o valor do atributo privado numero
  }
  
  double getSaldo() const {
    return saldo;   // Retorna o valor do atributo privado saldo
  }
  
  Cliente getTitular() const {
    return titular; // Retorna o valor do atributo privado titular
  }
  
  // Voids -> Realizações de operações e/ou ações que não retornam um valor
  /// Deposita um valor na conta bancária
  void depositar(double valor) {
    if (valor > 0) {
      saldo += valor;
    }
    else {
      cout << "Valor inválido para depósito.\n";
    }
  }
  
  /// Saca um valor da conta bancária
  void sacar(double valor){
    if (valor > 0 && valor <= saldo) {
      saldo -= valor;
      cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
    }
    else {
      cout << "Saldo insuficiente ou valor inválido.\n";
    }
  }
  
  /// Tranfere um valor da conta bancária para outra conta
  void transferir (double valor, ContaBancaria &destino) {
    if (valor > 0 && valor <= saldo) {
      saldo -= valor;
      destino.depositar(valor);
      cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.getNumero() << "\n";
    }
    else {
      cout << "Transferência não realizada: saldo insuficiente ou valor inválido.\n";
    }
  }
  
  /// Transfere um valor da conta bancária para outras duas contas, onde é dividido igualmente entre elas
  void transferir (double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    double metade = valor / 2.0;
    if (valor > 0 && valor <= saldo) {
      saldo -= valor;
      destino1.depositar(metade);
      destino2.depositar(metade);
      cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.getNumero() << " e " << destino2.getNumero() << ") da conta " << numero << "\n";
    }
    else {
      cout << "Transferência não realizada: saldo insuficiente ou valor inválido.\n";
    }
  }
  
  /// Exibe o saldo da conta bancária
  void exibirSaldo() {
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
  }
  
  /// Exibe as informações da conta bancária
  void exibirInformacoes() {
    cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCPF() << "\n";
    cout << "Número da conta: " << numero << ", Saldo: R$ " << saldo << endl;
  }
};
