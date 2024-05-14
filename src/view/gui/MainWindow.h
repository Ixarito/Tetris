#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MenuScene.h"
#include "TetrisScene.h"

namespace tetris::view::gui {

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    MenuScene& menuScene;
    TetrisScene& tetrisScene;
    int currentSceneIndex;

public:
    explicit MainWindow(MenuScene &menuScene, TetrisScene& tetrisScene, QWidget *parent = nullptr);

    void setGameScene();

    void setMenuScene();
};

} // namespace tetris::view::gui

#endif //MAINWINDOW_H