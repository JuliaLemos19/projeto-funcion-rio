#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Funcionario {
public:
    int prontuario;
    string nome;
    double salario;

    Funcionario(int pront, string nome, double salario) : prontuario(pront), nome(nome), salario(salario) {}
};

void incluirFuncionario(vector<Funcionario>& listaFuncionarios) {
    int prontuario;
    cout << "Digite o prontuario do funcionario: ";
    cin >> prontuario;

    for (const auto& funcionario : listaFuncionarios) {
        if (funcionario.prontuario == prontuario) {
            cout << "Ja existe um funcionario com esse prontuario." << endl;
            return;
        }
    }

    string nome;
    cout << "Digite o nome do funcionario: ";
    cin.ignore();
    getline(cin, nome);

    double salario;
    cout << "Digite o salario do funcionario: ";
    cin >> salario;

    listaFuncionarios.push_back(Funcionario(prontuario, nome, salario));
    cout << "Funcionario incluido com sucesso." << endl;
}

void excluirFuncionario(vector<Funcionario>& listaFuncionarios) {
    int prontuario;
    cout << "Digite o prontuario do funcionario a ser excluido: ";
    cin >> prontuario;

    for (auto it = listaFuncionarios.begin(); it != listaFuncionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            listaFuncionarios.erase(it);
            cout << "Funcionario excluido com sucesso." << endl;
            return;
        }
    }

    cout << "Funcionario nao encontrado." << endl;
}

void pesquisarFuncionario(const vector<Funcionario>& listaFuncionarios) {
    int prontuario;
    cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    cin >> prontuario;

    for (const auto& funcionario : listaFuncionarios) {
        if (funcionario.prontuario == prontuario) {
            cout << "Prontuario: " << funcionario.prontuario << endl;
            cout << "Nome: " << funcionario.nome << endl;
            cout << "Salario: " << funcionario.salario << endl;
            return;
        }
    }

    cout << "Funcionario nao encontrado." << endl;
}

void listarFuncionarios(const vector<Funcionario>& listaFuncionarios) {
    double totalSalarios = 0;
    for (const auto& funcionario : listaFuncionarios) {
        cout << "Prontuario: " << funcionario.prontuario << endl;
        cout << "Nome: " << funcionario.nome << endl;
        cout << "Salario: " << funcionario.salario << endl;
        totalSalarios += funcionario.salario;
    }
    cout << "Total dos salarios: " << totalSalarios << endl;
}

int main() {
    vector<Funcionario> listaFuncionarios;
    int opcao;

    while (true) {
        cout << "\nMENU:" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

         switch (opcao) {
            case 0:
                return 0;
            case 1:
                incluirFuncionario(listaFuncionarios);
                break;
            case 2:
                excluirFuncionario(listaFuncionarios);
                break;
            case 3:
                pesquisarFuncionario(listaFuncionarios);
                break;
            case 4:
                listarFuncionarios(listaFuncionarios);
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
