#include "MainWindow.h"
#include <QStackedWidget>

namespace tetris::view::gui {

 MainWindow::MainWindow(MenuScene &menuScene, TetrisScene& tetrisScene, QWidget *parent)
   : QMainWindow(parent), menuScene(menuScene), tetrisScene(tetrisScene) {
  QStackedWidget* stackedWidget = new QStackedWidget(this);
  stackedWidget->addWidget(&tetrisScene);
  stackedWidget->addWidget(&menuScene);
  setCentralWidget(stackedWidget);
  currentSceneIndex = 0;
  this->show();
 }

	void MainWindow::setGameScene() {
  QStackedWidget* stackedWidget = qobject_cast<QStackedWidget*>(centralWidget());
  if (stackedWidget) {
    stackedWidget->setCurrentWidget(&tetrisScene);
  }
 }

 void MainWindow::setMenuScene() {
  QStackedWidget* stackedWidget = qobject_cast<QStackedWidget*>(centralWidget());
  if (stackedWidget) {
    stackedWidget->setCurrentWidget(&menuScene);
  }
 }

} // namespace tetris::view::gui