#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MenuController.h"
#include "MenuScene.h"
#include "TetrisScene.h"

namespace tetris::view::gui {

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    MenuScene& menuScene;
    TetrisScene& tetrisScene;
    int currentSceneIndex;

public slots:
	void changeScene(QWidget* scene);

public:
    explicit MainWindow(MenuScene &menuScene, TetrisScene& tetrisScene, QWidget *parent = nullptr);
};

} // namespace tetris::view::gui

#endif //MAINWINDOW_H