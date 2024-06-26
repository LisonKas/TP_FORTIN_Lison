#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <list>
#include <numeric>
#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

int main(){

    Node* newNode {create_node(10)};

    pretty_print_left_right(*newNode);
    std::cout << newNode->is_leaf() << std::endl;

    newNode->insert(34);
    newNode->insert(5);
    newNode->insert(44);
    newNode->insert(20);
    newNode->insert(50);
    pretty_print_left_right(*newNode);
    std::cout << newNode->height() << std::endl;
    // newNode->right->delete_childs();
    // pretty_print_left_right(*newNode);
    newNode->display_infixe();

    //Question 7
    std::vector<Node const*> nodes_prefixe {newNode->prefixe()};
    for(int i {0}; i<nodes_prefixe.size(); i++){
        pretty_print_left_right(*nodes_prefixe[i]);
        std::cout << "Prochain noeud : " << std::endl;
    }
    std::cout << "Fin du préfixe" << std::endl;

    std::cout << std::endl;
    //Question 9
    pretty_print_left_right(*most_left(newNode));
    std::cout << std::endl;

    if(remove(newNode, 44)){
        pretty_print_left_right(*newNode);
    }
    else {
        std::cout << "La valeur 44 n'as pas pu être supprimé car elle n'existe pas" << std::endl;
    }

    //Question 11
    std::cout << "suppression : " << std::endl;
    delete_tree(newNode);
    // pretty_print_left_right(*newNode);

    //EXO 2
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "-----------------EXERCICE 2------------------" << std::endl;
    Node* noeud {create_node(5)};
    noeud->insert(3);
    noeud->insert(7);
    noeud->insert(4);
    noeud->insert(6);
    noeud->insert(8);
    noeud->insert(1);
    noeud->insert(9);
    noeud->insert(0);

    std::cout << "L'arbre après initialisation (question 1): " << std::endl;
    pretty_print_left_right(*noeud);

    std::cout << "Affichage infixe (question 2): " << std::endl;
    noeud->display_infixe();

    std::cout << "Somme à partir du chemin préfixe : " << std::endl;
    std::vector<Node const*> noeud_prefixe {noeud->prefixe()};
    int somme {0};
    for(int i {0}; i<noeud_prefixe.size(); i++){
        somme += noeud_prefixe[i]->value;
    }
    std::cout << "Somme = " << somme << std::endl;

    std::cout << "Hauteur de l'arbre : " << noeud->height() << std::endl;

    return 0;
}