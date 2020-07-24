#ifndef TEMP4_H
#define TEMP4_H

#include <QDialog>

namespace Ui {
class temp4;
}

class temp4 : public QDialog
{
    Q_OBJECT

public:
    explicit temp4(QWidget *parent = nullptr);
    ~temp4();

private slots:
    void on_pushButton_nxt_2_clicked();

private:
    Ui::temp4 *ui;
};

#endif // TEMP4_H
