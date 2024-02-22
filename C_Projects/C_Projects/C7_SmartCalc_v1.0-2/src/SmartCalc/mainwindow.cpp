#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Backend/smart_calc_v1.0.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_x ,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_open_bracket,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_close_bracket,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_add,SIGNAL(clicked()),this,SLOT(arifmetic_operations()));
    connect(ui->pushButton_sub,SIGNAL(clicked()),this,SLOT(arifmetic_operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(arifmetic_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(arifmetic_operations()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(arifmetic_operations()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(arifmetic_operations()));

    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(functions()));
    connect(ui->pushButton_lod,SIGNAL(clicked()),this,SLOT(functions()));

    connect(ui->pushButton_delete,SIGNAL(clicked()),this,SLOT(button_delete_click()));
    connect(ui->pushButton_ac,SIGNAL(clicked()),this,SLOT(button_ac_click()));
    connect(ui->pushButton_calculate,SIGNAL(clicked()),this,SLOT(on_pushButton_calculate_clicked()));
    connect(ui->pushButton_graphic,SIGNAL(clicked()),this,SLOT(on_pushButton_graphic_clicked()));

    ui->pushButton_dot->setCheckable(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {
        ui->input_str1->setText(ui->input_str1->text() + button->text());
        ui->output_str2->setText("");
    } else {
            ui->output_str2->setText("Нажата неизвестная кнопка");
    }
}

void MainWindow::arifmetic_operations() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {
        ui->input_str1->setText(ui->input_str1->text() + button->text());
        ui->output_str2->setText("");
        ui->pushButton_dot->setCheckable(false);
    } else {
            ui->output_str2->setText("Нажата неизвестная кнопка");
    }
}

void MainWindow::functions() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {
        QString currentText = button->text();  // Получаем текущий текст из поля ввода
        int indexOfOpenParenthesis = currentText.indexOf('x');  // Находим индекс символа 'x'
        if (indexOfOpenParenthesis != -1) {
            QString newText = currentText.left(indexOfOpenParenthesis);  // Извлекаем подстроку до символа 'x'
            ui->input_str1->setText(ui->input_str1->text() + newText);  // Добавляем текст кнопки к подстроке и устанавливаем новый текст в поле ввода
        }
    } else {
            ui->output_str2->setText("Нажата неизвестная кнопка");
    }
}

void MainWindow::on_pushButton_unarny_clicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {
        ui->input_str1->setText(ui->input_str1->text() + "-(");
        ui->output_str2->setText("");
    } else {
        ui->output_str2->setText("Нажата неизвестная кнопка");
    }
}

void MainWindow::button_ac_click() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {
        ui->input_str1->clear();
        ui->output_str2->clear();
    } else {
            ui->output_str2->setText("Нажата неизвестная кнопка");
    }
}

void MainWindow::button_delete_click() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {
        ui->input_str1->backspace();
    } else {
            ui->output_str2->setText("Нажата неизвестная кнопка");
    }
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->pushButton_dot->isCheckable())) {
        ui->input_str1->setText(ui->input_str1->text() + '.');
        ui->pushButton_dot->setCheckable(true);
    }
}

void MainWindow::on_pushButton_calculate_clicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {
        // Получаем текст из input_str1 с помощью метода text() и затем преобразовать его в QByteArray
        QByteArray expressionBytes = ui->input_str1->text().toUtf8();
        // Создаем динамический массив
        char *expressionStr = new char[expressionBytes.size() + 1];
        // Копируем все в массив expressionStr
        strcpy(expressionStr, expressionBytes.constData());

        int error = 0;
        double variable_x = ui->doubleSpinBox_x->value();
        double result = 0;
        smart_calc(expressionStr, &error, variable_x, &result);

        // Освобождение выделенной памяти
        delete[] expressionStr;
        QString res = QString::number(result, 'g', 10);

        if (error == OK) {
            ui->output_str2->setText(res);
        } else if (error == ERROR_1) {
            ui->output_str2->setText("Wrong number of brackets");
        } else if (error == ERROR_2) {
            ui->output_str2->setText("Incorrect input");
        } else if (error == ERROR_3) {
            ui->output_str2->setText("Error division by zero");
        } else if (error == ERROR_4) {
            ui->output_str2->setText("Not memmory avialable");
        } else {
            ui->output_str2->setText("ERROR!");
        }
    }
}

void MainWindow::on_pushButton_graphic_clicked(){
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button != nullptr) {

        int error = 0;
        double X_max = ui->doubleSpinBox_Xmax->value();
        double X_min = ui->doubleSpinBox_Xmin->value();
        double Y_max = ui->doubleSpinBox_Ymax->value();
        double Y_min = ui->doubleSpinBox_Ymin->value();
        double result = 0;

        if (X_min > X_max || Y_min > Y_max || (Y_min == 0.0 && Y_max == 0.0 && X_min == 0.0 && X_max == 0.0)) {
            ui->output_str2->setText("Wrong coordinates input data!");
        } else {
            // Получаем текст из input_str1 с помощью метода text() и затем преобразовать его в QByteArray
            QByteArray expressionBytes = ui->input_str1->text().toUtf8();
            // Создаем динамический массив
            char *expressionStr = new char[expressionBytes.size() + 1];
            // Копируем все в массив expressionStr
            strcpy(expressionStr, expressionBytes.constData());

            QVector<double> x_data, y_data;
            double step = (X_max - X_min) / (10000 - 1);
            QString res = QString::number(result, 'g', 10);
                ui->widget_graph->xAxis->setRange(X_min, X_max);
                ui->widget_graph->yAxis->setRange(Y_min, Y_max);

                for (double variable_x = X_min; variable_x <= X_max; variable_x += step) {
                    smart_calc(expressionStr, &error, variable_x, &result);
                    if (error == 0 && !std::isnan(result) && std::isfinite(result) &&
                        result <= Y_max && result >= Y_min) {
                      x_data.push_back(variable_x);
                      y_data.push_back(result);
                    } else {
                      x_data.push_back(variable_x);
                      y_data.push_back(qQNaN());
                    }
                  }
                if (error == OK) {
                    // Plot the graph
                    ui->widget_graph->clearGraphs();
                    ui->widget_graph->addGraph();
                    ui->widget_graph->graph(0)->setData(x_data, y_data);
                    ui->widget_graph->setInteraction(QCP::iRangeZoom, true);
                    ui->widget_graph->setInteraction(QCP::iRangeDrag, true);
                    ui->widget_graph->replot();
                } else if (error == ERROR_1) {
                    ui->output_str2->setText("Wrong number of brackets");
                } else if (error == ERROR_2) {
                    ui->output_str2->setText("Incorrect input");
                } else if (error == ERROR_3) {
                    ui->output_str2->setText("Error division by zero");
                } else if (error == ERROR_4) {
                    ui->output_str2->setText("Not memmory avialable");
                } else {
                    ui->output_str2->setText("ERROR!!!");
                }
                // Освобождение выделенной памяти
                delete[] expressionStr;
            }
        }
    }


