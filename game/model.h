#ifndef ___MODEL____H_
#define ___MODEL____H_

#include <vector>
#include <memory>

#include "../view/view.h"
#include "../controller/controller.h"

enum Action;

class Model{
  std::vector<std::unique_ptr<View>> views;
  std::unique_ptr<Controller> control;
 protected:
  void addView(std::unique_ptr<View> v);
  void addController(std::unique_ptr<Controller> v);
  bool hasController();
 public:
  Model();
  virtual ~Model() = default;
  void updateViews(int, int, char);
  void updateViews(const std::string& s);
  void updateViews(std::string race, int gold, int floor, int HP, int atk, int def, std::string action);
  Action getAction();
  void displayViews();
};

#endif
