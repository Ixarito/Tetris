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
#include <QIntValidator>

namespace tetris::view::gui {
	using namespace common;

	/**
	 * Represents the main menu of the application
	 */
	class MenuScene : public QWidget {
	Q_OBJECT

	private:
		QValidator *IntValidator;
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


	public:

		/**
		 * Creates a Menu scene view
		 * @param parent the parent widget
		 */
		explicit MenuScene(QWidget *parent = nullptr);

		/**
		 * Destructor of Menu Scene
		 */
		~MenuScene() override;

	signals:

		void gameTypeChanged(const int & value);

		void additionalParameterChanged(const int & value);

		void difficultyChanged(const int & value);

		void nbBlocksChanged(const int & value);

		void confirmButtonClicked();

	private slots:

		/**
		 * Displays the game settings
		 */
		void showGameSettings();

		/**
		 * Closes the game settings
		 */
		void closeGameSettings();

		/**
		 * Changes the placeholder of the additional input parameter
		 * @param index the index of the chosen game type
		 */
		void updateAdditionalParameterInputDisplay(int index);

		/**
		 * Changes the visibility of the input that contains the number of blocks already placed before the game starts
		 * @param checked the state of the related checkbox
		 */
		void updateNbBlocksInput(bool checked);

		/**
		 * Called when the game type changes
		 */
		void onGameTypeChange();

		/**
		 * Called when the value to reach for the specified game type change
		 */
		void onGameAdditionalParameterChange();

		/**
		 * Called when the difficulty change
		 */
		void onDifficultyChange();

		/**
		 * Called when the number of already placed blocks change
		 */
		void onAlreadyPlacedValueChange();

		/**
		 * Called when the confirm button is clicked
		 */
		void onConfirmButtonClicked();

	};

} // namespace tetris::view::gui

#endif //MENUSCENE_H