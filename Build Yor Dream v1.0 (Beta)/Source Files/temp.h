#ifndef TEMP_H
#define TEMP_H

#include <QDialog>

namespace Ui {
class temp;
}

class temp : public QDialog
{
    Q_OBJECT

public:
    explicit temp(QWidget *parent = nullptr);
    ~temp();

private slots:
    void on_pushButton_go_bck_clicked();

    void on_pushButton_nxt_clicked();

private:
    Ui::temp *ui;
};

#endif // TEMP_H
