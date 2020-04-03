/*
*   ipcam_monitor is a small QT GUI for viewing ip cams in individual windows
*
*   Copyright (c) GB Tony Cabrera 2018
*/

#include "videoplayer.h"
#include <QtWidgets>
#include <QVideoWidget>
#include <QUrl>

VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget(parent)
    , urlText(0)
    , playButton(0)
    , newButton(0)
    , killButton(0)
{
	mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
	QVideoWidget *videoWidget = new QVideoWidget;

	urlText = new QLineEdit;
	urlText->setPlaceholderText("http://user:password@myipaddress:8080/video.cgi");
    
	playButton = new QPushButton;
	playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
	
	newButton = new QPushButton;
	newButton->setText("New Player");
//	newButton->setIcon(style()->standardIcon(QStyle::SP_VistaShield));
	connect(newButton, SIGNAL(clicked()), this, SLOT(newWindow()));

	killButton = new QPushButton;
	killButton->setText("Exit All");
	connect(killButton, SIGNAL(clicked()), this, SLOT(killAll()), Qt::QueuedConnection);

// LAYOUT
	QBoxLayout *controlLayout = new QHBoxLayout;
	controlLayout->setMargin(0);
	controlLayout->addWidget(urlText);
	controlLayout->addWidget(playButton);
	controlLayout->addWidget(newButton);
	controlLayout->addWidget(killButton);
	QBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(controlLayout);
	layout->addWidget(videoWidget);

	setLayout(layout);
// END LAYOUT

mediaPlayer->setVideoOutput(videoWidget);
}

VideoPlayer::~VideoPlayer()
{
}

void VideoPlayer::setUrl(const QString &myurl)
{
	urlText->setText(myurl);
}

void VideoPlayer::play()
{
	const QString myurl = urlText->text();
	QUrl url = myurl;
	mediaPlayer->setMedia(url);
	mediaPlayer->play();
}

void VideoPlayer::newWindow()
{
	nWin = new VideoPlayer;
	nWin->resize(640, 480);
	nWin->show();
}
void VideoPlayer::killAll()
{
	QApplication::closeAllWindows();
}
