#ifndef WH_H
#define WH_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QList>


namespace Ui {
class wh;
}

class wh : public QMainWindow
{
    Q_OBJECT

public:
    explicit wh(QWidget *parent = 0);
    ~wh();

private slots:
    void updateTime();
    void updateTimeTXT();

private:
    Ui::wh *ui;
    QTimer timer;
    QTimer timertxt;
};

#endif // WH_H
