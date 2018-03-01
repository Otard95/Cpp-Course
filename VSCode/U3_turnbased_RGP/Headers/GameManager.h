#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <vector>
#include <memory>
#include "Player.h"

typedef vector<shared_ptr<Player>> player_vector;
typedef player_vector::iterator player_vector_iterator;

using namespace std;

class GameManager {

  public:
    static GameManager& Instance();

    void init ();
    void run ();

    ~GameManager() = default;

  private:
    GameManager () = default;
    GameManager(GameManager const&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    static GameManager m_game_manager;

    player_vector m_players;

};

#endif