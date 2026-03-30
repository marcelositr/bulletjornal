#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Journal.h"
#include "FileManager.h"
#include "Utils.h"
#include <cstdlib>

void displayMenu() {
    std::cout << "\n--- Bullet Journal C++ ---" << std::endl;
    std::cout << "1. Listar todas as notas" << std::endl;
    std::cout << "2. Adicionar nova tarefa (*)" << std::endl;
    std::cout << "3. Adicionar tarefa importante (!)" << std::endl;
    std::cout << "4. Adicionar reunião (M)" << std::endl;
    std::cout << "5. Buscar notas" << std::endl;
    std::cout << "6. Iniciar novo dia (Migração)" << std::endl;
    std::cout << "7. Listar Categorias/Tags" << std::endl;
    std::cout << "8. Abrir no Nano (Editar manual)" << std::endl;
    std::cout << "9. Remover nota" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
}

int main(int argc, char* argv[]) {
    // Determine file paths
    std::string home = std::getenv("HOME") ? std::getenv("HOME") : ".";
    std::string bujoDir = home + "/.bujo";
    std::string nanoConfigDir = home + "/.config/nano"; // User asked for ~/config/nanorc/, but ~/.config/nano/ is standard. I will use ~/.config/nano to be safe but check user preference.
    
    // Ensure .bujo directory exists
    FileManager::ensureDirectoryExists(bujoDir);
    
    std::string todoPath = bujoDir + "/todo.bujo";
    std::string dailyPath = bujoDir + "/daily.bujo";
    std::string nanoSyntaxPath = home + "/.config/nano/nano-syntax.nanorc";

    // Create default files only if they don't exist
    std::ifstream fTodo(todoPath);
    if (!fTodo.good()) {
        FileManager::writeBujoFile(todoPath, {"# Bem-vindo ao seu Bullet Journal!"});
    }
    
    std::ifstream fDaily(dailyPath);
    if (!fDaily.good()) {
        FileManager::writeBujoFile(dailyPath, {"# Adicione aqui suas tarefas diárias recorrentes"});
    }

    // Ensure nano syntax file exists in ~/.config/nano/
    FileManager::ensureDirectoryExists(home + "/.config");
    FileManager::ensureDirectoryExists(home + "/.config/nano");
    std::ifstream fNano(nanoSyntaxPath);
    if (!fNano.good()) {
        // We'll copy the local nano-syntax.nanorc if it exists or create a basic one
        system("cp nano-syntax.nanorc ~/.config/nano/nano-syntax.nanorc 2>/dev/null");
    }

    Journal journal(todoPath, dailyPath);
    journal.loadNotes();

    // Command line argument support
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "-n") {
            journal.startNewDay();
            return 0;
        } else if (arg == "-s") {
            journal.listAll();
            return 0;
        } else if (arg == "-h") {
            std::cout << "Uso: " << argv[0] << " [OPÇÃO]" << std::endl;
            std::cout << " -n    Iniciar novo dia" << std::endl;
            std::cout << " -s    Listar notas" << std::endl;
            return 0;
        }
    }

    int choice;
    std::string input;
    
    while (true) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(); // consume newline

        switch (choice) {
            case 1:
                journal.listAll();
                break;
            case 2:
                std::cout << "Digite a tarefa: ";
                std::getline(std::cin, input);
                journal.addNote(Note("* " + input));
                break;
            case 3:
                std::cout << "Digite a tarefa importante: ";
                std::getline(std::cin, input);
                journal.addNote(Note("! " + input));
                break;
            case 4:
                std::cout << "Digite a reunião (ex: 30/03/2026 Café): ";
                std::getline(std::cin, input);
                journal.addNote(Note("M " + input));
                break;
            case 5:
                std::cout << "Digite o termo de busca: ";
                std::getline(std::cin, input);
                journal.search(input);
                break;
            case 6:
                journal.startNewDay();
                break;
            case 7:
                journal.listCategories();
                journal.listTags();
                break;
            case 8:
                system(("nano " + todoPath).c_str());
                journal.loadNotes(); // Reload after manual edit
                break;
            case 9: {
                int index;
                std::cout << "Digite o índice da nota para remover: ";
                if (std::cin >> index) {
                    journal.removeNote(index);
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 0:
                return 0;
            default:
                std::cout << "Opção inválida." << std::endl;
        }
    }

    return 0;
}
