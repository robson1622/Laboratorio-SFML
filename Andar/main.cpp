#include "Lista.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

//Caso haja problemas para compilar, utilize o comando a baixo no terminal linux
//g++ *.cpp -o exe -lsfml-graphics -lsfml-window -lsfml-system

ListaTexturas* andarIMGS();

int main(){
    sf::RenderWindow janela(sf::VideoMode(1024,512),"Arquivo de testes");
    sf::Event event;
    Vetor *v;
    ListaTexturas *l = andarIMGS();
    Animacao *ogro = criarAnimacao();
    ogro->primeira = l;
    ogro->ponteiro = l;
    setPOS(ogro,sf::Vector2f(0,260),sf::Vector2f(0,0),sf::Vector2f(TAMANHO,TAMANHO));
    janela.setFramerateLimit(60);

    sf::Texture bg;
    bg.loadFromFile("bg.png");
    sf::Sprite background;
    background.setTexture(bg);
    background.setPosition(sf::Vector2f(0,0));
    background.setOrigin(sf::Vector2f(0,0));

    while (janela.isOpen()){
        while (janela.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                janela.close();
        }

        janela.clear(sf::Color::White);
        janela.draw(background);
        janela.draw(ogro->sprite);
        janela.display();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            atualizaPosicao(ogro,sf::Vector2f(1,0));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            atualizaPosicao(ogro,sf::Vector2f(-1,0));
        }
        else{
            atualizaPosicao(ogro,sf::Vector2f(0,0));
        }
                
    }
    return 0;
}

ListaTexturas* andarIMGS(){
    ListaTexturas *l = criar();
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_003.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_002.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_001.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_000.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_017.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_016.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_015.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_014.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_013.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_012.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_011.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_010.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_009.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_008.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_007.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_006.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_005.png");
    l = adicionar(l,"PNG/Minotaur_01/Walking/Minotaur_01_Walking_004.png");
    return l;
}