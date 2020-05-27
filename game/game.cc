#include "game.h"
using namespace std;
#include "subjects/factory/playerFactory.h"
#include "subjects/characters/playable/PC.h"
#include "../view/view.h"
// #include "../view/curseView.h"
// #include "../controller/curseControl.h"
#include "../view/standard.h"
#include "../view/writtenView.h"
#include "../controller/controller.h"

#include "../controller/keyboard.h"

#include "floor.h"

using namespace std;

Game::Game(bool curses, string loadfile) : Model{} { // new game constructor, no loading from file

  // set view and controller
  // if ( curses ){ // WITH CURSES
  //   addView(std::move(std::make_unique<Curses>("select Race", 0,1,0,0,0," ",*this))); // add curses view
  //   if ( !hasController() ){
  //     addController(std::move(std::make_unique<CurseKeyboard>())); // curse Keyboard controller
  //   }
  // } 
  
  // else { // NO CURSES
  addView(std::move(std::make_unique<Standard>(*this))); // add standard view
  addView(std::move(std::make_unique<Written>("select Race", 0,1,0,0,0," ",*this))); // add written view
  if ( !hasController() ) {
  addController(std::move(std::make_unique<Keyboard>())); // Keyboard controller
  }
 //}
  // initialize first floor

    if (loadfile == "") {
  floors.emplace_back(std::make_unique<Floor>(*this, currFloor));
     } else  {// always read terrain from this file
     floors.emplace_back(std::make_unique<Floor>(*this, currFloor, loadfile));
     }
  

  // generating player
  std::string playername;
  std::cout << "Please choose Player {h,e,d,o} for {Human, Elves, Dwarf, Orc} ";
  std::cin >> playername;
  gamePlayer = PlayerFactory::generate(floors[currFloor-1]->getplayerX(), floors[currFloor-1]->getplayerY(), playername );
  (playername == "h") ? race = "Human" :
  (playername == "e") ? race = "Elves" :
  (playername == "d") ? race = "Dwarf" : race = "Orc" ;

  cout << "generated player\n";

  floors[currFloor]->setPlayer(gamePlayer);

  updateViews(getRace(), gamePlayer->getGold(), currFloor, gamePlayer->getHP(), gamePlayer->getAtk(), gamePlayer->getDef(), "The Player chracter has spawned");
  
}

void Game::play() {
  // int currX = gamePlayer->getInfo().x;
  // int currY = gamePlayer->getInfo().y;
  // int newX = currX;
  // int newY = currY;
  Action a;
  while(std::cin){
    displayViews();
    a = getAction(); // what to do
    if ( Action::NONE == a ) continue;
    if ( Action::INVALID == a ) {
      floors[currFloor-1]->updateArgs("sorry, illegal move"); continue;
    }
    if ((a == Action::USE) || (a == Action::ATTACK)) {
      Action b = getAction();
      floors[currFloor-1]->action(a, b);
    }
    else {
      floors[currFloor-1]->move(a);
    }
  }
}
