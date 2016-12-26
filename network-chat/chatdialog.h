#define FN_CALL __cdecl
#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <string>
#include "ui_chatdialog.h"
#include "client.h"

class ChatDialog : public QDialog, private Ui::ChatDialog
{
	Q_OBJECT

public:
	ChatDialog(QWidget *parent = 0);

	public slots:
	void appendMessage(const QString &from, const QString &message);

private: 
	private slots:
	void newParticipant(const QString &nick);
	void returnPressed();

	void participantLeft(const QString &nick);
	void showInformation();

private:
	Client client;
	QString myNickName;
	QTextTableFormat tableFormat;






};

#ifdef __cplusplus
extern "C" {
#endif 
	void HelloMessage();
#ifdef __cplusplus
}
#endif 
#endif