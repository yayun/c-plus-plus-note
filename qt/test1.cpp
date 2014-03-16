#include<QtGui/QApplication>
#include<QtGui>
#include <QFileDialog>
#include <QErrorMessage>
#include <QMessageBox>

#include<sendemail_ui.h>
#include<ui_sendemail.h>
#include "./src/SmtpMime" 
using namespace std;

SendEmail::SendEmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendEmail)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(on_sendEmail_clicked()));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(on_addAttachment_clicked()));
}

SendEmail::~SendEmail()
{
    delete ui;
}
void SendEmail::on_sendEmail_clicked()
{
    QString user = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString attachment=ui->lineEdit_6->text();

    EmailAddress *sender = stringToEmail(ui->lineEdit_3->text());

    QStringList rcptStringList = ui->lineEdit_4->text().split(';');

    QString subject = ui->lineEdit_5->text();
    QString html = ui->textEdit->toHtml();

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser(user);
    smtp.setPassword(password);

    MimeMessage message;

    message.setSender(sender);
    message.setSubject(subject);

    for (int i = 0; i < rcptStringList.size(); ++i)
         message.addRecipient(stringToEmail(rcptStringList.at(i)));

    MimeHtml content;
    content.setHtml(html);

    message.addPart(&content);
    message.addPart(new MimeAttachment(new QFile(attachment)));

    if (!smtp.connectToHost())
    {
        errorMessage("Connection Failed");
        return;
    }
    smtp.login();
    if (!smtp.sendMail(message))
    {
        errorMessage("Mail sending failed");
        return;
    }
    else
    {
        QMessageBox okMessage (this);
        okMessage.setText("The email was succesfully sended.");
        okMessage.exec();
    }

    smtp.quit();

}

void SendEmail::on_addAttachment_clicked()
{
}
EmailAddress* SendEmail::stringToEmail(const QString &str)
{
    int p1 = str.indexOf("<");
    int p2 = str.indexOf(">");

    if (p1 == -1)
    {
        // no name, only email address
        return new EmailAddress(str);
    }
    else
    {
        return new EmailAddress(str.mid(p1 + 1, p2 - p1 - 1), str.left(p1));
    }

}
void SendEmail::errorMessage(const QString &message)
{
    QErrorMessage err (this);

    err.showMessage(message);

    err.exec();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SendEmail form (NULL);

    form.setWindowTitle("SmtpClient");

    form.show();

    app.exec();

}
