#ifndef TEMP2_H
#define TEMP2_H

#include <QDialog>

namespace Ui {
class temp2;
}

class temp2 : public QDialog
{
    Q_OBJECT

public:
    explicit temp2(QWidget *parent = nullptr);
    ~temp2();

private slots:
    void on_pushButton_nxt_2_clicked();

    void on_pushButton_nxt_clicked();

private:
    Ui::temp2 *ui;
};

#endif // TEMP2_H
