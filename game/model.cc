#include "model.h"
#include "state.h"
#include "../view/view.h"
#include "../view/standard.h"
//#include "../view/curseView.h"
#include "../view/writtenView.h"
#include "../controller/controller.h"
#include "../controller/keyboard.h"
//#include "../controller/curseControl.h"


Model::Model() {
  //views.emplace_back(std::make_unique<Standard>(x, y, *this));
  //views.emplace_back(std::make_unique<Written>(x, y, *this));
  //control = std::make_unique<Keyboard>();
  //control{std::make_unique<CurseKeyboard>()}
}

void Model::updateViews(std::string race, int gold, int floor, int HP, int atk, int def, std::string action){
  for( auto& view: views ){
    view->update(race, gold, floor, HP, atk, def, action);
  }
}

void Model::updateViews(int row, int col, char disp){
  for( auto& view: views ){
    view->update(row, col, disp);
  }
}

void Model::updateViews(const std::string& s){
  for( auto& view: views ){
    view->update(s);
  }
}

void Model::displayViews(){
  for( auto& view: views ){
    view->updateView();
  }
}

void Model::addView(std::unique_ptr<View> v){
  views.emplace_back(std::move(v));
}
void Model::addController(std::unique_ptr<Controller> c){
  control = std::move(c);
}
bool Model::hasController(){
  return control != nullptr;
}

Action Model::getAction(){
  return control->getAction();
}
