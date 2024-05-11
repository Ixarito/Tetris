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
		QPushButton *settingsReturnButton;
		QPushButton *confirmButton;



		void showGameSettings();

		void closeGameSettings();

		void updateAdditionalParameterInputDisplay(int index);
	public:

		explicit MenuScene(QWidget *parent = nullptr);

		~MenuScene() override;
	};

} // namespace tetris::view::gui