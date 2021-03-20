#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#define VMAX 8
#define TAMANHO 0.3



typedef struct Vetor{
    sf::Vector2f posicao;
    sf::Vector2f velocidade;
    sf::Vector2f aceleracao;
}Vetor;
//ListaTextura, neste contexto, é uma lista circular para os enderecos das imagens a serem desenhadas
//Desta forma, quando se percorre a lista, desenhando cada imagem, ten-se o efeito do personagem andando
//Sei que nojogo do simao sera com classes e orientado a objetos, mas aqui da pra se ter uma ideia de como
//usar o sfml... 
typedef struct ListaTexturas{
    sf::Texture p;
    ListaTexturas *proximo;
}ListaTexturas;

typedef struct Animacao{
    ListaTexturas *primeira;
    ListaTexturas *ponteiro;
    sf::Sprite sprite;
    Vetor vector;
    int direcao;
}Animacao;

Animacao* criarAnimacao(void){
    Animacao *nova = new Animacao();
    return nova;
}

void setPOS(Animacao *objeto,sf::Vector2f posicao,sf::Vector2f origem,sf::Vector2f escala){
    objeto->sprite.setPosition(posicao);
    objeto->vector.posicao = posicao;
    objeto->sprite.setOrigin(origem);
    objeto->sprite.setScale(escala);
    objeto->direcao = 1;
}

void incrementoVelocidade(Animacao *objeto){
    //Checa se a velocidade não vai passar do valor limitante para que ele não corra d+
    if( abs( objeto->vector.velocidade.x + objeto->vector.aceleracao.x ) < VMAX)
        objeto->vector.velocidade.x += objeto->vector.aceleracao.x;

    //Simula de uma forma simplificada e ate grotesca os atritos que fazem ele parar
    if( objeto->vector.aceleracao.x == 0 && objeto->vector.velocidade.x != 0){

        //Para que a velocidade nao fique se acumulando proximo a zero, seta-se ela como zero
        if(abs(objeto->vector.velocidade.x) <= 0.5)
            objeto->vector.velocidade.x = 0;
        else if(objeto->vector.velocidade.x > 0)
            objeto->vector.velocidade.x -= 0.5;
        else
            objeto->vector.velocidade.x += 0.5;
    }
}

void incrementoPosicao(Animacao *objeto){
    //incrementa a velocidade e seleciona a posicao
    objeto->vector.posicao.x += objeto->vector.velocidade.x;
    objeto->sprite.setPosition(objeto->vector.posicao);
    //Confere se não está andando para fazer com que o sprite fique constante
    if(objeto->vector.velocidade.x == 0)
        objeto->ponteiro = objeto->primeira;
    else{
        objeto->ponteiro = objeto->ponteiro->proximo;
    }
    objeto->sprite.setTexture(objeto->ponteiro->p);
}

void atualizaPosicao(Animacao *objeto,sf::Vector2f direcao){
    //O objeto, personagem, sempre deve estar virado na mesma direcao e sentido da aceleracao

    //Pode-se aqui implementar um incrementador para que quando o usuario mudar o sentido
    //da aceleracao, fazer o incremento de posicao que ajusta o personagem a seu lugar correto
    ///terminar..........
    if( direcao.x > 0 ){
        objeto->sprite.setScale(sf::Vector2f(TAMANHO,TAMANHO));
        if(objeto->direcao < 0){
            objeto->vector.posicao.x -= 200;
        }
        objeto->direcao = 1;
    }
    else if(direcao.x < 0){
        objeto->sprite.setScale(sf::Vector2f(-TAMANHO,TAMANHO));
        if(objeto->direcao > 0){
            objeto->vector.posicao.x += 200;
        }
        objeto->direcao = -1;
    }  

    //Setando a direcao da aceleracao
    objeto->vector.aceleracao.x = direcao.x;
    incrementoVelocidade(objeto);
    incrementoPosicao(objeto);
}


ListaTexturas* criar(){
    return NULL;
}

ListaTexturas* adicionar(ListaTexturas *lista,const char* endereco){
    //Lista circular pra poder percorrer mais de boas
    ListaTexturas *nova = new ListaTexturas();
    if(lista == NULL)
        nova->proximo = nova;
    else{
        nova->proximo = lista->proximo; 
        lista->proximo = nova;  
    }
    nova->p.loadFromFile(endereco);
    return nova;
}
