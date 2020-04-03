/*
*	ipcam_monitor is a small QT GUI for viewing ip cams in individual windows
*
*	Copyright (c) GB Tony Cabrera 2018
*/

#include "videoplayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	const QString myurl = "http://";
	
	VideoPlayer player;
	
	player.resize(640, 480);
	player.show();
//	player.setUrl(myurl);
//	player.play();
	
	return app.exec();
}
