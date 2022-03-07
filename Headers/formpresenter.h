#ifndef FORMPRESENTER_H
#define FORMPRESENTER_H

#include <QObject>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QPushButton>
#include <QMainWindow>
#include <QGraphicsScene>
#include "lsystem.h"
#include "turtle.h"

#include <QDebug>

struct FormDataBundle {
    QString axiom;
    QColor fill_color;
    qreal initial_angle;
    qreal turn_angle;
    qreal turn_increment;
    qint32 iterations;
    qreal line_length;
    qreal scale_factor;
    qreal line_width;
    qreal width_increment;
    QHash<QChar, QString> rules;
};

class FormPresenter : public QObject
{
    Q_OBJECT
public:
    class View {
    public:
        virtual ~View() {}
        virtual void add_rule_entry(const QChar& c = QChar(), const QString& s = QString()) = 0;
        virtual QString get_axiom_string() = 0;
        virtual QColor get_fill_color() = 0;
        virtual qreal get_initial_angle() = 0;
        virtual qreal get_turn_angle() = 0;
        virtual qreal get_turn_increment() = 0;
        virtual qint32 get_iterations() = 0;
        virtual qreal get_line_length() = 0;
        virtual qreal get_scale_factor() = 0;
        virtual qreal get_line_width() = 0;
        virtual qreal get_width_increment() = 0;
        virtual QHash<QChar, QString> get_sub_entries() = 0;
        virtual Turtle* get_turtle() = 0;
        virtual void fill_form(const FormDataBundle& form_data) = 0;
        virtual void center_graphics_output() = 0;
    };

    FormPresenter(View* view);
    ~FormPresenter();
public slots:
    void add_rule_button_clicked();
    void generate_button_clicked();
    void leaf_preset();
    void thistle_preset();
    void coral_preset();
    void bush_preset();
    void spruce_preset();
    void binary_tree_preset();
    void foxtail_preset();
    void sprig_preset();
    void algae_preset();
    void birch_preset();
    void rings_preset();
    void cross_preset();
    void koch_snowflake_preset();
    void sierpinski_arrowhead_preset();
    void hilbert_curve_preset();
    void board_preset();
    void crystal_preset();
    void quadratic_snowflake_preset();
    void quadratic_koch_island_preset();
    void pentaplexity_preset();
    void levy_curve_preset();
    void krishna_anklet_preset();
private:
    LSystem* lsys;
    View* view;
};

#endif // FORMPRESENTER_H
