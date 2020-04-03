/*
*   ipcam_monitor is a small QT GUI for viewing ip cams in individual windows
*
*   Copyright (c) GB Tony Cabrera 2018
*/

#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMediaPlayer>
#include <QWidget>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
class QAbstractButton;
QT_END_NAMESPACE

class VideoPlayer : public QWidget
{
    Q_OBJECT
	public:
    	VideoPlayer(QWidget *parent = 0);
    	~VideoPlayer();
		void setUrl(const QString &myurl);
	
	public slots:
		void play();
		void newWindow();
		void killAll();

	private slots:

	private:
    	QMediaPlayer* mediaPlayer;
		QLineEdit *urlText;
		QAbstractButton *playButton;
		QAbstractButton *newButton;
		QAbstractButton *killButton;
		VideoPlayer *nWin;
};

#endif
