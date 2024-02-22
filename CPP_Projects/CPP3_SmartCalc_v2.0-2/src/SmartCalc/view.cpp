#include "view.h"

#include "../mvc/controller.h"
#include "ui_view.h"

View::View(QWidget *parent, s21::Controller *controller)
    : QMainWindow(parent), ui_(new Ui::View), controller_(controller) {
  ui_->setupUi(this);

  QList<QPushButton *> Arifmetic = {ui_->pushButton_add, ui_->pushButton_sub,
                                    ui_->pushButton_div, ui_->pushButton_mult,
                                    ui_->pushButton_mod, ui_->pushButton_pow};

  QList<QPushButton *> Numbers = {ui_->pushButton_0,
                                  ui_->pushButton_1,
                                  ui_->pushButton_2,
                                  ui_->pushButton_3,
                                  ui_->pushButton_4,
                                  ui_->pushButton_5,
                                  ui_->pushButton_6,
                                  ui_->pushButton_7,
                                  ui_->pushButton_8,
                                  ui_->pushButton_9,
                                  ui_->pushButton_x,
                                  ui_->pushButton_open_bracket,
                                  ui_->pushButton_close_bracket};
  QList<QPushButton *> Functions = {
      ui_->pushButton_sin,  ui_->pushButton_cos,  ui_->pushButton_tan,
      ui_->pushButton_asin, ui_->pushButton_acos, ui_->pushButton_atan,
      ui_->pushButton_sqrt, ui_->pushButton_ln,   ui_->pushButton_lod};

  for (QPushButton *Arifmetic : Arifmetic) {
    connect(Arifmetic, &QPushButton::clicked, this, &View::Arifmetic);
  }
  for (QPushButton *Numbers : Numbers) {
    connect(Numbers, &QPushButton::clicked, this, &View::Numbers);
  }
  for (QPushButton *Functions : Functions) {
    connect(Functions, &QPushButton::clicked, this, &View::Functions);
  }

  connect(ui_->pushButton_e, SIGNAL(clicked()), this, SLOT(ButtonE()));
  connect(ui_->pushButton_dot, SIGNAL(clicked()), this, SLOT(ButtonDot()));
  connect(ui_->pushButton_unarny, SIGNAL(clicked()), this, SLOT(ButtonUnarny()));
  connect(ui_->pushButton_delete, SIGNAL(clicked()), this, SLOT(ButtonDelete()));
  connect(ui_->pushButton_ac, SIGNAL(clicked()), this, SLOT(ButtonAc()));
  connect(ui_->pushButton_calculate, SIGNAL(clicked()), this,
          SLOT(ButtonCalculate()));
  connect(ui_->pushButton_graphic, SIGNAL(clicked()), this,
          SLOT(ButtonGraphic()));

  ui_->pushButton_dot->setCheckable(false);
  ui_->pushButton_add->setCheckable(false);
  ui_->pushButton_sub->setCheckable(false);
  ui_->pushButton_e->setCheckable(false);

  ui_->pushButton_div->setCheckable(true);
  ui_->pushButton_mult->setCheckable(true);
  ui_->pushButton_pow->setCheckable(true);
}

View::~View() { delete ui_; }

void View::Numbers() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr) {
    ui_->input_str1->setText(ui_->input_str1->text() + button->text());
    ui_->output_str2->setText("");
    ui_->pushButton_add->setCheckable(false);
    ui_->pushButton_sub->setCheckable(false);
    ui_->pushButton_div->setCheckable(false);
    ui_->pushButton_mult->setCheckable(false);
    ui_->pushButton_pow->setCheckable(false);
  }
}

void View::Arifmetic() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr && !(button->isCheckable())) {
    ui_->input_str1->setText(ui_->input_str1->text() + button->text());
    ui_->output_str2->setText("");
    ui_->pushButton_e->setCheckable(false);
    ui_->pushButton_dot->setCheckable(false);
    ui_->pushButton_add->setCheckable(true);
    ui_->pushButton_sub->setCheckable(true);
    ui_->pushButton_div->setCheckable(true);
    ui_->pushButton_mult->setCheckable(true);
    ui_->pushButton_pow->setCheckable(true);
  }
}

void View::Functions() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr) {
    QString currentText = button->text();
    // Находим индекс символа x
    int indexOfOpenParenthesis = currentText.indexOf('x');
    if (indexOfOpenParenthesis != -1) {
      QString newText = currentText.left(indexOfOpenParenthesis);
      ui_->input_str1->setText(ui_->input_str1->text() + newText);
    }
  }
}

