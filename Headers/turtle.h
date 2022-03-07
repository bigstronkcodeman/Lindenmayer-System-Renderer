#pragma once
#ifndef TURTLE_H
#define TURTLE_H

#include <math.h>
#include <QHash>
#include <QPoint>
#include <QStack>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>


struct TurtleState {
    QPointF position;
    qreal bearing;
    qreal bearing_inc;
    qreal turn_inc;
    qreal line_width;
    qreal line_width_inc;
    qreal line_length;
    qreal line_scale_factor;
    bool turns_reversed;

    TurtleState();
};

class Turtle : public QObject
{
    Q_OBJECT
public:
    Turtle();
    Turtle(QGraphicsView* v);

    void reset();

    void set_graphics_view(QGraphicsView* v);
    void set_state(const TurtleState& state);
    void set_fill_color(const QColor& color);

    void execute_instruction(const QChar& instruction);
    void execute_instructions(const QString& instructions);

    void move_forward_draw();
    void move_forward_no_draw();
    void turn_left();
    void turn_right();
    void reverse();
    void push_memory();
    void pop_memory();
    void increment_line_width();
    void decrement_line_width();
    void dot();
    void open_polygon();
    void close_polygon();
    void scale_up_line_length();
    void scale_down_line_length();
    void swap_turn_instruction_meaning();
    void increment_turning_angle();
    void decrement_turning_angle();

private:
    static const QColor DEFAULT_FILL_COLOR;
    QGraphicsScene* scene;
    QGraphicsView* view;
    TurtleState current_state;
    QStack<TurtleState> memories;
    QColor polygon_fill_color;
    QPen pen;
};

#endif // TURTLE_H
