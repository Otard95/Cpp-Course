#include <iostream>
#include "Headers/GameManager.h"
#include "Headers/CharacterClass.h"
#include "Headers/Utils.h"

using namespace std;

GameManager& GameManager::Instance () {

  static GameManager m_game_manager;
  return m_game_manager;

}

void GameManager::init () {

  /**
   * ## Get player count
  */

  int player_count = Utils::get_int_range(2, 7, "How many players are there(2-7): ");
  cout << "============================================\n" << endl;

  /**
   * Create the players
  */

  for (int i = 0; i < player_count; i++) {

    // Temporary variables for user input
    string name;
    int character_class;
    // get the players name
    cout << "Player " << (i+1) << " enter you name: ";
    getline(cin, name);
    
    // Print the CharacterClass options
    for (auto cc = CharacterClass::First; cc < CharacterClass::Count; ++cc)
    {
      cout << cc << ": " << CharacterClassNames.at(cc) << endl;
    }
    // Get the players choise
    character_class = Utils::get_int_range
    (
      static_cast<int>(CharacterClass::First),
      (static_cast<int>(CharacterClass::Count) - 1),
      "Select a class(number): "
    );
    cout << "============================================\n" << endl;

    // Create the player
    shared_ptr<Player> p(new Player (name, character_class));
    // and add the player to the player-list
    m_players.push_back(p);

  }

  for (auto p : m_players) {
    cout
        << "Player "
        << p->get_name()
        << " has chosen class: "
        << CharacterClassNames.at( p->get_class() )
        << endl;
    
    //p->print_attacks();
    cout << endl;

  }

}

void GameManager::run () {

  int round = 0;

  while (m_players.size() > 0) {

    cout
      << " _                      __    __           __    _     __    _     _     _ " << endl
      << "|_) _    __  _|   /|     _)   __)   |_|   |_    |_      /   (_)   (_|   / \\" << endl
      << "| \\(_)|_|| |(_|    |    /__   __)     |   __)   |_)    /    (_)    _|   \\_/" << endl
      << endl;

    for (auto player : m_players) {

      cout << player->get_name() << "'s turn" << endl;

      player->print_attacks();

      int choise = Utils::get_int_range(1, 3, "Select ability(number): ");

      player->set_ability(choise);

      int i = 1; // i = index + 1;
      for (auto player : m_players) {
        cout << i << ": " << player->get_name() << endl;
        i++;
      }

      choise = Utils::get_int_range(1, m_players.size(), "Select a target: ");

      //                                v convert back to index
      player->set_target(m_players.at(choise-1));

      cout << "\n============================================\n" << endl;

    }

    for (auto player : m_players) {
      player->use_ability();
    }
    
    player_vector_iterator iter = m_players.begin();
    while ( iter != m_players.end() ) {
      (*iter)->update();
      if ((*iter)->is_dead()) {
        iter->reset();
        m_players.erase(iter);
      } else {
        iter++;
      }
    }

    // reverse to_delete
    // loop through and delete from m_players

    round++;
  }

}