void View::ButtonAc() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr) {
    ui_->input_str1->clear();
    ui_->output_str2->clear();
    ui_->pushButton_dot->setCheckable(false);
    ui_->pushButton_add->setCheckable(false);
    ui_->pushButton_sub->setCheckable(false);
    ui_->pushButton_div->setCheckable(true);
    ui_->pushButton_mult->setCheckable(true);
    ui_->pushButton_pow->setCheckable(true);
  }
}

void View::ButtonDelete() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr) {
    ui_->input_str1->backspace();
    ui_->pushButton_add->setCheckable(false);
    ui_->pushButton_sub->setCheckable(false);
    ui_->pushButton_div->setCheckable(false);
    ui_->pushButton_mult->setCheckable(false);
    ui_->pushButton_pow->setCheckable(false);
    ui_->pushButton_dot->setCheckable(false);
    ui_->pushButton_e->setCheckable(false);
  }
}

void View::ButtonDot() {
  if (!(ui_->pushButton_dot->isCheckable())) {
    ui_->input_str1->setText(ui_->input_str1->text() + '.');
    ui_->pushButton_dot->setCheckable(true);
  }
}

void View::ButtonE() {
  if (!(ui_->pushButton_e->isCheckable())) {
    ui_->input_str1->setText(ui_->input_str1->text() + 'e');
    ui_->pushButton_e->setCheckable(true);
  }
}

void View::ButtonUnarny() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr) {
    ui_->input_str1->setText(ui_->input_str1->text() + "(-");
    ui_->output_str2->setText("");
  }
}

/* Convert QString to char */
char *View::InputLineToChar() {
  QByteArray expressionBytes = ui_->input_str1->text().toUtf8();
  char *line = new char[expressionBytes.size() + 1];
  strcpy(line, expressionBytes.constData());
  return line;
}

/* Plot the graph */
void View::PlotGraph(QVector<double> *x_data, QVector<double> *y_data) {
  ui_->widget_graph->clearGraphs();
  ui_->widget_graph->addGraph();
  ui_->widget_graph->graph(0)->setData(*x_data, *y_data);
  ui_->widget_graph->setInteraction(QCP::iRangeZoom, true);
  ui_->widget_graph->setInteraction(QCP::iRangeDrag, true);
  ui_->widget_graph->replot();
}

void View::ButtonCalculate() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr) {
    ui_->output_str2->clear();
    char *line = InputLineToChar();
    double variable_x = ui_->doubleSpinBox_x->value();
    try {
      double result = controller_->Calculator(line, variable_x);
      QString str_result = QString::number(result, 'g', 10);
      ui_->output_str2->setText(str_result);
    } catch (...) {
      ui_->output_str2->setText("Input data is not correct!");
    }
    delete[] line;
  }
}

void View::ButtonGraphic() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  if (button != nullptr) {
    bool flag_print_graph = true;
    double X_max = ui_->doubleSpinBox_Xmax->value();
    double X_min = ui_->doubleSpinBox_Xmin->value();
    double Y_max = ui_->doubleSpinBox_Ymax->value();
    double Y_min = ui_->doubleSpinBox_Ymin->value();
    if (X_min >= X_max || Y_min >= Y_max) {
      ui_->output_str2->setText("Wrong coordinates input data!");
    } else {
      ui_->output_str2->clear();
      char *line = InputLineToChar();
      QVector<double> x_data, y_data;
      double step = (X_max - X_min) / (10000 - 1);
      ui_->widget_graph->xAxis->setRange(X_min, X_max);
      ui_->widget_graph->yAxis->setRange(Y_min, Y_max);
      for (double variable_x = X_min; variable_x <= X_max; variable_x += step) {
        try {
          double result = controller_->Calculator(line, variable_x);
          if (std::isfinite(result) && result <= Y_max && result >= Y_min) {
            x_data.push_back(variable_x);
            y_data.push_back(result);
          } else {
            x_data.push_back(variable_x);
            y_data.push_back(qQNaN());
          }
        } catch (...) {
          ui_->output_str2->setText("Input data is not correct!");
          flag_print_graph = false;
        }
      }
      if (flag_print_graph) {
        PlotGraph(&x_data, &y_data);
      }
      delete[] line;
    }
  }
}
