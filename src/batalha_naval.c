/**
# Especifica��es Batalha Naval

Cada jogador posiciona os seus navios no campo em posi��es aleat�rias

## Tipos de Navio:
- Lancha                (Tamanho: 1 - Quantidade: 5) ?
- Submarino             (Tamanho: 2 - Quantidade: 4 - Quadros: 8)
- Contra-torpedeiros    (Tamanho: 3 - Quantidade: 3 - Quadros: 9)
- Navio-tanque          (Tamanho: 4 - Quantidade: 2 - Quadros: 8)
- Porta-avi�o           (Tamanho: 5 - Quantidade: 1 - Quadros: 5)
- Posi��oOcupadas: 30

## Jogadores
- Quantidade: 2

## Passos
Passos para a constru��o do jogo
1. Definir campos
-- Tamanho fixo (10x10)
-- Limpar campo (~)
-- c_navios_1
-- c_navios_2
-- c_ataque_1
-- c_ataque_2

2. Marcar navios
-- Jogador X coloca navios no campo cnavios1
-- Menu tipo de navios e quantidade
-- Pontos do navio

3. Jogada
-- Jogador 1 faz jogada
-- Pede posi��o (l, c)
-- Se tiver '.' ok
-- Ver em c_navios_2 (l, c)
--- Se '.' marca '~' em c_ataque_1
--- Se '*' marca '*' em c_ataque_1
---- Incrementar Jogador.Pontua��o

4. VerificarVencedor
- Se Jogador.Pontua��o == 0 Jogador Ganhou

9. Desenho do Tabuleiro
    0   1   2   3   4   5   6   7   8   9
  -----------------------------------------
0 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
1 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
2 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
3 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
4 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
5 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
6 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
7 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
8 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------
9 |   |   |   |   |   |   |   |   |   |   |
  -----------------------------------------

**/

void main()
{
    //jogar
}
