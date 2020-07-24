#ifndef TEMP3_H
#define TEMP3_H

#include <QDialog>

namespace Ui {
class temp3;
}

class temp3 : public QDialog
{
    Q_OBJECT

public:
    explicit temp3(QWidget *parent = nullptr);
    ~temp3();

private slots:
    void on_pushButton_nxt_2_clicked();

    void on_pushButton_nxt_clicked();

private:
    Ui::temp3 *ui;
};

#endif // TEMP3_H
