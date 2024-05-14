#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsView>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include "Observer.h"
#include "Game.h"

namespace tetris::view::gui {
	using namespace common;

	class MenuScene : public QWidget {
	Q_OBJECT

	private:
		QVBoxLayout *layout;
		QLabel *title;
		QPushButton *playButton;
		QPushButton *quitButton;
		QLabel *gameTypeLabel;
		QComboBox *gameTypeComboBox;
		QLineEdit *additionalParameterInput;
		QLabel *difficultyLabel;
		QComboBox *difficultyComboBox;
		QCheckBox *blocksCheckBox;
		QLineEdit *nbBlocksInput;
		QPushButton *settingsReturnButton;
		QPushButton *confirmButton;


		void showGameSettings();

		void closeGameSettings();

	public:

		explicit MenuScene(QWidget *parent = nullptr);

		~MenuScene() override;

		void updateCheckBoxParameters(bool checked);

		void updateAdditionalParameterInputDisplay(int index);
	};

} // namespace tetris::view::gui

#endif //MENUSCENE_H