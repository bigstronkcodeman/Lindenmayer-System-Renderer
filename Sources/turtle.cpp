#include "turtle.h"

const QColor Turtle::DEFAULT_FILL_COLOR = Qt::blue;

TurtleState::TurtleState()
    : position(0,0)
    , bearing(90)
    , bearing_inc(90)
    , turn_inc(0)
    , line_width(1)
    , line_width_inc(0.05)
    , line_length(1)
    , line_scale_factor(1.2)
    , turns_reversed(false) { }

Turtle::Turtle()
    : scene()
    , view()
    , current_state()
    , memories()
    , polygon_fill_color(Turtle::DEFAULT_FILL_COLOR)
    , pen(Qt::white, this->current_state.line_width, Qt::SolidLine) {
    this->scene = new QGraphicsScene();
    this->scene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

Turtle::Turtle(QGraphicsView* v)
    : scene()
    , view()
    , current_state()
    , memories()
    , polygon_fill_color(Turtle::DEFAULT_FILL_COLOR)
    , pen(Qt::white, this->current_state.line_width, Qt::SolidLine) {
    this->scene = new QGraphicsScene();
    this->scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    this->set_graphics_view(v);
}

void Turtle::reset() {
    this->scene->clear();
    this->current_state = TurtleState();
    this->memories.clear();
    this->polygon_fill_color = Turtle::DEFAULT_FILL_COLOR;
}

void Turtle::set_graphics_view(QGraphicsView *v) {
    this->view = v;
    this->view->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    this->view->setScene(this->scene);
}

void Turtle::set_state(const TurtleState& state) {
    this->current_state = state;
    this->pen.setWidth(state.line_width);
}

void Turtle::set_fill_color(const QColor& color) {
    this->polygon_fill_color = color;
}

void Turtle::execute_instruction(const QChar& instruction) {
    switch (instruction.toLatin1()) {
    case 'F':
        move_forward_draw();
        break;
    case 'f':
        move_forward_no_draw();
        break;
    case '+':
        this->current_state.turns_reversed ? turn_right() : turn_left();
        break;
    case '-':
        this->current_state.turns_reversed ? turn_left() : turn_right();
        break;
    case '|':
        reverse();
        break;
    case '[':
        push_memory();
        break;
    case ']':
        pop_memory();
        break;
    case '#':
        increment_line_width();
        break;
    case '!':
        decrement_line_width();
        break;
    case '@':
        dot();
        break;
    case '{':
        open_polygon();
        break;
    case '}':
        close_polygon();
        break;
    case '>':
        scale_up_line_length();
        break;
    case '<':
        scale_down_line_length();
        break;
    case '&':
        swap_turn_instruction_meaning();
        break;
    case '(':
        decrement_turning_angle();
        break;
    case ')':
        increment_turning_angle();
        break;
    default:
        break;
    }
}

void Turtle::execute_instructions(const QString& instructions) {
    this->scene->clear();
    for (const QChar& c : instructions) {
        execute_instruction(c);
    }
}

void Turtle::move_forward_draw() {
    QPointF p1(this->current_state.position);
    move_forward_no_draw();

    this->scene->addLine(QLineF(p1, this->current_state.position), this->pen);
    this->scene->update();
}

void Turtle::move_forward_no_draw() {
    QPointF p1(this->current_state.position);
    QPointF p2(p1.x() + this->current_state.line_length, p1.y());

    QLineF line(p1, p2);
    line.setAngle(this->current_state.bearing);
    this->current_state.position = line.p2();
}

void Turtle::turn_left() {
    this->current_state.bearing = fmod(this->current_state.bearing + this->current_state.bearing_inc, 360.0);
}

void Turtle::turn_right() {
    this->current_state.bearing = fmod(this->current_state.bearing - this->current_state.bearing_inc, 360.0);
}

void Turtle::reverse() {
    this->current_state.bearing = fmod(this->current_state.bearing + 180.0, 360.0);
}

void Turtle::push_memory() {
    this->memories.push(this->current_state);
}

void Turtle::pop_memory() {
    if (!this->memories.isEmpty()) {
        this->current_state = this->memories.pop();
    }
}

void Turtle::increment_line_width() {
    this->current_state.line_width += this->current_state.line_width_inc;
}

void Turtle::decrement_line_width() {
    this->current_state.line_width -= this->current_state.line_width_inc;
}

void Turtle::dot() {
    qreal radius = this->current_state.line_width;
    this->scene->addEllipse(this->current_state.position.x() - radius
                          , this->current_state.position.y() - radius
                          , 2.0 * radius
                          , 2.0 * radius
                          , this->pen
                          , QBrush(Qt::SolidPattern));
    this->scene->update();
}

void Turtle::open_polygon() { }

void Turtle::close_polygon() { }

void Turtle::scale_up_line_length() {
    this->current_state.line_length *= this->current_state.line_scale_factor;
}

void Turtle::scale_down_line_length() {
    this->current_state.line_length /= this->current_state.line_scale_factor;
}

void Turtle::swap_turn_instruction_meaning() {
    this->current_state.turns_reversed = !this->current_state.turns_reversed;
}

void Turtle::increment_turning_angle() {
    this->current_state.bearing_inc = fmod(this->current_state.bearing_inc + this->current_state.turn_inc, 360.0);
}

void Turtle::decrement_turning_angle() {
    this->current_state.bearing_inc = fmod(this->current_state.bearing_inc - this->current_state.turn_inc, 360.0);
}
