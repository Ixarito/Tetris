#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include "Grid.h"

class TetrisWindow : public QMainWindow
{
Q_OBJECT

public:
    TetrisWindow(QWidget *parent = nullptr);

    ~TetrisWindow();

    void updateGameBoard(const tetris::model::Grid::GridView_type& gridView);

private:
    QGraphicsView *gameBoard;
    QLabel *scoreLabel;
    QLabel *levelLabel;

private slots:
    void startGame();
    void stopGame();
    void movePiece();
};