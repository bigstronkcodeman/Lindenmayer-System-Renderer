#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QPushButton>
#include <QToolButton>
#include <QComboBox>
#include <QGraphicsItem>
#include "formpresenter.h"
#include "turtle.h"
#include "graphics_view_zoom.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow
        : public QMainWindow
        , public FormPresenter::View {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initialize_color_combobox();
    void clear_rule_form();

    QLineEdit* get_axiom_textbox();
    QComboBox* get_color_combobox();
    QDoubleSpinBox* get_initial_angle_spinbox();
    QDoubleSpinBox* get_turn_angle_spinbox();
    QDoubleSpinBox* get_turn_increment_spinbox();
    QSpinBox* get_iterations_spinbox();
    QDoubleSpinBox* get_line_length_spinbox();
    QDoubleSpinBox* get_scale_factor_spinbox();
    QDoubleSpinBox* get_line_width_spinbox();
    QDoubleSpinBox* get_width_increment_spinbox();
    QPushButton* get_add_rule_btn();
    QPushButton* get_generate_btn();
    QFormLayout* get_rule_form_layout();
    QGraphicsView* get_graphics_view();

    QString get_axiom_string() override;
    QColor get_fill_color() override;
    qreal get_initial_angle() override;
    qreal get_turn_angle() override;
    qreal get_turn_increment() override;
    qint32 get_iterations() override;
    qreal get_line_length() override;
    qreal get_scale_factor() override;
    qreal get_line_width() override;
    qreal get_width_increment() override;
    QHash<QChar, QString> get_sub_entries() override;

    void add_rule_entry(const QChar& c = QChar(), const QString& s = QString()) override;
    Turtle* get_turtle() override;
    void fill_form(const FormDataBundle &form_data) override;
public slots:
    void center_graphics_output() override;
private:
    Ui::MainWindow *ui;
    FormPresenter form_presenter;
    Turtle turtle;
};
#endif // MAINWINDOW_H
